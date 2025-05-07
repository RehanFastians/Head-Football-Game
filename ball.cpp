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

// void Ball::update(Player *player1, Player *player2)
// {
//     checkPlayerCollision(player1, player2);

//     if (isKicked())
//     {
//         if (player)
//         {
//             speed = player->kickPower;
//         }
//         if (player != nullptr)
//         {
//             player = nullptr; // reset player after kick
//         }
//     }

//     if (player)
//     {
//         // Ball is attached to the player
//         if (!isKicked())
//         {
//         // Place the ball in front of the player
//         position.x = player->getPosition().x + player->getDirection().x * 20; // Adjust offset as needed
//         position.y = player->getPosition().y + player->getDirection().y * 20; // Adjust offset as needed
//         }
//         direction = player->getDirection(); // Get player's direction
//         player->speed = this->speed; // Set player's speed to ball's speed
//         // Update direction based on player's direction
//         if (player->getDirection().x == 1 && player->getDirection().y == 0)
//         {
//             direction = {1.0, 0.0}; // right
//         }
//         else if (player->getDirection().x == -1 && player->getDirection().y == 0)
//         {
//             direction = {-1.0, 0.0}; // left
//         }
//         else if (player->getDirection().x == 0 && player->getDirection().y == 1)
//         {
//             direction = {0.0, 1.0}; // down
//         }
//         else if (player->getDirection().x == 0 && player->getDirection().y == -1)
//         {
//             direction = {0.0, -1.0}; // up
//         }
//         else if (player->getDirection().x == -1 && player->getDirection().y == -1)
//         {
//             direction = {-1.0, -1.0}; // up left
//         }
//         else if (player->getDirection().x == -1 && player->getDirection().y == 1)
//         {
//             direction = {-1.0, 1.0}; // down left
//         }
//         else if (player->getDirection().x == 1 && player->getDirection().y == -1)
//         {
//             direction = {1.0, -1.0}; // up right
//         }
//         else if (player->getDirection().x == 1 && player->getDirection().y == 1)
//         {
//             direction = {1.0, 1.0}; // down right
//         }
//     }
//     else
//     {
//         // Ball is not attached to any player
//         speed -= groundResistance;
//     }

//     // Update ball position based on direction and speed
//     if (direction.x == 1 && direction.y == 0)
//     {
//         position.x += speed;
//     }
//     else if (direction.x == -1 && direction.y == 0)
//     {
//         position.x -= speed;
//     }
//     else if (direction.x == 0 && direction.y == 1)
//     {
//         position.y += speed;
//     }
//     else if (direction.x == 0 && direction.y == -1)
//     {
//         position.y -= speed;
//     }
//     else if (direction.x == -1 && direction.y == -1)
//     {
//         position.x -= speed / 2;
//         position.y -= speed / 2;
//     }
//     else if (direction.x == -1 && direction.y == 1)
//     {
//         position.x -= speed / 2;
//         position.y += speed / 2;
//     }
//     else if (direction.x == 1 && direction.y == -1)
//     {
//         position.x += speed / 2;
//         position.y -= speed / 2;
//     }
//     else if (direction.x == 1 && direction.y == 1)
//     {
//         position.x += speed / 2;
//         position.y += speed / 2;
//     }

//     // Ensure position stays within screen bounds
//     if (position.x < 0)
//         position.x = 0;
//     if (position.x > GetScreenWidth() - ballImage.width)
//         position.x = GetScreenWidth() - ballImage.width;
//     if (position.y < 0)
//         position.y = 0;
//     if (position.y > GetScreenHeight() - ballImage.height)
//         position.y = GetScreenHeight() - ballImage.height;
// }
void Ball::update(Player *player1, Player *player2)
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
            position.x = player->getPosition().x + player->getDirection().x * 20; // Adjust offset as needed
            position.y = player->getPosition().y + player->getDirection().y * 20; // Adjust offset as needed
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
    if (position.x < 0)
        position.x = 0;
    if (position.x > GetScreenWidth() - ballImage.width)
        position.x = GetScreenWidth() - ballImage.width;
    if (position.y < 0)
        position.y = 0;
    if (position.y > GetScreenHeight() - ballImage.height)
        position.y = GetScreenHeight() - ballImage.height;
}