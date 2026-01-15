#include "periph/input.h"
#include "board_config.h"
#include "drivers/gpio.h"
#include "drivers/timebase.h"

#include <stm32f401re_gpio.h>

static inline uint8_t pin_read_active(GPIO_TypeDef* port, uint16_t pin)
{
  return GPIO_ReadInputDataBit(port, pin) ? 0 : 1; // active LOW
}

/* Debounce + click */
typedef struct {
  uint8_t  last;
  uint32_t t;
} btn_state_t;

static btn_state_t b_sw1 = {0, 0};
static btn_state_t b_sw3 = {0, 0};
static btn_state_t b_sw5 = {0, 0};

static uint8_t btn_clicked(btn_state_t* st, uint8_t now)
{
  uint32_t ms = millis();
  if (now != st->last && (ms - st->t) > 15)
  {
    st->t    = ms;
    st->last = now;
    if (now) return 1;
  }
  return 0;
}

uint8_t SW1_Click(void) { return btn_clicked(&b_sw1, pin_read_active(SW1_GPIOx, SW1_PIN)); }
uint8_t SW3_Click(void) { return btn_clicked(&b_sw3, pin_read_active(SW3_GPIOx, SW3_PIN)); }
uint8_t SW5_Click(void) { return btn_clicked(&b_sw5, pin_read_active(SW5_GPIOx, SW5_PIN)); }

/* Held */
uint8_t SW1_Held(uint16_t ms)
{
  static uint8_t  hold = 0;
  static uint32_t t0   = 0;
  uint8_t p = pin_read_active(SW1_GPIOx, SW1_PIN);

  if (p && !hold) { hold = 1; t0 = millis(); }
  else if (!p)    { hold = 0; }

  return (hold && (millis() - t0) >= ms);
}

uint8_t SW3_Held(uint16_t ms)
{
  static uint8_t  hold = 0;
  static uint32_t t0   = 0;
  uint8_t p = pin_read_active(SW3_GPIOx, SW3_PIN);

  if (p && !hold) { hold = 1; t0 = millis(); }
  else if (!p)    { hold = 0; }

  return (hold && (millis() - t0) >= ms);
}

uint8_t SW5_Held(uint16_t ms)
{
  static uint8_t  hold = 0;
  static uint32_t t0   = 0;
  uint8_t p = pin_read_active(SW5_GPIOx, SW5_PIN);

  if (p && !hold) { hold = 1; t0 = millis(); }
  else if (!p)    { hold = 0; }

  return (hold && (millis() - t0) >= ms);
}

void Input_Init(void)
{
  GPIO_AllClocks_Enable();

  GPIO_InitTypeDef gi;

  /* SW1, SW2, SW5: PB5, PB3, PB4 pull-up */
  gi.GPIO_Pin   = SW1_PIN | SW2_PIN | SW5_PIN;
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gi);

  /* SW3: PA4 pull-up */
  gi.GPIO_Pin   = SW3_PIN;
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &gi);

  /* SW4: PB0 pull-up  */
  gi.GPIO_Pin   = SW4_PIN;
  gi.GPIO_Mode  = GPIO_Mode_IN;
  gi.GPIO_OType = GPIO_OType_PP;
  gi.GPIO_PuPd  = GPIO_PuPd_UP;
  gi.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gi);
}

