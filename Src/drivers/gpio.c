#include "drivers/gpio.h"
#include "board_config.h"

#include <stm32f401re_rcc.h>
#include <stm32f401re_gpio.h>

// Khởi tạo tất cả GPIO (LED, buzzer, nút)
void drivers_gpio_init_all(void){
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA |
                         RCC_AHB1Periph_GPIOB |
                         RCC_AHB1Periph_GPIOC, ENABLE);

  GPIO_InitTypeDef gi;

  // LED: output
  gi.GPIO_Pin   = LED_PIN;
  gi.GPIO_Mode  = GPIO_Mode_OUT;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LED_GPIOx, &gi);

  // Buzzer: output
  gi.GPIO_Pin   = BUZZ_PIN;
  gi.GPIO_Mode  = GPIO_Mode_OUT;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(BUZZ_GPIOx, &gi);

  // SW1, SW2, SW5: input pull-up
  gi.GPIO_Pin   = SW1_PIN | SW2_PIN | SW5_PIN;
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gi);

  // SW3: input pull-up
  gi.GPIO_Pin   = SW3_PIN;
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &gi);

  // SW4: input pull-up
  gi.GPIO_Pin   = SW4_PIN;
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gi);
}
