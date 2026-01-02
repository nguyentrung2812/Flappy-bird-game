#include "drivers/timebase.h"

#include "stm32f401re.h"
#include "system_stm32f4xx.h"

#include <timer.h>

void timebase_init(void){
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock / 1000);  // 1ms
  TimerInit();                             // scheduler lib bạn đang dùng
}

uint32_t timebase_millis(void){
  return GetMilSecTick();
}

void timebase_process(void){
  processTimerScheduler();
}

void timebase_delay_ms(uint32_t ms){
  uint32_t t0 = timebase_millis();
  while((uint32_t)(timebase_millis() - t0) < ms){
    timebase_process();
  }
}
