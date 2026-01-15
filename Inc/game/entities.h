#ifndef GAME_ENTITIES_H
#define GAME_ENTITIES_H

#include <stdint.h>

void Bird_Reset(void);
float Bird_GetY(void);
int16_t Bird_GetY_Int(void);

/* gọi trong TIM2 ISR */
void Bird_OnTick(uint8_t current_level);

/* buzzer tick timeout gọi trong TIM2 ISR */
void Buzzer_OnTick(void);
void Buzzer_FireJump(void);

void Bird_SetJump(uint8_t current_level);
#endif
