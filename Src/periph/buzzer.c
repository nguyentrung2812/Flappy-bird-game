#include "periph/buzzer.h"
#include "board_config.h"
#include "drivers/gpio.h"

#include <stm32f401re_gpio.h>

void Buzzer_Init(void)
{
  GPIO_AllClocks_Enable();

  GPIO_InitTypeDef gi;
  gi.GPIO_Pin   = BUZZ_PIN;
  gi.GPIO_Mode  = GPIO_Mode_OUT;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(BUZZ_GPIOx, &gi);

  Buzzer_Off();
}

void Buzzer_On(void)  { GPIO_SetBits(BUZZ_GPIOx, BUZZ_PIN); }
void Buzzer_Off(void) { GPIO_ResetBits(BUZZ_GPIOx, BUZZ_PIN); }
