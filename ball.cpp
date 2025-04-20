#include "ball.h"
#include "raylib.h"
using namespace std;

Vector2 Ball ::getPosition()
{
    return position;
}

void Ball ::setSpeed(Vector2 speed)
{
    this->speed = speed;
}

void Ball ::updatePosition(Vector2 pos)
{
    position = pos;
}

void Ball ::update()
{
    position.x += speed.x;
    position.y += speed.y;
    if (speed.x > 0)
        speed.x -= airResistance;
    else if (speed.x < 0)
        speed.x += airResistance;
    if (speed.y > 0)
        speed.y -= gravity;
    else if (speed.y < 0)
        speed.y += gravity;
}