#include "game/ui.h"

#include "gfx/lcd_init.h"
#include "gfx/render.h"
#include "drivers/timebase.h"
#include "periph/input.h"
#include <timer.h>   // processTimerScheduler()

#include <stdio.h>

static uint16_t last_score = 0;
static uint8_t  current_level = 1;

void UI_SetLastScore(uint16_t s) { last_score = s; }

uint8_t UI_Splash_ChooseLevel(void)
{
#define MENU_X  6

  ucg_ClearScreen(&ucg);

  UCG_SetRGB(0, 255, 255, 255);
  ucg_DrawHLine(&ucg, 0, 0, 128);
  ucg_DrawHLine(&ucg, 0, 79, 128);

  /* mini pipe + bird */
  UCG_SetRGB(0, 255, 255, 255);

  int16_t px      = 102;
  int16_t topY    = 6;
  int16_t bottomY = 74;
  int16_t gap_c   = 34;
  int16_t gap     = 14;

  int16_t h_top = (gap_c - gap) - topY;
  if (h_top > 0) ucg_DrawBox(&ucg, px, topY, 10, h_top);

  int16_t y_bot = gap_c + gap;
  int16_t h_bot = bottomY - y_bot;
  if (h_bot > 0) ucg_DrawBox(&ucg, px, y_bot, 10, h_bot);

  Bird_DrawAt(16, 16);

  ucg_SetFont(&ucg, ucg_font_helvR08_tf);

  UCG_SetRGB(0, 255, 255, 255);
  ucg_DrawString(&ucg, MENU_X, 36, 0, "FLAPPY BIRD");
  ucg_DrawString(&ucg, 11, 48, 0, "> LEVEL: 1");
  ucg_DrawString(&ucg, 20, 60, 0, "START");

  char ls[24];
  snprintf(ls, sizeof(ls), "LAST SCORE: %u", (unsigned)last_score);
  ucg_DrawString(&ucg, MENU_X, 72, 0, ls);

  char lv[8];
  snprintf(lv, sizeof(lv), "%u", (unsigned)current_level);
  ucg_DrawString(&ucg, 59, 48, 0, lv);

  delay_ms(30);                 // cho LCD settle (nhẹ)
  processTimerScheduler();      // bơm scheduler 1 nhịp

  uint8_t a = 1; // 1: LEVEL, 2: START

  while (1)
  {
    processTimerScheduler();    //  bơm scheduler liên tục trong menu

    switch (a)
    {
      case 1:
        while (1)
        {
          processTimerScheduler();

          if (SW3_Click() || SW3_Held(600))
          {
            current_level = (current_level == 1) ? 2 : 1;
            delay_ms(100);

            snprintf(lv, sizeof(lv), "%u", (unsigned)current_level);
            UCG_SetRGB(0, 0, 0, 0);
            ucg_DrawBox(&ucg, 59, 40, 6, 8);
            UCG_SetRGB(0, 255, 255, 255);
            ucg_DrawString(&ucg, 59, 48, 0, lv);
          }

          if (SW5_Click() || SW5_Held(600))
          {
            delay_ms(100);

            UCG_SetRGB(0, 0, 0, 0);
            ucg_DrawBox(&ucg, 11, 40, 6, 8);

            UCG_SetRGB(0, 255, 255, 255);
            ucg_DrawString(&ucg, 11, 60, 0, ">");

            delay_ms(100);
            a = 2;
            break;
          }
        }
        break;

      case 2:
        while (1)
        {
          processTimerScheduler();

          if (SW3_Click() || SW3_Held(600))
          {
            delay_ms(100);
            return current_level;
          }

          if (SW1_Click() || SW1_Held(600))
          {
            delay_ms(100);

            UCG_SetRGB(0, 0, 0, 0);
            ucg_DrawBox(&ucg, 11, 52, 6, 8);

            UCG_SetRGB(0, 255, 255, 255);
            ucg_DrawString(&ucg, 11, 48, 0, ">");

            delay_ms(100);
            a = 1;
            break;
          }
        }
        break;

      default:
        a = 1;
        break;
    }
  }
}
