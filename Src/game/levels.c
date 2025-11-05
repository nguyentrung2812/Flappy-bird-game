/*
 * levels.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "game/levels.h"

level_cfg_t LEVELS[2] = {
  { .pipe_gap=26, .pipe_speed=2, .gravity=1, .flap_vel=-6, .step_ms=28 },
  { .pipe_gap=22, .pipe_speed=3, .gravity=1, .flap_vel=-7, .step_ms=22 }
};

uint8_t current_level = 1; /* 0..1 index; default 1 */
