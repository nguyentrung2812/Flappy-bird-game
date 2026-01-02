# 🐦 Flappy Bird – STM32 Nucleo-F401RE (SPL + Ucglib)

Flappy Bird chạy trên **STM32 Nucleo-F401RE** với **màn hình LCDLCD** dùng  với **màn hình LCD** dùng.**UĐiều khiển bằng **5 nút nhấn (SW1–SW5)**, có **buzzer** và **LED báo trạng thái**.

> **Vòng đời chương trình:** `MENU → RUN → GAME OVER → MENU`

---

## 🎮 Tính năng

- **2 mức độ khó**: Level 1 & Level 2 (khác trọng lực / tốc độ và độ rộng ống).
- **Menu chọn level + Start**.
- **Buzzer (PC9)** kêu khi **jump**.
- **LED (PA11)** nháy khi **Game Over**.
- Ống sinh ngẫu nhiên theo trục Y, di chuyển ngang.
- **Tính điểm nội bộ** (khi vượt qua ống) và **lưu `LAST SCORE`** để hiển thị ở menu ván sau.  
  *(Không vẽ điểm trong lúc chơi, chỉ hiện `LAST SCORE` ở menu — đúng theo code hiện tại.)*

---

## 🧩 Phụ thuộc

- **STM32F4 SPL + CMSIS**
- **Ucglib** (SPI mềm 4 dây)
- **timer.h**
  - `GetMilSecTick()`
  - `processTimerScheduler()`
  - `TimerInit()`

---

## 🪛 Phần cứng / Chân kết nối

### LED & Buzzer

| Thiết bị | Cổng | Ghi chú |
|---|---|---|
| LED | **PA11** | nháy khi Game Over |
| Buzzer | **PC9** | kêu khi jump |

### Nút nhấn (active-LOW, pull-up)

| Nút | Cổng |
|---|---|
| SW1 | PB5 |
| SW2 | PB3 *(chưa dùng)* |
| SW3 | PA4 |
| SW4 | PB0 *(chưa dùng)* |
| SW5 | PB4 |

### Màn hình

- Ucglib SPI mềm 4 dây
- **128×80** (viền trên/dưới vẽ bằng `DrawHLine` tại y=0 và y=79)

---

## 🕹️ Cách chơi

### Menu

- **SW3**: đổi **Level 1 ↔ Level 2**
- **SW5**: di chuyển dấu `>` xuống **START**
- **SW1**: quay lại chọn LEVEL khi đang đứng ở START
- **SW3** tại START: bắt đầu game
- Menu có **LAST SCORE** (điểm ván trước)

### Trong game

- **SW3**: jump (chim bay lên)
- Chết → LED nháy → lưu `LAST SCORE` → về menu

---

## ⚙️ Tick thời gian & luồng xử lý

- Dùng **TIM2 interrupt** tạo tick:
  - Prescaler = 8399, Period = 199 → **~20ms/tick** (50Hz)

- ISR TIM2:
  1. Đọc jump (SW3) → set vận tốc bay lên
  2. Cập nhật vật lý chim (gravity + velocity)
  3. Tắt buzzer theo tick (không delay trong ISR)
  4. Set cờ `render_needed = 1`

- Main loop:
  1. Khi `render_needed = 1` → cập nhật/vẽ ống
  2. Vẽ sprite chim (xóa cũ, vẽ mới)
  3. Tính điểm nội bộ (không vẽ)
  4. Va chạm → game over → lưu last_score → menu

---

## 📁 Cấu trúc dự án

```text
.
├── Inc/
│   ├── board_config.h
│   ├── drivers/
│   │   ├── gpio.h
│   │   └── timebase.h
│   ├── periph/
│   │   ├── led.h
│   │   ├── buzzer.h
│   │   └── input.h
│   ├── gfx/
│   │   ├── lcd_init.h
│   │   └── render.h
│   └── game/
│       ├── entities.h
│       ├── levels.h
│       ├── collision.h
│       ├── ui.h
│       └── loop.h
├── Src/
│   ├── drivers/
│   │   ├── gpio.c
│   │   └── timebase.c
│   ├── periph/
│   │   ├── led.c
│   │   ├── buzzer.c
│   │   └── input.c
│   ├── gfx/
│   │   ├── lcd_init.c
│   │   └── render.c
│   ├── game/
│   │   ├── levels.c
│   │   ├── collision.c
│   │   ├── ui.c
│   │   └── loop.c
│   └── main.c
├── Startup/
├── Debug/
├── STM32F401RETX_FLASH.ld
└── README.md
```
## 🎨 Fix màu (RGB/BGR)
MMột số màn LCD/driver bị đảo kênh màu (vàng hiển thị thành xanh/cyan).Trong board_config.h:

#define LCD_IS_BGR  1

Màu đúng → LCD_IS_BGR = 0

Màu bị đảo → LCD_IS_BGR = 1

---

## 🧪 Build & Flash
Mở project bằng STM32CubeIDE

Build: Project → Build All

Flash/Debug: Run/Debug qua ST-Link trên Nucleo

---

##🪪 License

Cảm ơn Ucglib, STM32 SPL/CMSIS và cộng đồng STM32.

