/*
 * board_config.h
 *
 *  Created on: Oct 15, 2025
 *      Author: TDCOM
 */

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include <stm32f401re.h>
#include <stm32f401re_rcc.h>
#include <stm32f401re_gpio.h>
#include <system_stm32f4xx.h>
#include <Ucglib.h>

/* ================== LED / BUZZER ================== */
#define LED_GPIOx       GPIOA
#define LED_PIN         GPIO_Pin_11

#define BUZZ_GPIOx      GPIOC
#define BUZZ_PIN        GPIO_Pin_9

/* ================== Switches (active-LOW, pull-up) ================== */
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

/* ================== LCD / Screen geometry ================== */
#define SCR_W 128
#define SCR_H 64
#define PLAY_X0 2
#define PLAY_Y0 6
#define PLAY_W (SCR_W - 4)
#define PLAY_H (SCR_H - 10)

extern ucg_t ucg;   /* declared in gfx/lcd_init.c */

#endif /* BOARD_CONFIG_H */
