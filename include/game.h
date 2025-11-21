#ifndef GAME_H
#define GAME_H

#include "circle.h"

#define WINDOW_TITLE "pendulum_raylib"
#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 810
#define TARGET_FPS 144

extern Circle* lastCircle;
extern Circle* headCircle;
extern bool isPaused;

void InitGame(void);
void DrawGame(void);
void UpdateGame(void);

#endif