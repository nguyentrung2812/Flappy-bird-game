#include "game/loop.h"
#include "game/entities.h"
#include "game/ui.h"
#include "game/levels.h"
#include "game/collision.h"

#include "gfx/render.h"
#include "drivers/timebase.h"
#include "periph/led.h"
#include "periph/buzzer.h"
#include "periph/input.h"

#include <stm32f401re_tim.h>
#include <stm32f401re_rcc.h>
#include <misc.h>

GameState g_game = {
  .current_level = 1,
  .score = 0,
  .last_score = 0,
  .pipe_center = 40,
  .pipe_x1 = 0,
  .bird_y = 30.0f,
  .bird_v = 0.0f,
  .render_needed = 0,
  .prev_pipe_x = PIPE_START_X,
  .scored_this_pipe = 0,
};

// cấu hình TIM2 20ms (tick game)
static void tim2_config_20ms(void){
  TIM_TimeBaseInitTypeDef tb;
  NVIC_InitTypeDef nvic;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  tb.TIM_Prescaler     = 8399;   // 84MHz -> 10kHz
  tb.TIM_Period        = 199;    // 10kHz -> 50Hz (20ms)
  tb.TIM_ClockDivision = TIM_CKD_DIV1;
  tb.TIM_CounterMode   = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2, &tb);

  nvic.NVIC_IRQChannel = TIM2_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 0;
  nvic.NVIC_IRQChannelSubPriority = 1;
  nvic.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvic);

  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM2, ENABLE);
}

// nháy LED khi game over
static void game_over_blink(void){
  for(int i=0;i<5;i++){
    led_on();  timebase_delay_ms(120);
    led_off(); timebase_delay_ms(120);
  }
}

// xử lý game over: lưu last_score
static void game_over_handler(void){
  TIM_Cmd(TIM2, DISABLE);
  g_game.last_score = g_game.score;
  g_game.score = 0;
  g_game.bird_y = 30;
  g_game.bird_v = 0;
}

// reset ván mới + vẽ lại (không vẽ score trong game)
static void reset_run_and_redraw(void){
  TIM_Cmd(TIM2, DISABLE);

  g_game.bird_y = 30;
  g_game.bird_v = 0;

  g_game.pipe_x1 = 0;
  g_game.score = 0;

  g_game.prev_pipe_x = PIPE_START_X;
  g_game.scored_this_pipe = 0;

  render_clear();
  render_border();

  levels_draw_pipe(g_game.current_level, &g_game.pipe_center);
  render_bird_draw((int16_t)g_game.bird_y);

  g_game.render_needed = 0;

  TIM_SetCounter(TIM2, 0);
  TIM_Cmd(TIM2, ENABLE);
}

void game_init_state(void){
  tim2_config_20ms();
}

// ===== ISR TIM2: jump + physics + buzzer tick =====
void TIM2_IRQHandler(void){
  if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){

    // Jump bằng SW3
    if(sw3_click() || sw3_held(600)){
      buzzer_beep_ticks(3); // ~60ms
      if(g_game.current_level == 1) g_game.bird_v = (JUMP_FORCE + 0.7f);
      else                         g_game.bird_v = JUMP_FORCE;
    }

    // Physics
    if(g_game.current_level == 1) g_game.bird_v += (GRAVITY - 0.05f);
    else                          g_game.bird_v += GRAVITY;

    g_game.bird_y += g_game.bird_v;

    if(g_game.bird_y < 1){
      g_game.bird_y = 1;
      g_game.bird_v = 0;
    }
    if(g_game.bird_y > 79 - BIRD_H){
      g_game.bird_y = 79 - BIRD_H;
    }

    buzzer_tick_20ms();

    g_game.render_needed = 1;
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  }
}

void game_run_forever(void){
  int16_t old_bird_y = (int16_t)g_game.bird_y;
  int16_t current_pipe_x = PIPE_START_X;

  while(1){
    ui_splash_and_choose_level();
    reset_run_and_redraw();

    while(1){
      if(g_game.render_needed){
        g_game.render_needed = 0;

        // Update pipe
        current_pipe_x = levels_update_pipe(g_game.current_level, &g_game.pipe_center);

        // TÍNH ĐIỂM NGẦM (không vẽ lên màn)
        if(current_pipe_x > g_game.prev_pipe_x){
          g_game.scored_this_pipe = 0; // respawn
        }
        g_game.prev_pipe_x = current_pipe_x;

        int16_t w = (g_game.current_level==1) ? PIPE_W_L1 : PIPE_W_L2;
        if(!g_game.scored_this_pipe && (current_pipe_x + w) < BIRD_X){
          g_game.scored_this_pipe = 1;
          g_game.score++;
        }

        // Update bird
        int16_t curr = (int16_t)g_game.bird_y;
        render_bird_update(curr, old_bird_y);
        old_bird_y = curr;

        // Collision
        if(collision_check(g_game.bird_y, current_pipe_x, g_game.pipe_center, g_game.current_level)){
          game_over_blink();
          game_over_handler();
          break;
        }
      }
    }
  }
}
