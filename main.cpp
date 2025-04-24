#include <iostream>
#include "raylib.h"
#include "ball.h"
#include "background.h"

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
    football.updatePosition({SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0});

    while (WindowShouldClose() == false)
    {

        BeginDrawing();
        ClearBackground(WHITE);
        background.loadBackground(SCREEN_WIDTH, SCREEN_HEIGHT);
        football.draw();
        EndDrawing();
    }

    CloseWindow();
}