#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include "circle.h"

#define SCREEN_WIDTH 1120
#define SCREEN_HEIGHT 780
#define TARGET_FPS 60

float angularSpeed = 60;
float angularSpeedC2 = 180;

int main()
{
    Circle testCirle = {SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 100};
    Circle centerCircle = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    Circle c2 = {SCREEN_WIDTH / 2 + 150, SCREEN_HEIGHT / 2 + 200};

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RAYLIB KANZII");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        DrawCircleV(c2.center, 10, GREEN);

        ClearBackground(RAYWHITE);
        DrawLineV(centerCircle.center, testCirle.center,BLACK);
        DrawLineV(testCirle.center, c2.center,BLACK);
        DrawCircleV(centerCircle.center, 10, BLACK);
        DrawCircleV(testCirle.center, 20, RED);
        DrawCircleV(c2.center, 25, GREEN);
        
        EndDrawing();
        
        Vector2 temp = testCirle.center;
        testCirle = RotateCircle(centerCircle, testCirle, angularSpeed * 1 / GetFPS() * DEG2RAD);
        Vector2 deltaPos = Vector2Subtract(testCirle.center, temp);
        c2 = RotateCircle(testCirle, c2, angularSpeedC2 * 1 / GetFPS() * DEG2RAD);
        c2.center = Vector2Add(c2.center, deltaPos);
    }

    CloseWindow();

    return 0;
}