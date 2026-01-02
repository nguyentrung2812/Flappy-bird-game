#include "drivers/timebase.h"
#include "drivers/gpio.h"
#include "gfx/lcd_init.h"
#include "game/loop.h"

int main(void){
  timebase_init();
  drivers_gpio_init_all();
  lcd_init();

  game_init_state();
  game_run_forever();

  while(1){}
}
