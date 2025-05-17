#include <iostream>
#include "raylib.h"
#include "ball.h"
#include "background.h"
#include "player.h"
#include "goalie.h"
#include "footballgame.h"
using namespace std;
int main()
{
    // Initialize the game
    const float SCREEN_WIDTH = 1500;
    const float SCREEN_HEIGHT = 800;
    try
    {

        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Football Game");
        InitAudioDevice(); // Initialize audio device
        FootballGame game;
        game.simulateGame();
    }
    catch (const std::exception &e)
    {
        cerr << "Unhandled exception: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "An unknown error occurred." << endl;
    }

    return 0;
}