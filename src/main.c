#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "game.h"

bool isPaused = false;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    InitGame();
    
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE)) { isPaused = !isPaused; }
        if (!isPaused) { UpdateGame(); }
        BeginDrawing();
        DrawGame();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}