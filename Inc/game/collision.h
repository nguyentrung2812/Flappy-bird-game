/*
 * collision.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H
#include "board_config.h"
#include "game/entities.h"

uint8_t collide(bird_t *b, pipe_t *p, uint8_t gap);

#endif /* GAME_COLLISION_H */
