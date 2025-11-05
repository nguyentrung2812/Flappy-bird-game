/*
 * entities.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef GAME_ENTITIES_H
#define GAME_ENTITIES_H

#include <stdint.h>

typedef struct { int16_t x, y; int8_t vy; uint8_t r; } bird_t;
typedef struct { int16_t x; int8_t gap_y; uint8_t scored; } pipe_t;

#endif /* GAME_ENTITIES_H */
