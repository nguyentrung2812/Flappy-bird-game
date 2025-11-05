/*
 * buzzer.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef PERIPH_BUZZER_H
#define PERIPH_BUZZER_H
#include "board_config.h"

void Buzzer_Init(void);
void Buzzer_Beep(uint16_t ms);

#endif /* PERIPH_BUZZER_H */
