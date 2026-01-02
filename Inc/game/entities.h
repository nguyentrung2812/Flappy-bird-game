#pragma once
#include <stdint.h>

// Màn hình
#define SCREEN_W        128
#define SCREEN_H        80

// Pipe
#define PIPE_START_X    115
#define PIPE_W_L1       8
#define PIPE_W_L2       12

// Chim
#define BIRD_X          20
#define BIRD_W          10
#define BIRD_H          7
#define GRAVITY         0.15f
#define JUMP_FORCE      -2.5f

typedef struct {
  // menu
  uint8_t  current_level;
  uint16_t score;          // tính ngầm
  uint16_t last_score;

  // pipe
  uint8_t  pipe_center;
  volatile uint16_t pipe_x1;

  // bird
  volatile float bird_y;
  volatile float bird_v;

  // render flag (set trong ISR)
  volatile uint8_t render_needed;

  // score helper (tính ngầm)
  int16_t  prev_pipe_x;
  uint8_t  scored_this_pipe;
} GameState;

extern GameState g_game;
