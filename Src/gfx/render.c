/*
 * render.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "gfx/render.h"

void clear_playfield(void){
  ucg_SetColor(&ucg, 0, 0,0,0);
  ucg_DrawBox(&ucg, 1, 1, SCR_W-3, SCR_H-3);
  ucg_SetColor(&ucg, 0, 255,255,255);
}

void draw_frame(uint16_t score){
  ucg_SetColor(&ucg, 0, 255,255,255);
  ucg_DrawFrame(&ucg, 0, 0, SCR_W-1, SCR_H-1);
  char buf[10];
  snprintf(buf,sizeof(buf),"%u",score);
  ucg_DrawString(&ucg, 2, 10, 0, buf);
}

void draw_bird(bird_t *b){
  ucg_DrawDisc(&ucg, b->x, b->y, b->r, UCG_DRAW_ALL);
}

void draw_pipe(pipe_t *p, uint8_t gap){
  int top_h = p->gap_y - gap/2;
  int bot_y = p->gap_y + gap/2;
  if(top_h < 0) top_h = 0;
  if(bot_y > PLAY_H) bot_y = PLAY_H;
  ucg_DrawBox(&ucg, p->x, PLAY_Y0, 6, top_h);
  ucg_DrawBox(&ucg, p->x, PLAY_Y0 + bot_y, 6, PLAY_H - bot_y);
}

