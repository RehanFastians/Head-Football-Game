#include "player.h"
#include "raylib.h"
#include <iostream>
#include <string>

using namespace std;

Vector2 Player::getPosition()
{
    return position;
}
void Player::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

void Player::setPosition(Vector2 newPosition)
{
    position = newPosition;
}

void Player::update()
{
    if (IsKeyDown(controlsKey[0])) // up
        position.y -= speed;
    if (IsKeyDown(controlsKey[1])) // down
        position.y += speed;
    if (IsKeyDown(controlsKey[2])) // left
        position.x -= speed;
    if (IsKeyDown(controlsKey[3])) // right
        position.x += speed;
    if (position.x < 0)
        position.x = 0;
    if (position.x > GetScreenWidth() - playerImage.width)
        position.x = GetScreenWidth() - playerImage.width;
    if (position.y < 0)
        position.y = 0;
    if (position.y > GetScreenHeight() - playerImage.height)
        position.y = GetScreenHeight() - playerImage.height;
}
void Player::updatePosition(Vector2 newPosition)
{
    position = newPosition;
}
void Player::draw()
{
    DrawTexture(playerImage, position.x, position.y, WHITE);
}
