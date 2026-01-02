#include "game/ui.h"
#include "game/entities.h"
#include "gfx/render.h"
#include "drivers/timebase.h"
#include "periph/input.h"

#include <stdio.h>

void ui_splash_and_choose_level(void){
  const int MENU_X = 6;

  render_clear();
  render_border();

  render_menu_text("FLAPPY BIRD", MENU_X, 36);
  render_menu_text("> LEVEL: 1",  11,     48);
  render_menu_text("START",       20,     60);

  char ls[28];
  snprintf(ls, sizeof(ls), "LAST SCORE: %u", (unsigned)g_game.last_score);
  render_menu_text(ls, MENU_X, 72);

  char lv[8];
  snprintf(lv, sizeof(lv), "%u", (unsigned)g_game.current_level);
  render_menu_text(lv, 59, 48);

  uint8_t a = 1; // 1=LEVEL, 2=START

  while(1){
    switch(a){
      case 1:
        while(1){
          timebase_process();

          if(sw3_click() || sw3_held(600)){
            g_game.current_level = (g_game.current_level==1) ? 2 : 1;

            snprintf(lv, sizeof(lv), "%u", (unsigned)g_game.current_level);
            RENDER_SetRGB(0, 0,0,0);
            ucg_DrawBox(&g_ucg, 59, 40, 6, 8);
            RENDER_SetRGB(0, 255,255,255);
            ucg_DrawString(&g_ucg, 59, 48, 0, lv);

            timebase_delay_ms(100);
          }

          if(sw5_click() || sw5_held(600)){
            timebase_delay_ms(100);

            // xóa '>' ở LEVEL
            RENDER_SetRGB(0, 0,0,0);
            ucg_DrawBox(&g_ucg, 11, 40, 6, 8);
            // vẽ '>' ở START
            RENDER_SetRGB(0, 255,255,255);
            ucg_DrawString(&g_ucg, 11, 60, 0, ">");

            timebase_delay_ms(100);
            a = 2;
            break;
          }
        }
        break;

      case 2:
        while(1){
          if(sw3_click() || sw3_held(600)){
            timebase_delay_ms(100);
            return; // start game
          }
          if(sw1_click() || sw1_held(600)){
            timebase_delay_ms(100);

            // xóa '>' ở START
            RENDER_SetRGB(0, 0,0,0);
            ucg_DrawBox(&g_ucg, 11, 52, 6, 8);
            // vẽ '>' ở LEVEL
            RENDER_SetRGB(0, 255,255,255);
            ucg_DrawString(&g_ucg, 11, 48, 0, ">");

            timebase_delay_ms(100);
            a = 1;
            break;
          }
        }
        break;
    }
  }
}
