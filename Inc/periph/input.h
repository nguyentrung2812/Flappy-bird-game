#ifndef PERIPH_INPUT_H
#define PERIPH_INPUT_H

#include <stdint.h>

void Input_Init(void);

/* Click (dùng SW1, SW3, SW5) */
uint8_t SW1_Click(void);
uint8_t SW3_Click(void);
uint8_t SW5_Click(void);

uint8_t SW1_Held(uint16_t ms);
uint8_t SW3_Held(uint16_t ms);
uint8_t SW5_Held(uint16_t ms);

#endif
