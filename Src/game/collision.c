#include "game/collision.h"
#include "game/entities.h"

uint8_t collision_check(float b_y, int16_t p_x, uint8_t p_center, uint8_t level){
  // chạm trần/sàn
  if(b_y < 0 || b_y > (80 - BIRD_H)) return 1;

  int16_t bird_left  = BIRD_X;
  int16_t bird_right = BIRD_X + BIRD_W;

  int16_t w = (level==1) ? PIPE_W_L1 : PIPE_W_L2;

  // chạm ống theo X
  if(p_x < bird_right && (p_x + w) > bird_left){
    if(b_y < (p_center - 15)) return 1;
    if((b_y + BIRD_H) > (p_center + 15)) return 1;
  }
  return 0;
}
