#include "gfx/lcd_init.h"
#include "board_config.h"

ucg_t g_ucg;

void lcd_init(void){
  Ucglib4WireSWSPI_begin(&g_ucg, 0);      // 0: normal
  ucg_SetFont(&g_ucg, ucg_font_helvR12_tf);
  ucg_ClearScreen(&g_ucg);
  ucg_SetFont(&g_ucg, ucg_font_helvR08_tf);

  // set mặc định 2 color index cho text
  ucg_SetColor(&g_ucg, 0, 255,255,255);
  ucg_SetColor(&g_ucg, 1, 0,0,0);

  ucg_SetRotate180(&g_ucg);              // bỏ nếu LCD đúng chiều
}
