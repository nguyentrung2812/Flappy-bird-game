/*
 * led.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef PERIPH_LED_H
#define PERIPH_LED_H
#include "board_config.h"

void LED_Init(void);
static inline void LED_On(void)  { GPIO_SetBits(LED_GPIOx, LED_PIN); }
static inline void LED_Off(void) { GPIO_ResetBits(LED_GPIOx, LED_PIN); }
static inline void LED_Toggle(void){ GPIO_ToggleBits(LED_GPIOx, LED_PIN); }
void LED_Blink(uint8_t times, uint16_t on_ms, uint16_t off_ms);

#endif /* PERIPH_LED_H */
