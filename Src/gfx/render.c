#include "gfx/render.h"
#include "gfx/lcd_init.h"
#include "board_config.h"

static const uint16_t bird_mask[BIRD_H] = {
  0b000111100000,
  0b001111110000,
  0b011111111000,
  0b111101111100,
  0b111111111110,
  0b011111111100,
  0b001111111000,
  0b000111110000
};

void Render_DrawFrameLines(void)
{
  UCG_SetRGB(0, 255, 255, 255);
  ucg_DrawHLine(&ucg, 0, 0, 128);
  ucg_DrawHLine(&ucg, 0, 79, 128);
}

void Bird_EraseAt(int16_t x, int16_t y)
{
  UCG_SetRGB(0, 0, 0, 0);
  ucg_DrawBox(&ucg, x - 1, y - 1, BIRD_W + 2, BIRD_H + 2);
}

void Bird_DrawAt(int16_t x, int16_t y)
{
  UCG_SetRGB(0, 255, 255, 0);
  for (int r = 0; r < BIRD_H; r++)
  {
    uint16_t row = bird_mask[r];
    for (int c = 0; c < BIRD_W; c++)
    {
      if (row & (1u << (BIRD_W - 1 - c)))
        ucg_DrawPixel(&ucg, x + c, y + r);
    }
  }

  UCG_SetRGB(0, 255, 255, 255);
  ucg_DrawPixel(&ucg, x + 2, y + 1);
  ucg_DrawPixel(&ucg, x + 3, y + 0);
  ucg_DrawPixel(&ucg, x + 9, y + 2);

  UCG_SetRGB(0, 0, 0, 0);
  ucg_DrawPixel(&ucg, x + 7, y + 3);
  ucg_DrawPixel(&ucg, x + 8, y + 3);

  UCG_SetRGB(0, 255, 255, 255);
  ucg_DrawPixel(&ucg, x + 11, y + 3);
  ucg_DrawPixel(&ucg, x + 11, y + 4);

  UCG_SetRGB(0, 0, 0, 0);
  ucg_DrawPixel(&ucg, x + 4, y + 4);
  ucg_DrawPixel(&ucg, x + 5, y + 5);
}

void Bird_UpdateSprite(int16_t current_y, int16_t old_y)
{
  if (current_y == old_y) return;
  Bird_EraseAt(BIRD_X, old_y);
  Bird_DrawAt(BIRD_X, current_y);
}
