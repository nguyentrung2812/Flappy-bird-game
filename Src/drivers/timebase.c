#include "drivers/timebase.h"

#include <stm32f401re_rcc.h>
#include <stm32f401re_tim.h>
#include <misc.h>

#include <timer.h>  // GetMilSecTick(), processTimerScheduler()

uint32_t millis(void)
{
  return GetMilSecTick();
}

void delay_ms(uint32_t d)
{
  uint32_t t0 = millis();
  while ((uint32_t)(millis() - t0) < d)
  {
    processTimerScheduler();
  }
}

void Timebase_TIM2_Config_20ms(void)
{
  TIM_TimeBaseInitTypeDef tim;
  NVIC_InitTypeDef nvic;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  tim.TIM_Prescaler     = 8399;               // 84MHz/(8399+1)=10kHz
  tim.TIM_Period        = 199;                // 10kHz/(199+1)=50Hz => 20ms
  tim.TIM_ClockDivision = TIM_CKD_DIV1;
  tim.TIM_CounterMode   = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2, &tim);

  nvic.NVIC_IRQChannel                   = TIM2_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 0;
  nvic.NVIC_IRQChannelSubPriority        = 1;
  nvic.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&nvic);

  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM2, ENABLE);
}
