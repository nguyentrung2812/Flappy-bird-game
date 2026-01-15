#include "game/collision.h"
#include "board_config.h"

uint8_t check_collision(float b_y, int16_t p_x, uint8_t p_center, uint8_t current_level)
{
  if (b_y <= CEIL_Y)  return 1;
  if (b_y >= FLOOR_Y) return 1;

  int16_t bird_left  = BIRD_X;
  int16_t bird_right = BIRD_X + BIRD_W;

  if (current_level == 1) {
    if (p_x < bird_right && (p_x + PIPE_W_L1) > bird_left) {
      if (b_y < (p_center - 15)) return 1;
      if ((b_y + BIRD_H) > (p_center + 15)) return 1;
    }
  } else {
    if (p_x < bird_right && (p_x + PIPE_W_L2) > bird_left) {
      if (b_y < (p_center - 15)) return 1;
      if ((b_y + BIRD_H) > (p_center + 15)) return 1;
    }
  }
  return 0;
}
