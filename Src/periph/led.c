#include "periph/led.h"
#include "board_config.h"
#include <stm32f401re_gpio.h>

void led_on(void){ GPIO_SetBits(LED_GPIOx, LED_PIN); }
void led_off(void){ GPIO_ResetBits(LED_GPIOx, LED_PIN); }
void led_toggle(void){ GPIO_ToggleBits(LED_GPIOx, LED_PIN); }
