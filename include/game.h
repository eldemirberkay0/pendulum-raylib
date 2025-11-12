#ifndef GAME_H
#define GAME_H

#include "circle.h"

#define WINDOW_TITLE "PENDULUM RAYLIB"
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define TARGET_FPS 60

extern Circle* lastCircle;
extern Circle* headCircle;
extern bool isPaused;

void InitGame(void);
void DrawGame(void);
void UpdateGame(void);

#endif