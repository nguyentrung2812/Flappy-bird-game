#ifndef GFX_RENDER_H
#define GFX_RENDER_H

#include <stdint.h>

void Render_DrawFrameLines(void);

/* Bird sprite render */
void Bird_DrawAt(int16_t x, int16_t y);
void Bird_EraseAt(int16_t x, int16_t y);
void Bird_UpdateSprite(int16_t current_y, int16_t old_y);

#endif
