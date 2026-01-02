#pragma once
#include <stdint.h>
#include <Ucglib.h>
#include "board_config.h"
#include "gfx/lcd_init.h"

// Macro set màu theo LCD_IS_BGR
#if LCD_IS_BGR
  #define RENDER_SetRGB(idx, r, g, b)  ucg_SetColor(&g_ucg, (idx), (b), (g), (r))
#else
  #define RENDER_SetRGB(idx, r, g, b)  ucg_SetColor(&g_ucg, (idx), (r), (g), (b))
#endif

// Hàm vẽ nền/viền
void render_clear(void);
void render_border(void);

// Vẽ menu strings helper
void render_menu_text(const char* s, int x, int y);

// Vẽ chim sprite
void render_bird_draw(int16_t y);
void render_bird_erase(int16_t y);
void render_bird_update(int16_t curr_y, int16_t old_y);
