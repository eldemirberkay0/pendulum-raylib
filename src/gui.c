#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include "circle.h"
#include "game.h"
#include "gui.h"
#include "list_operations.h"
#include "random.h"

float guiRadius = 5;
float guiAngularSpeed = 60;
Color guiColor = RED;
float newLength = 10;
bool isLinesActive = 1;
Camera2D camera = { 0 };
bool isPaused;

void InitGUI(void)
{
    camera.zoom = 1;
    camera.offset = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    camera.target = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
}

void DrawGUI(void)
{
    GuiGroupBox((Rectangle){10, 10, 300, 500}, "Control Panel");
    GuiSlider((Rectangle){100, 20, 125, 15}, "Radius", TextFormat("%.1f", guiRadius), &guiRadius, MIN_RADIUS, MAX_RADIUS);
    GuiSlider((Rectangle){100, 40, 125, 15}, "Rod Length", TextFormat("%.1f", newLength), &newLength, MIN_ROD_LENGTH, MAX_ROD_LENGTH);
    GuiSlider((Rectangle){100, 60, 125, 15}, "Angular Speed", TextFormat("%.1f", guiAngularSpeed), &guiAngularSpeed, MIN_ANGULAR_SPEED, MAX_ANGULAR_SPEED);
    GuiColorPicker((Rectangle){55, 85, 150, 100}, "Color", &guiColor);
    GuiCheckBox((Rectangle){200, 200, 20, 20}, "Lines", &isLinesActive);
    GuiLine((Rectangle){25, 325, 275, 1}, "Save/Load");
    GuiSlider((Rectangle){50, 475, 100, 15}, "Zoom", TextFormat("%.1f", camera.zoom), &camera.zoom, MIN_ZOOM, MAX_ZOOM);
    if (isPaused) { DrawText("PAUSED", SCREEN_WIDTH / 2 - 200, 150, 100, GREEN); }
}

void UpdateGUI(void)
{
    if (IsKeyPressed(KEY_SPACE)) { isPaused = !isPaused; }
    camera.zoom += GetMouseWheelMove()*0.05f;
    if (camera.zoom > MAX_ZOOM) { camera.zoom = MAX_ZOOM; }
    else if (camera.zoom < MIN_ZOOM) { camera.zoom = MIN_ZOOM; }
    if (GuiButton((Rectangle){60, 200, 100, 20}, "Add Circle")) { AddCircle((Vector2){lastCircle->center.x + newLength, lastCircle->center.y}, guiRadius, guiColor, guiAngularSpeed); }
    if (GuiButton((Rectangle){60, 225, 100, 20}, "Add Random Circle")) { AddRandomCircle(); }
    if (GuiButton((Rectangle){60, 250, 100, 20}, "Remove Circle")) { RemoveLastCircle(headCircle); }
    if (GuiButton((Rectangle){60, 275, 100, 20}, "Remove 10 Circle")) { for (int i = 0; i < 10; i++) { RemoveLastCircle(headCircle); }}
    if (GuiButton((Rectangle){25, 350, 100, 20}, "Save/Load")) { }
}