#ifndef GAME_H
#define GAME_H

#include "circle.h"

#define WINDOW_TITLE "PENDULUM RAYLIB"
#define SCREEN_WIDTH 1120
#define SCREEN_HEIGHT 780
#define TARGET_FPS 60

extern Circle* lastCircle;

void InitGame(void);
void DrawGame(void);
void UpdateGame(void);

#endif