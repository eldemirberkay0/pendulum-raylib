#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "circle.h"
#include "random.h"

Circle centerCircle;

void InitGame(void)
{
    InitRandomSeed();
    centerCircle = (Circle){(Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, 10, BLACK, 0, NULL}; // Creates the head
}

void DrawGame(void)
{
    ClearBackground(RAYWHITE);
    // Draw circles starting from head (center circle)
}

void UpdateGame(void)
{
    if (IsKeyPressed(KEY_A))
    {
        printf("%f", RandomFloat(-10, 10));
        // Create a new circle and link the previous one to that
    }
}