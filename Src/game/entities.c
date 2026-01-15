#include "game/entities.h"
#include "board_config.h"
#include "periph/buzzer.h"

static volatile float   bird_y        = 30.0f;
static volatile float   bird_velocity = 0.0f;
static volatile uint8_t buzz_ticks    = 0;

void Bird_Reset(void)
{
  bird_y = 30.0f;
  bird_velocity = 0.0f;
}

float Bird_GetY(void) { return bird_y; }
int16_t Bird_GetY_Int(void) { return (int16_t)bird_y; }

void Buzzer_FireJump(void)
{
  Buzzer_On();
  buzz_ticks = 3; // ~60ms
}

void Buzzer_OnTick(void)
{
  if (buzz_ticks > 0)
  {
    buzz_ticks--;
    if (buzz_ticks == 0) Buzzer_Off();
  }
}

void Bird_OnTick(uint8_t current_level)
{
  /* gravity */
  if (current_level == 1) bird_velocity += (GRAVITY - 0.05f);
  else                    bird_velocity +=  GRAVITY;

  bird_y += bird_velocity;

  if (bird_y < CEIL_Y) {
    bird_y = CEIL_Y;
    bird_velocity = 0;
  }
  if (bird_y > FLOOR_Y) {
    bird_y = FLOOR_Y;
  }
}
void Bird_SetJump(uint8_t current_level)
{
  if (current_level == 1) bird_velocity = (JUMP_FORCE + 0.7f);
  else                    bird_velocity =  JUMP_FORCE;
}
