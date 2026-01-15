#include "game/loop.h"

#include "drivers/timebase.h"
#include "gfx/lcd_init.h"
#include "gfx/render.h"
#include "game/ui.h"
#include "game/levels.h"
#include "game/entities.h"
#include "game/collision.h"
#include "periph/input.h"
#include "periph/led.h"
#include "periph/buzzer.h"

#include <stm32f401re_tim.h>

/* render flag set in ISR */
static volatile uint8_t render_needed = 0;
uint8_t g_current_level = 1;
static void game_over_blink(void)
{
  for (int i = 0; i < 5; i++)
  {
    LED_On();
    delay_ms(120);
    LED_Off();
    delay_ms(120);
  }
}

static void reset_run_and_redraw(uint8_t level, uint8_t* pipe_center_val)
{
  TIM_Cmd(TIM2, DISABLE);

  Bird_Reset();

  ucg_ClearScreen(&ucg);
  Render_DrawFrameLines();

  Levels_Reset(level, pipe_center_val);

  Bird_DrawAt(BIRD_X, Bird_GetY_Int());

  render_needed = 0;

  TIM_SetCounter(TIM2, 0);
  TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
  {
    /* Jump */
    if (SW3_Click() || SW3_Held(600))
    {
      Buzzer_FireJump();
      Bird_SetJump(g_current_level);
    }

    /* Physics */
    Bird_OnTick(g_current_level);

    /* Buzzer timeout */
    Buzzer_OnTick();

    render_needed = 1;
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  }
}

void __Entities_SetJumpVelocity(uint8_t level);
void __Entities_SetJumpVelocity(uint8_t level)
{

  extern void __Entities_Internal_SetV(float v);
  if (level == 1) __Entities_Internal_SetV(JUMP_FORCE + 0.7f);
  else            __Entities_Internal_SetV(JUMP_FORCE);
}

void __Entities_Internal_SetV(float v);
float __Entities_Internal_GetV(void);


void Game_RunForever(void)
{
  uint16_t last_score = 0;

  while (1)
  {
    uint8_t level = UI_Splash_ChooseLevel();
    g_current_level = level;

    uint8_t pipe_center_val = 0;
    reset_run_and_redraw(level, &pipe_center_val);

    int16_t old_bird_y       = Bird_GetY_Int();
    int16_t current_pipe_x   = PIPE_START_X;
    int16_t prev_pipe_x      = PIPE_START_X;
    uint8_t scored_this_pipe = 0;
    uint16_t score           = 0;

    while (1)
    {
      if (!render_needed) continue;
      render_needed = 0;

      current_pipe_x = Levels_Update(level, &pipe_center_val);

      if (current_pipe_x > prev_pipe_x) scored_this_pipe = 0;
      prev_pipe_x = current_pipe_x;

      int16_t pipe_w = (level == 1) ? PIPE_W_L1 : PIPE_W_L2;
      if (!scored_this_pipe && (current_pipe_x + pipe_w) < BIRD_X)
      {
        scored_this_pipe = 1;
        score++;
      }

      int16_t curr_bird_y = Bird_GetY_Int();
      Bird_UpdateSprite(curr_bird_y, old_bird_y);
      old_bird_y = curr_bird_y;

      if (check_collision(Bird_GetY(), current_pipe_x, pipe_center_val, level))
      {
        game_over_blink();

        TIM_Cmd(TIM2, DISABLE);
        last_score = score;
        UI_SetLastScore(last_score);

        break;
      }
    }
  }
}
