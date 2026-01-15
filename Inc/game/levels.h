#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H

#include <stdint.h>

void Levels_Reset(uint8_t level, uint8_t* out_center);
int16_t Levels_Update(uint8_t level, uint8_t* center); /* return current pipe x */

#endif
