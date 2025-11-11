#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "circle.h"
#include "random.h"

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
    
}

void UpdateGame(void)
{
    if (IsKeyPressed(KEY_A))
    {
        Circle* newCircle = (Circle*)malloc(sizeof(Circle));
        lastCircle->next = newCircle;
        lastCircle = newCircle;
        *newCircle = (Circle){(Vector2){SCREEN_WIDTH / 2, lastCircle->center.y + RandomFloat(-55, 55)}, RandomFloat(5, 20), RED, RandomFloat(-180, 180) * DEG2RAD, NULL};
    }
}