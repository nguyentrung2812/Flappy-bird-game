#include "periph/input.h"
#include "board_config.h"
#include "drivers/timebase.h"

#include <stm32f401re_gpio.h>

// active-LOW: nhấn = 1
static inline uint8_t pin_read_active(GPIO_TypeDef* port, uint16_t pin){
  return GPIO_ReadInputDataBit(port, pin) ? 0 : 1;
}

// debounce click
typedef struct { uint8_t last; uint32_t t; } btn_state_t;
static btn_state_t b1={0,0}, b3={0,0}, b5={0,0};

static uint8_t btn_clicked(btn_state_t* st, uint8_t now){
  uint32_t ms = timebase_millis();
  if(now != st->last && (ms - st->t) > 15){
    st->t = ms;
    st->last = now;
    if(now) return 1;
  }
  return 0;
}

uint8_t sw1_click(void){ return btn_clicked(&b1, pin_read_active(SW1_GPIOx, SW1_PIN)); }
uint8_t sw3_click(void){ return btn_clicked(&b3, pin_read_active(SW3_GPIOx, SW3_PIN)); }
uint8_t sw5_click(void){ return btn_clicked(&b5, pin_read_active(SW5_GPIOx, SW5_PIN)); }

// held
static uint8_t held_generic(GPIO_TypeDef* port, uint16_t pin, uint16_t ms){
  static uint8_t  hold = 0;
  static uint32_t t0   = 0;

  uint8_t p = pin_read_active(port, pin);
  if(p && !hold){ hold = 1; t0 = timebase_millis(); }
  else if(!p){ hold = 0; }
  return (hold && (timebase_millis() - t0) >= ms);
}

uint8_t sw1_held(uint16_t ms){ return held_generic(SW1_GPIOx, SW1_PIN, ms); }
uint8_t sw3_held(uint16_t ms){ return held_generic(SW3_GPIOx, SW3_PIN, ms); }
uint8_t sw5_held(uint16_t ms){ return held_generic(SW5_GPIOx, SW5_PIN, ms); }
