#include <system_stm32f4xx.h>
#include <timer.h>

#include "drivers/timebase.h"
#include "gfx/lcd_init.h"

#include "periph/led.h"
#include "periph/buzzer.h"
#include "periph/input.h"

#include "game/loop.h"

int main(void)
{
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock / 1000);

  TimerInit();

  LED_Init();
  Buzzer_Init();
  Input_Init();

  LCD_Init_All();

  Timebase_TIM2_Config_20ms();

  Game_RunForever();
}
