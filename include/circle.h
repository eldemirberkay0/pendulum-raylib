#ifndef CIRCLE_H
#define CIRCLE_H

#include <raylib.h>
#include <raymath.h>

typedef struct Circle {
    Vector2 center;
    float radius;
    Color color;
    float angularSpeed; // degree
    struct Circle *next;
}Circle;

// Negative (-) values for CCW, Positive (+) values for CW
Vector2 RotatePoint(Vector2 ref, Vector2 point, float deg);

// Used inline for just reformatting
static inline void DrawCircleOP(Circle* circle) { DrawCircleV(circle->center, circle->radius, circle->color); }
static inline void RotateCircle(Circle* circle, Circle* ref, float deg) { circle->center = RotatePoint(circle->center, ref->center, deg); }
static inline void MoveCircle(Circle* circle, Vector2 pos) { circle->center = Vector2Add(circle->center, pos); }

#endif