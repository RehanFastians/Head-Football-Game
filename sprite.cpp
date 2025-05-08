#include "sprite.h"
#include "raylib.h"
#include <iostream>
#include <string>
using namespace std;

Vector2 Sprite::getPosition()
{
    return position;
}
void Sprite::setSpeed(int newSpeed)
{
    speed = newSpeed;
}
void Sprite::setPosition(Vector2 newPosition)
{
    position = newPosition;
}
void Sprite::updatePosition(Vector2 newPosition)
{
    position = newPosition;
}

Texture2D Sprite::getPlayerImage()
{
    return playerImage;
}

Vector2 Sprite::getDirection()
{
    return direction;
}

void Sprite ::draw()
{
    DrawTexture(playerImage, position.x, position.y, WHITE);
}