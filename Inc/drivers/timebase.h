#pragma once
#include <stdint.h>

// Khởi tạo SysTick 1ms + Timer scheduler (TimerInit)
void timebase_init(void);

// Trả về ms tick
uint32_t timebase_millis(void);

// Cho scheduler chạy (processTimerScheduler)
void timebase_process(void);

// Delay ms nhưng vẫn chạy scheduler
void timebase_delay_ms(uint32_t ms);
