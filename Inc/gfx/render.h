/*
 * render.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef GFX_RENDER_H
#define GFX_RENDER_H

#include "board_config.h"
#include "game/entities.h"

void clear_playfield(void);
void draw_frame(uint16_t score);
void draw_bird(bird_t *b);
void draw_pipe(pipe_t *p, uint8_t gap);

#endif /* GFX_RENDER_H */
