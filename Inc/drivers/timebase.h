#ifndef DRIVERS_TIMEBASE_H
#define DRIVERS_TIMEBASE_H

#include <stdint.h>

uint32_t millis(void);
void delay_ms(uint32_t d);

/* TIM2 tick 20ms (50Hz) cho game */
void Timebase_TIM2_Config_20ms(void);

#endif
