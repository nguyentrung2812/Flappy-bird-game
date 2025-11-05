/*
 * levels.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H

#include <stdint.h>

typedef struct {
  uint8_t pipe_gap;
  uint8_t pipe_speed;
  uint8_t gravity;
  int8_t  flap_vel;
  uint16_t step_ms;
} level_cfg_t;

extern level_cfg_t LEVELS[2];
extern uint8_t current_level;

#endif /* GAME_LEVELS_H */
