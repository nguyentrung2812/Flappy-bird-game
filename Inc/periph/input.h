/*
 * input.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef PERIPH_INPUT_H
#define PERIPH_INPUT_H
#include "board_config.h"
#include <stdint.h>

void Input_Init(void);

/* Rising-edge click (debounced) */
uint8_t SW1_Click(void);
uint8_t SW2_Click(void);
uint8_t SW3_Click(void);
uint8_t SW4_Click(void);
uint8_t SW5_Click(void);

/* Held helpers (true while held for >= ms) */
uint8_t SW3_Held(uint16_t ms);
uint8_t SW4_Held(uint16_t ms);

#endif /* PERIPH_INPUT_H */
