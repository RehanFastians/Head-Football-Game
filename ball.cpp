#include "ball.h"
#include "player.h"
#include <iostream>
#include "raylib.h"
using namespace std;

Vector2 Ball ::getPosition()
{
    return position;
}

void Ball ::draw()
{
    DrawTextureV(ballImage, position, WHITE);
}

void Ball ::setSpeed(int speed)
{
    this->speed = speed;
}

void Ball ::updatePosition(Vector2 pos)
{
    position.x = pos.x;
    position.y = pos.y;
}

void Ball ::checkPlayerCollision(Player *player1, Player *player2)
{
    if (CheckCollisionRecs({position.x, position.y, float(ballImage.width), float(ballImage.height)}, {player1->getPosition().x, player1->getPosition().y, float(player1->getPlayerImage().width), float(player1->getPlayerImage().height)}))
    {
        player = player1;
    }
    else if (CheckCollisionRecs({position.x, position.y, float(ballImage.width), float(ballImage.height)}, {player2->getPosition().x, player2->getPosition().y, float(player2->getPlayerImage().width), float(player2->getPlayerImage().height)}))
    {
        player = player2;
    }
    else
        player = nullptr; // reset player if no collision
}

bool Ball ::isKicked()
{
    if (player != nullptr)
    {
        if (IsKeyDown(player->kickKey))
        {
            return true;
        }
    }
    return false;
}
void Ball::update(Player *player1, Player *player2, int horizontalLimit, int verticalLimit)
{
    checkPlayerCollision(player1, player2);

    if (isKicked())
    {
        if (player)
        {
            speed = player->kickPower;
        }
        player = nullptr; // Reset player after kick
    }

    if (player)
    {
        // Ball is attached to the player
        if (!isKicked())
        {
            // Place the ball in front of the player
            if (player->getDirection().x == 0 || player->getDirection().y == 0 || (player->getDirection().x == 1 && player->getDirection().y == 1))
            {
                position.x = player->getPosition().x + player->getDirection().x * 20 + 5; // Adjust offset as needed
                position.y = player->getPosition().y + player->getDirection().y * 20 + 5; // Adjust offset as needed
            }
            else
            {
                position.x = player->getPosition().x + player->getDirection().x * 10 + 5; // Adjust offset as needed
                position.y = player->getPosition().y + player->getDirection().y * 10 + 5; // Adjust offset as needed
            }
        }

        // Update direction based on player's direction
        direction = player->getDirection();
    }
    else
    {
        // Ball is not attached to any player
        speed -= groundResistance;
        if (speed < 0)
            speed = 0; // Prevent negative speed
    }

    // Update ball position based on direction and speed
    float diagonalSpeed = speed / 1.414f; // Approximation of 1/sqrt(2) for diagonal movement
    if (direction.x == 1 && direction.y == 0)
    {
        position.x += speed;
    }
    else if (direction.x == -1 && direction.y == 0)
    {
        position.x -= speed;
    }
    else if (direction.x == 0 && direction.y == 1)
    {
        position.y += speed;
    }
    else if (direction.x == 0 && direction.y == -1)
    {
        position.y -= speed;
    }
    else if (direction.x == -1 && direction.y == -1)
    {
        position.x -= diagonalSpeed;
        position.y -= diagonalSpeed;
    }
    else if (direction.x == -1 && direction.y == 1)
    {
        position.x -= diagonalSpeed;
        position.y += diagonalSpeed;
    }
    else if (direction.x == 1 && direction.y == -1)
    {
        position.x += diagonalSpeed;
        position.y -= diagonalSpeed;
    }
    else if (direction.x == 1 && direction.y == 1)
    {
        position.x += diagonalSpeed;
        position.y += diagonalSpeed;
    }

    // Ensure position stays within screen bounds
    if (position.x < horizontalLimit)
        position.x = horizontalLimit;
    if (position.x > GetScreenWidth() - ballImage.width - horizontalLimit)
        position.x = GetScreenWidth() - ballImage.width - horizontalLimit;
    if (position.y < verticalLimit)
        position.y = verticalLimit;
    if (position.y > GetScreenHeight() - ballImage.height - verticalLimit)
        position.y = GetScreenHeight() - ballImage.height - verticalLimit;
}