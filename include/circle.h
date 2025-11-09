#ifndef CIRCLE_H
#define CIRCLE_H

#include <raylib.h>

typedef struct {
    Vector2 center;
}Circle;

// Negative (-) values for CCW, Positive (+) values for CW
// Degree means degree NOT RADIAN
// Can be done with pointers, but structs are not much big
Vector2 RotatePoint(Vector2 ref, Vector2 point, float deg); 
Circle RotateCircle(Circle center, Circle circle, float deg);

#endif