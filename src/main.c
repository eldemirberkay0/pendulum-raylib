#include <stdio.h>
#include <raylib.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("DEMO SCREEN", 250, 250, 60, GREEN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}