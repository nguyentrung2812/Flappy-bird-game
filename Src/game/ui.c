/*
 * ui.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "game/ui.h"
#include "board_config.h"
#include "gfx/render.h"
#include "periph/buzzer.h"
#include "periph/input.h"

void splash_and_choose_level(void){
  ucg_ClearScreen(&ucg);
  ucg_SetFont(&ucg, ucg_font_helvR08_tf);
  ucg_SetColor(&ucg,0,255,255,255);
  ucg_DrawString(&ucg, 20, 36, 0, "FLAPPY BIRD");
  ucg_DrawString(&ucg, 11, 48, 0, "> LEVEL: 1");
  ucg_DrawString(&ucg, 20, 60, 0, "START");

  char lv[20];
  uint8_t a = 1;
  while(a == 1 || a == 2) {
    switch(a) {
    case 1:
      while(1) {
        processTimerScheduler();
        if(SW3_Click() || SW3_Held(600)){
          Buzzer_Beep(100);
          extern uint8_t current_level;
          if(current_level == 1) current_level = 2;
          else current_level = 1;
          snprintf(lv, sizeof(lv), "%u", (unsigned)current_level);
          ucg_SetColor(&ucg,0,0,0,0); ucg_DrawBox(&ucg, 59, 40, 6, 8);
          ucg_SetColor(&ucg,0,255,255,255); ucg_DrawString(&ucg, 59, 48, 0, lv);
        }
        if(SW5_Click()){
          Buzzer_Beep(100);
          ucg_SetColor(&ucg,0,0,0,0);
          ucg_DrawBox(&ucg, 11, 40, 6, 8);
          ucg_SetColor(&ucg,0,255,255,255);
          ucg_DrawString(&ucg, 11, 60, 0, ">");
          a = 2;
          break;
        }
      }
      /* fallthrough */
    case 2:
      while(1) {
        if(SW3_Click() || SW3_Held(600)) {
          Buzzer_Beep(100);
          return;
        }
        if(SW1_Click()) {
          Buzzer_Beep(100);
          ucg_SetColor(&ucg,0,0,0,0);
          ucg_DrawBox(&ucg, 11, 52, 6, 8);
          ucg_SetColor(&ucg,0,255,255,255);
          ucg_DrawString(&ucg, 11, 48, 0, ">");
          a = 1;
          break;
        }
      }
      break;
    }
  }
}
