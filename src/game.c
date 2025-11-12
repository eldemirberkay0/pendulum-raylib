#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "circle.h"
#include "random.h"
#include "list_operations.h"

Circle* headCircle;
Circle* lastCircle;
bool isLinesActive = 1;

void InitGame(void)
{
    InitRandomSeed();
    headCircle = (Circle*)malloc(sizeof(Circle));
    lastCircle = headCircle;
    *headCircle = (Circle){(Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, 10, BLACK, 0, NULL}; // Creates the head
}

void DrawGame(void)
{
    ClearBackground(RAYWHITE);
    if (isLinesActive) { DrawLines(headCircle); }
    DrawCircles(headCircle);
    if (isPaused) { DrawText("PAUSED", SCREEN_WIDTH / 2 - 200, 150, 100, GREEN); }
}

void UpdateGame(void)
{
    UpdateCircles(headCircle);
    if (IsKeyPressed(KEY_A))
    {
        AddCircle((Vector2){SCREEN_WIDTH / 2, lastCircle->center.y + RandomFloat(-50, 50)}, RandomFloat(5, 20), (Color){RandomFloat(0,255), RandomFloat(0,255), RandomFloat(0,255), 255}, RandomFloat(-180, 180) * DEG2RAD);
    }
    if (IsKeyPressed(KEY_D)) { RemoveLastCircle(headCircle); }
}