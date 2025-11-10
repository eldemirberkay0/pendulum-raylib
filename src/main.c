#include <raylib.h>
#include "game.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    InitGame();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        UpdateGame();
        DrawGame();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}