#include <raylib.h>
#include <math.h>
#include "circle.h"

Vector2 RotatePoint(Vector2 ref, Vector2 point, float deg)
{
    Vector2 tempPoint;
    deg *= DEG2RAD;
    tempPoint.x = ref.x + ((point.x - ref.x) * cos(deg)) - ((point.y - ref.y) * sin(deg));
    tempPoint.y = ref.y + ((point.x - ref.x) * sin(deg)) + ((point.y - ref.y) * cos(deg));
    return tempPoint;
}