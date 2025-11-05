/*
 * timebase.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef DRIVERS_TIMEBASE_H
#define DRIVERS_TIMEBASE_H

#include <stdint.h>

/* Initialize SysTick (1 ms) and start the scheduler timer (TimerInit from timer.h) */
void Timebase_Init(void);

/* Milliseconds since boot (wrap-around safe) */
uint32_t millis(void);

/* Cooperative delay that pumps processTimerScheduler() */
void delay_ms(uint32_t d);

#endif /* DRIVERS_TIMEBASE_H */
