/*
 * loop.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "game/loop.h"

#include <stdlib.h>

#include "board_config.h"
#include "drivers/timebase.h"
#include "periph/led.h"
#include "periph/input.h"
#include "gfx/render.h"
#include "game/entities.h"
#include "game/levels.h"
#include "game/collision.h"

static void game_over_blink(uint8_t times){
  LED_Blink(times, 120, 120);
}

void run_game(void){
  level_cfg_t L = LEVELS[current_level-1]; /* current_level is 1 or 2 */
  clear_playfield();

  uint16_t score = 0;
  bird_t bird = { .x = PLAY_X0 + 18, .y = PLAY_Y0 + PLAY_H/2, .vy = 0, .r = 3 };
  pipe_t pipe = { .x = PLAY_X0 + PLAY_W - 2, .gap_y = PLAY_Y0 + 18, .scored = 0 };

  uint32_t last_step = 0;
  uint8_t paused = 0;

  srand(millis());

  while(1){
    uint32_t now = millis();
    if(now - last_step < L.step_ms){ processTimerScheduler(); continue; }
    last_step = now;

    /* Controls */
    if(SW1_Click() || SW5_Click()){ bird.vy = L.flap_vel; }
    if(SW2_Click()){
      paused ^= 1;
      if(paused){
        ucg_SetFont(&ucg, ucg_font_helvR10_tf);
        ucg_DrawString(&ucg, 44, 34, 0, "PAUSED");
      }
    }
    if(paused) continue;

    /* Physics */
    bird.vy += L.gravity;
    bird.y  += bird.vy;

    /* Pipe */
    pipe.x -= L.pipe_speed;
    if(pipe.x < PLAY_X0 - 8){
      pipe.x = PLAY_X0 + PLAY_W - 2;
      int16_t miny = PLAY_Y0 + 10;
      int16_t maxy = PLAY_Y0 + PLAY_H - 10;
      pipe.gap_y = (rand() % (maxy - miny)) + miny;
      pipe.scored = 0;
    }
    if(!pipe.scored && pipe.x + 6 < bird.x - bird.r){ score++; pipe.scored = 1; }

    /* Render */
    clear_playfield();
    draw_frame(score);
    draw_pipe(&pipe, L.pipe_gap);
    draw_bird(&bird);

    /* Collide */
    if(collide(&bird, &pipe, L.pipe_gap)){
      ucg_SetFont(&ucg, ucg_font_helvR10_tf);
      ucg_DrawString(&ucg, 26, 34, 0, "GAME OVER");
      game_over_blink(6);
      delay_ms(800);
      return;
    }
  }
}
