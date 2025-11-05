# Flappy Bird – STM32 Nucleo‑F401RE (SPL + Ucglib)

Game Flappy Bird chạy trên kit **STM32 Nucleo‑F401RE** với màn hình OLED SPI (Ucglib).
Điều khiển bằng **USER Button** (PC13), có **âm thanh** khi nhấn và **LED LD2** nháy khi *Game Over*.

> **Vòng đời chương trình:** `MENU → RUN → GAME OVER → MENU`


## Tính năng
- 2 **level** (giữ nút > 2 giây để đổi).
- Nhấn ngắn để **bắt đầu** và **vỗ cánh** (buzzer kêu).
- **LED LD2 (PA5)** nháy khi *Game Over*.
- Ống ngẫu nhiên, tính điểm khi qua tâm ống, kiểm tra va chạm.
  
## Cấu trúc dự án (STM32CubeIDE)

```
.
├── Src/                       # Mã nguồn chính (main.c, game*, driver glue)
├── Startup/                   # startup_stm32f401xe.s, system_stm32f4xx.c
├── Debug/                     # Thư mục build do IDE sinh ra
├── .settings/                 # Thiết lập IDE
├── .project                   # File dự án (Eclipse/CubeIDE)
├── .cproject                  # File cấu hình build
├── Flappybirdgame.launch      # Cấu hình Debug/Run (ST‑Link)
├── STM32F401RETX_FLASH.ld     # Linker script chạy từ Flash (mặc định)
└── STM32F401RETX_RAM.ld       # Linker script chạy từ RAM (tùy chọn)
```

## Phần cứng
- Nucleo‑F401RE, OLED SPI (Ucglib – SPI mềm), BTN PC13, LED PA5, Buzzer PA6.

## Phụ thuộc
- STM32F4 **SPL + CMSIS**, **Ucglib**, module **timer** (`GetMilSecTick`, `processTimerScheduler`).

## Cách chơi
- **Menu:** giữ > 2 giây đổi level; nhấn & thả nhanh để bắt đầu.
- **Trong game:** nhấn để chim vỗ cánh bay lên (beep).
- **Game Over:** hiện “GAME OVER”, LED nháy, dừng ngắn rồi về menu.

## Thuật toán (tóm tắt)
- Tick thời gian khung theo `step_ms`.
- Mỗi khung: đọc BTN → cập nhật vật lý → sinh ống khi hết → tính điểm → vẽ → kiểm tra va chạm.
- Khi va chạm: *Game Over* → **return** về Menu.

## License
MIT – cảm ơn **Ucglib**, **SPL/CMSIS**, **ST‑Link/OpenOCD**.
