#include "game/levels.h"
#include "gfx/lcd_init.h"
#include "board_config.h"

#include <stdlib.h>

static volatile uint16_t pipe_x1 = 0;

static void draw_pipe1(uint8_t *center)
{
  uint8_t rand_pipe = (rand() % 41) + 20;
  *center = rand_pipe;

  UCG_SetRGB(0, 255, 255, 255);
  if (*center > PIPE_GAP_HALF)
    ucg_DrawBox(&ucg, PIPE_START_X, 1, PIPE_W_L1, *center - PIPE_GAP_HALF);

  if ((SCREEN_H - *center - PIPE_GAP_HALF) > 0)
    ucg_DrawBox(&ucg, PIPE_START_X, *center + PIPE_GAP_HALF, PIPE_W_L1,
                SCREEN_H - *center - PIPE_GAP_HALF);
}

static int16_t update_pipe1(uint8_t *center)
{
  int16_t draw_x  = PIPE_START_X - pipe_x1;
  int16_t erase_x = PIPE_START_X + PIPE_W_L1 - pipe_x1;

  if (draw_x >= 0)
  {
    UCG_SetRGB(0, 255, 255, 255);
    ucg_DrawVLine(&ucg, draw_x, 3, *center - PIPE_GAP_HALF);
    ucg_DrawVLine(&ucg, draw_x, *center + PIPE_GAP_HALF + 2,
                  SCREEN_H - *center - PIPE_GAP_HALF + 1);
  }

  if (erase_x < SCREEN_W && erase_x >= 0)
  {
    UCG_SetRGB(0, 0, 0, 0);
    ucg_DrawVLine(&ucg, erase_x, 3, *center - PIPE_GAP_HALF);
    ucg_DrawVLine(&ucg, erase_x, *center + PIPE_GAP_HALF + 2,
                  SCREEN_H - *center - PIPE_GAP_HALF + 1);
  }

  pipe_x1++;

  if (erase_x <= 0)
  {
    pipe_x1 = 0;
    draw_pipe1(center);
  }

  return draw_x;
}

static void draw_pipe2(uint8_t *center)
{
  uint8_t rand_pipe = (rand() % 41) + 20;
  *center = rand_pipe;

  UCG_SetRGB(0, 255, 255, 255);

  if (*center > PIPE_GAP_HALF)
    ucg_DrawBox(&ucg, PIPE_START_X, 1, PIPE_W_L1, *center - PIPE_GAP_HALF);

  if ((SCREEN_H - *center - PIPE_GAP_HALF) > 0)
    ucg_DrawBox(&ucg, PIPE_START_X, *center + PIPE_GAP_HALF, PIPE_W_L1,
                SCREEN_H - *center - PIPE_GAP_HALF);
}

static int16_t update_pipe2(uint8_t *center)
{
  int16_t draw_x  = PIPE_START_X - pipe_x1;
  int16_t erase_x = PIPE_START_X + PIPE_W_L2 - pipe_x1;

  if (draw_x >= 0)
  {
    UCG_SetRGB(0, 255, 255, 255);
    ucg_DrawVLine(&ucg, draw_x, 3, *center - PIPE_GAP_HALF);
    ucg_DrawVLine(&ucg, draw_x, *center + PIPE_GAP_HALF + 2,
                  SCREEN_H - *center - PIPE_GAP_HALF + 1);
  }

  if (erase_x < SCREEN_W && erase_x >= 0)
  {
    UCG_SetRGB(0, 0, 0, 0);
    ucg_DrawVLine(&ucg, erase_x, 3, *center - PIPE_GAP_HALF);
    ucg_DrawVLine(&ucg, erase_x, *center + PIPE_GAP_HALF + 2,
                  SCREEN_H - *center - PIPE_GAP_HALF + 1);
  }

  pipe_x1++;

  if (erase_x <= 0)
  {
    pipe_x1 = 0;
    draw_pipe2(center);
  }

  return draw_x;
}

void Levels_Reset(uint8_t level, uint8_t* out_center)
{
  pipe_x1 = 0;
  if (level == 1) draw_pipe1(out_center);
  else            draw_pipe2(out_center);
}

int16_t Levels_Update(uint8_t level, uint8_t* center)
{
  if (level == 1) return update_pipe1(center);
  return update_pipe2(center);
}
