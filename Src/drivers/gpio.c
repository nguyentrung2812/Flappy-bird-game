/*
 * gpio.c
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */


#include "drivers/gpio.h"

void GPIO_EnableAllClocks(void){
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA |
                         RCC_AHB1Periph_GPIOB |
                         RCC_AHB1Periph_GPIOC, ENABLE);
}
