#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include "list_operations.h"
#include "circle.h"
#include "game.h"

Vector2 deltaPos;

void DrawCircles(Circle* circle)
{
    while (circle != NULL)
    {
        DrawCircleOP(circle);
        circle = circle->next;
    }
}

void DrawLines(Circle* circle)
{
    while (circle->next != NULL)
    {
        DrawLineV(circle->center, circle->next->center, GRAY);
        circle = circle->next;
    }
}

void UpdateCircles(Circle* circle)
{
    deltaPos = Vector2Zero();
    while (circle->next != NULL)
    {
        Vector2 oldPos = circle->next->center;
        RotateCircle(circle->next, circle, circle->next->angularSpeed);
        MoveCircle(circle->next, deltaPos);
        deltaPos = Vector2Subtract(circle->next->center, oldPos);
        circle = circle->next;
    }
}

void AddCircle(Vector2 center, float radius, Color color, float angularSpeed)
{
    Circle* newCircle = (Circle*)malloc(sizeof(Circle));
    *newCircle = (Circle){center, radius, color, angularSpeed, NULL};
    lastCircle->next = newCircle;
    lastCircle = newCircle;
}

void RemoveLastCircle(Circle* circle)
{
    if (lastCircle == headCircle) { return; }
    while (circle->next != lastCircle) { circle = circle->next; }
    circle->next = NULL;
    free(lastCircle);
    lastCircle = circle;
}