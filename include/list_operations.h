#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include "circle.h"

extern int segments;

void DrawLines(Circle* circle);
void DrawCircles(Circle* circle);
void UpdateCircles(Circle* circle);
void AddCircle(Vector2 center, float radius, Color color, float angularSpeed);
void AddRandomCircle(void);
void RemoveLastCircle(Circle* circle);

#endif