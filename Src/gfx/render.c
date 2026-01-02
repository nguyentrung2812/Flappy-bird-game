#include "gfx/render.h"
#include "game/entities.h"

static const uint16_t bird_mask[BIRD_H] = {
  0b0011100000,
  0b0111110000,
  0b1111111000,
  0b1110111100,
  0b1111111110,
  0b0111111100,
  0b0011111000,
};

void render_clear(void){
  ucg_ClearScreen(&g_ucg);
}

void render_border(void){
  RENDER_SetRGB(0, 255,255,255);
  ucg_DrawHLine(&g_ucg, 0, 0, 128);
  ucg_DrawHLine(&g_ucg, 0, 79, 128);
}

void render_menu_text(const char* s, int x, int y){
  ucg_SetFont(&g_ucg, ucg_font_helvR08_tf);
  RENDER_SetRGB(0, 255,255,255);
  ucg_DrawString(&g_ucg, x, y, 0, s);
}

void render_bird_erase(int16_t y){
  RENDER_SetRGB(0, 0,0,0);
  ucg_DrawBox(&g_ucg, BIRD_X-1, y-1, BIRD_W+2, BIRD_H+2);
}

void render_bird_draw(int16_t y){
  // Chim màu vàng (qua macro sẽ ra đúng màu theo LCD)
  RENDER_SetRGB(0, 255,255,0);

  for(int r=0; r<BIRD_H; r++){
    uint16_t row = bird_mask[r];
    for(int c=0; c<BIRD_W; c++){
      if(row & (1u << (BIRD_W - 1 - c))){
        ucg_DrawPixel(&g_ucg, BIRD_X + c, y + r);
      }
    }
  }

  // mắt đen
  RENDER_SetRGB(0, 0,0,0);
  ucg_DrawPixel(&g_ucg, BIRD_X + 6, y + 3);

  // mỏ trắng
  RENDER_SetRGB(0, 255,255,255);
  ucg_DrawPixel(&g_ucg, BIRD_X + 9, y + 3);
}

void render_bird_update(int16_t curr_y, int16_t old_y){
  if(curr_y == old_y) return;
  render_bird_erase(old_y);
  render_bird_draw(curr_y);
}

