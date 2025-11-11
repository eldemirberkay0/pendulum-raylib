#include <raylib.h>
#include <raymath.h>
#include <stddef.h>
#include "list_operations.h"

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

}

void UpdateCircles(Circle* circle)
{

}