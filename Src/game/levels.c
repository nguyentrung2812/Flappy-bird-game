#include "game/levels.h"
#include "game/entities.h"
#include "gfx/lcd_init.h"
#include "gfx/render.h"
#include <stdlib.h>

// Vẽ pipe lần đầu (box)
static void draw_pipe1(uint8_t* center){
  uint8_t rand_pipe = (rand() % 41) + 20;
  *center = rand_pipe;

  RENDER_SetRGB(0, 255,255,255);
  if(*center > 15) ucg_DrawBox(&g_ucg, PIPE_START_X, 1, 8, *center - 15);
  if(80 - *center - 15 > 0) ucg_DrawBox(&g_ucg, PIPE_START_X, *center + 15, 8, 80 - *center - 15);
}
static void draw_pipe2(uint8_t* center){
  uint8_t rand_pipe = (rand() % 41) + 20;
  *center = rand_pipe;

  RENDER_SetRGB(0, 255,255,255);
  if(*center > 15) ucg_DrawBox(&g_ucg, PIPE_START_X, 1, 12, *center - 15);
  if(80 - *center - 15 > 0) ucg_DrawBox(&g_ucg, PIPE_START_X, *center + 15, 12, 80 - *center - 15);
}

void levels_draw_pipe(uint8_t level, uint8_t* center){
  if(level == 1) draw_pipe1(center);
  else draw_pipe2(center);
}

int16_t levels_update_pipe(uint8_t level, uint8_t* center){
  int16_t w = (level==1) ? PIPE_W_L1 : PIPE_W_L2;

  int16_t draw_x  = PIPE_START_X - (int16_t)g_game.pipe_x1;
  int16_t erase_x = PIPE_START_X + w - (int16_t)g_game.pipe_x1;

  if(draw_x >= 0){
    RENDER_SetRGB(0, 255,255,255);
    ucg_DrawVLine(&g_ucg, draw_x, 3, *center - 15);
    ucg_DrawVLine(&g_ucg, draw_x, *center + 17, 80 - *center - 16);
  }

  if(erase_x < SCREEN_W && erase_x >= 0){
    RENDER_SetRGB(0, 0,0,0);
    ucg_DrawVLine(&g_ucg, erase_x, 3, *center - 15);
    ucg_DrawVLine(&g_ucg, erase_x, *center + 17, 80 - *center - 16);
  }

  g_game.pipe_x1++;

  if(erase_x <= 0){
    g_game.pipe_x1 = 0;
    levels_draw_pipe(level, center);
  }

  return draw_x;
}
