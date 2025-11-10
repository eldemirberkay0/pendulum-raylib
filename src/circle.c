#include "circle.h"
#include <math.h>

Vector2 RotatePoint(Vector2 ref, Vector2 point, float deg)
{
    Vector2 tempPoint;
    deg *= DEG2RAD;
    tempPoint.x = ref.x + ((point.x - ref.x) * cos(deg)) - ((point.y - ref.y) * sin(deg));
    tempPoint.y = ref.y + ((point.x - ref.x) * sin(deg)) + ((point.y - ref.y) * cos(deg));
    return tempPoint;
}

Circle RotateCircle(Circle ref, Circle circle, float deg)
{
    circle.center = RotatePoint(ref.center, circle.center, deg);
    return circle;
}