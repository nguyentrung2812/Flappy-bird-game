# 🐦 Flappy Bird – STM32 Nucleo-F401RE (SPL + Ucglib)

Game **Flappy Bird** chạy trên **STM32 Nucleo-F401RE** với **OLED SPI** (Ucglib).  
Điều khiển bằng **nút nhấn (SW1–SW5)**, có **buzzer** và **LED báo trạng thái**.

> **Vòng đời chương trình:** `MENU → RUN → GAME OVER → MENU`

---

## 🎮 Tính năng

- 2 **mức độ khó (Level 1 & 2)**  
- Nhấn **SW3** để **bắt đầu** và **đổi level**.  
- **LED LD2 (PA11)** nháy khi *Game Over*.  
- **Buzzer (PC9)** kêu khi thao tác.  
- Ống sinh ngẫu nhiên, tính điểm khi vượt qua, kiểm tra va chạm.

---

## ⚙️ Cấu trúc dự án

```
.
├── Inc/
│ ├── board_config.h # Cấu hình chân, LCD, constants
│ ├── drivers/
│ │ ├── gpio.h
│ │ └── timebase.h
│ ├── periph/
│ │ ├── led.h
│ │ ├── buzzer.h
│ │ └── input.h
│ ├── gfx/
│ │ ├── lcd_init.h
│ │ └── render.h
│ └── game/
│ ├── entities.h
│ ├── levels.h
│ ├── collision.h
│ ├── ui.h
│ └── loop.h
│
├── Src/
│ ├── drivers/
│ │ ├── gpio.c
│ │ └── timebase.c
│ ├── periph/
│ │ ├── led.c
│ │ ├── buzzer.c
│ │ └── input.c
│ ├── gfx/
│ │ ├── lcd_init.c
│ │ └── render.c
│ ├── game/
│ │ ├── levels.c
│ │ ├── collision.c
│ │ ├── ui.c
│ │ ├── loop.c
│ │ └── entities.c 
│ └── main.c 
│
├── Startup/ # system_stm32f4xx.c, startup_stm32f401xe.s
├── Debug/ # Thư mục build (CubeIDE)
├── .project / .cproject # Cấu hình Eclipse/CubeIDE
├── Flappybirdgame.launch # Cấu hình Debug (ST-Link)
├── STM32F401RETX_FLASH.ld # Linker script chạy từ Flash
├── STM32F401RETX_RAM.ld # Linker script chạy từ RAM
└── README.md
```

---

## 🧩 Phụ thuộc

- **STM32F4 SPL + CMSIS**  
- **Ucglib** (SPI mềm 4 dây)  
- **timer.h** (hàm `GetMilSecTick`, `processTimerScheduler`)  

---

## 🪛 Phần cứng mặc định

| Thiết bị | Cổng | Ghi chú |
|-----------|-------|----------|
| LED | PA11 | LD2 – nháy khi *Game Over* |
| Buzzer | PC9 | Buzzer thụ động |
| SW1 | PB5 | Nút nhấn 1 |
| SW2 | PB3 | Nút nhấn 2 |
| SW3 | PA4 | **Bắt đầu chơi / Đổi level** |
| SW4 | PB0 | Giữ lâu để chọn |
| SW5 | PB4 | Di chuyển menu |
| LCD | SPI mềm (Ucglib) | OLED 128×64 |

---

## 🕹️ Cách chơi

- **Menu:** Nhấn **SW3** để đổi **level**.  
- **Trong game:** Nhấn **SW3** để **bắt đầu chơi** và **vỗ cánh** (chim bay lên).  
- **Game Over:** Sau khi chim va chạm hoặc chạm sàn/trần, LED LD2 nháy 6 lần, sau đó quay lại **menu**.

---

## 🧠 Thuật toán chính

1. **Tick thời gian** mỗi `step_ms`.  
2. Đọc input → cập nhật vận tốc chim → áp dụng trọng lực.  
3. Cập nhật vị trí ống → sinh mới khi ra khỏi màn hình.  
4. Tính điểm, vẽ lại khung, chim, ống.  
5. Nếu va chạm → hiện “GAME OVER” → nháy LED → trở về menu.

---

## 🪪 Giấy phép

**MIT License**  
Cảm ơn **Ucglib**, **STM32 SPL/CMSIS**, **ST-Link/OpenOCD**, và cộng đồng STM32.
