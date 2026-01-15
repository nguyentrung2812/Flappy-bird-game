#ifndef GAME_UI_H
#define GAME_UI_H

#include <stdint.h>

/* Menu: chọn level + start (blocking) */
uint8_t UI_Splash_ChooseLevel(void);

/* Last score hiển thị ở menu */
void UI_SetLastScore(uint16_t s);

#endif
