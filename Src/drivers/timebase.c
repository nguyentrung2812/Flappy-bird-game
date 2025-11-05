/*
 * timebase.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "drivers/timebase.h"
#include "board_config.h"
#include <timer.h>

static volatile uint32_t g_ms = 0;

uint32_t millis(void){ return GetMilSecTick(); } /* From your timer.h */

void delay_ms(uint32_t d){
  uint32_t t = millis();
  while((uint32_t)(millis() - t) < d){
    processTimerScheduler();
  }
}

void Timebase_Init(void){
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock / 1000); /* 1 ms */
  TimerInit(); /* provided by your timer lib */
}
