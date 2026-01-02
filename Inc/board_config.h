
#pragma once

// ====== Cấu hình phần cứng chung cho toàn project ======

#include <stm32f401re.h>
#include <stm32f401re_gpio.h>

// ===== COLOR FIX (RGB/BGR) =====
// Nếu bạn thấy màu bị đảo (vàng -> xanh/cyan) thì để 1, nếu màu đúng để 0
#define LCD_IS_BGR  1

// ===== LED / BUZZER =====
#define LED_GPIOx       GPIOA
#define LED_PIN         GPIO_Pin_11

#define BUZZ_GPIOx      GPIOC
#define BUZZ_PIN        GPIO_Pin_9

// ===== SW (active-LOW, pull-up) =====
#define SW1_GPIOx       GPIOB
#define SW1_PIN         GPIO_Pin_5

#define SW2_GPIOx       GPIOB
#define SW2_PIN         GPIO_Pin_3

#define SW3_GPIOx       GPIOA
#define SW3_PIN         GPIO_Pin_4

#define SW4_GPIOx       GPIOB
#define SW4_PIN         GPIO_Pin_0

#define SW5_GPIOx       GPIOB
#define SW5_PIN         GPIO_Pin_4
