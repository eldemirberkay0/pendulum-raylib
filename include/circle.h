#ifndef CIRCLE_H
#define CIRCLE_H

#include <raylib.h>

typedef struct Circle {
    Vector2 center;
    float radius;
    Color color;
    float angularSpeed; // degree
    struct Circle *nextCirclePtr;
}Circle;

// Used inline for just reformatting
static inline void DrawCircleOP(Circle circle) { DrawCircleV(circle.center, circle.radius, circle.color); }

// Negative (-) values for CCW, Positive (+) values for CW
// Can be done with pointers, but structs are not much big
Vector2 RotatePoint(Vector2 ref, Vector2 point, float deg);
Circle RotateCircle(Circle center, Circle circle, float deg);



#endif