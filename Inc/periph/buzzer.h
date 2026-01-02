#pragma once
#include <stdint.h>

void buzzer_on(void);
void buzzer_off(void);

// Gọi trong ISR TIM2 mỗi tick (20ms) để auto tắt
void buzzer_tick_20ms(void);

// Kêu theo số tick (1 tick = 20ms)
void buzzer_beep_ticks(uint8_t ticks);
