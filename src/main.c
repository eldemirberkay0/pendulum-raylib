#include <stdio.h>
#include <raylib.h>
#include "circle.h"

#define SCREEN_WIDTH 1120
#define SCREEN_HEIGHT 780

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RAYLIB KANZII");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawLine(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 50, BLACK);

        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10, BLACK);

        DrawCircle(SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 50, 20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}