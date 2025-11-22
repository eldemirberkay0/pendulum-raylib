#ifndef GUI_H
#define GUI_H

#include <raylib.h>
#include "circle.h"

#define MIN_RADIUS 5
#define MAX_RADIUS 50
#define MIN_ROD_LENGTH 1
#define MAX_ROD_LENGTH 200
#define MIN_ANGULAR_SPEED -720
#define MAX_ANGULAR_SPEED 720
#define MIN_ZOOM 0.5
#define MAX_ZOOM 5

extern float guiRadius;
extern float guiAngularSpeed;
extern Color guiColor;
extern float guiRodLength;
extern bool isLineActive;
extern bool isOutlineActive;
extern Camera2D camera;

void InitGUI(void);
void DrawGUI(void);
void UpdateGUI(void);

#endif