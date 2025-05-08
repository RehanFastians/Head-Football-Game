#include "footballgame.h"
#include "raylib.h"
#include "ball.h"
#include "background.h"
#include "player.h"
#include "goalie.h"
#include <iostream>
#include <string>
using namespace std;

void FootballGame::simulateGame()
{
    // Initialize player and goalie positions
    ((Player *)entities[0])->setPosition({float(SCREEN_WIDTH / 2.0 - 100), float(SCREEN_HEIGHT / 2.0)});
    ((Player *)entities[1])->setPosition({float(SCREEN_WIDTH / 2.0 + 100), float(SCREEN_HEIGHT / 2.0)});
    ((Goalie *)entities[2])->setPosition({80, float(SCREEN_HEIGHT / 2.0)});
    ((Goalie *)entities[3])->setPosition({float(SCREEN_WIDTH - 100), float(SCREEN_HEIGHT / 2.0)});
    ((Ball *)entities[4])->updatePosition({float(SCREEN_WIDTH / 2.0 - 7), float(SCREEN_HEIGHT / 2.0 - 7)});

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        background.loadBackground(SCREEN_WIDTH, SCREEN_HEIGHT);
        entities[0]->update(horizontalLimit, verticalLimit);                                                         // Update player 1
        entities[1]->update(horizontalLimit, verticalLimit);                                                         // Update player 2
        ((Ball *)entities[4])->update((Player *)entities[0], (Player *)entities[1], horizontalLimit, verticalLimit); // Update ball position based on player positions
        ((Goalie *)entities[2])->update((Ball *)entities[4], horizontalLimit, verticalLimit);                        // Update goalie 1 position based on ball position
        ((Goalie *)entities[3])->update((Ball *)entities[4], horizontalLimit, verticalLimit);                        // Update goalie 2 position based on ball position
        // Draw Entities
        for (int i = 0; i < 5; i++)
        {
            entities[i]->draw();
        }

        EndDrawing();
    }
}