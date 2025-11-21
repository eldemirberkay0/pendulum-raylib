#include <raylib.h>
#include "game.h"
#include "gui.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    InitGame();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        if (!isPaused) { UpdateGame(); }
        DrawGame();
        EndMode2D();
        UpdateGUI();
        DrawGUI();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}