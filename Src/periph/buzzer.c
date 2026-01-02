#include "periph/buzzer.h"
#include "board_config.h"
#include <stm32f401re_gpio.h>

// số tick còn lại để kêu (volatile vì dùng trong ISR)
static volatile uint8_t s_buzz_ticks = 0;

void buzzer_on(void){
  GPIO_SetBits(BUZZ_GPIOx, BUZZ_PIN);
}
void buzzer_off(void){
  GPIO_ResetBits(BUZZ_GPIOx, BUZZ_PIN);
}

void buzzer_beep_ticks(uint8_t ticks){
  buzzer_on();
  s_buzz_ticks = ticks;
}

void buzzer_tick_20ms(void){
  if(s_buzz_ticks > 0){
    s_buzz_ticks--;
    if(s_buzz_ticks == 0){
      buzzer_off();
    }
  }
}
