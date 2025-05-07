#include <iostream>
#include "raylib.h"
#include "ball.h"
#include "background.h"
#include "player.h"

using namespace std;

int main()
{
    const float SCREEN_WIDTH = 1500;
    const float SCREEN_HEIGHT = 800;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Head Football Game");
    SetTargetFPS(60);
    // Making object of Ball and initializing it
    Background background(SCREEN_WIDTH, SCREEN_HEIGHT);
    Ball football;
    Player player1("blue");
    Player player2("red");
    player1.setPosition({SCREEN_WIDTH / 2.0 - 100, SCREEN_HEIGHT / 2.0});
    player2.setPosition({SCREEN_WIDTH / 2.0 + 100, SCREEN_HEIGHT / 2.0});
    player1.setSpeed(5);
    player2.setSpeed(5);
    football.updatePosition({SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0});
    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);
        background.loadBackground(SCREEN_WIDTH, SCREEN_HEIGHT);
        player1.update();
        player2.update();
        football.draw();
        player1.draw();
        player2.draw();
        EndDrawing();
    }

    CloseWindow();
}