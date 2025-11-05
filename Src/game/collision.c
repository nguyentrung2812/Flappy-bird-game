/*
 * collision.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "game/collision.h"

uint8_t collide(bird_t *b, pipe_t *p, uint8_t gap){
  if(b->y - b->r <= PLAY_Y0 || b->y + b->r >= PLAY_Y0 + PLAY_H) return 1;
  if(b->x + b->r >= p->x && b->x - b->r <= p->x + 6){
    if(!(b->y > (p->gap_y - gap/2) && b->y < (p->gap_y + gap/2))) return 1;
  }
  return 0;
}
