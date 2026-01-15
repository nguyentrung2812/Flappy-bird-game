#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>
#include <stm32f401re_gpio.h>

/* ============================ LCD COLOR ORDER ============================ */
/* Nếu màu bị đảo (vàng -> xanh) thì để LCD_IS_BGR = 1, đúng màu thì = 0 */
#define LCD_IS_BGR  1

/* =============================== GPIO: LED/BUZZ ============================= */
#define LED_GPIOx   GPIOA
#define LED_PIN     GPIO_Pin_11

#define BUZZ_GPIOx  GPIOC
#define BUZZ_PIN    GPIO_Pin_9

/* ============================== GPIO: SWITCHES ============================== */
/* Switch active-LOW, có kéo lên (pull-up): nhấn -> đọc 0 */
#define SW1_GPIOx   GPIOB
#define SW1_PIN     GPIO_Pin_5

#define SW2_GPIOx   GPIOB
#define SW2_PIN     GPIO_Pin_3

#define SW3_GPIOx   GPIOA
#define SW3_PIN     GPIO_Pin_4

#define SW4_GPIOx   GPIOB
#define SW4_PIN     GPIO_Pin_0

#define SW5_GPIOx   GPIOB
#define SW5_PIN     GPIO_Pin_4

/* ============================ SCREEN / PIPE SETTINGS ======================== */
#define SCREEN_W       128
#define SCREEN_H       78

#define PIPE_START_X   115
#define PIPE_W_L1      8
#define PIPE_W_L2      12
#define PIPE_GAP_HALF  18

/* =============================== BIRD SETTINGS ============================== */
#define BIRD_X      20
#define BIRD_W      12
#define BIRD_H      8

#define GRAVITY     0.15f
#define JUMP_FORCE  -2.5f

/* Trần / sàn logic */
#define CEIL_Y   0.0f
#define FLOOR_Y  (SCREEN_H - 1 - BIRD_H)

#endif
