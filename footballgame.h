#ifndef footballgame_h
#define footballgame_h
#include "raylib.h"
#include "ball.h"
#include "background.h"
#include "player.h"
#include "goalie.h"
#include <iostream>
#include <string>

using namespace std;
class FootballGame
{
    const float SCREEN_WIDTH = 1500;
    const float SCREEN_HEIGHT = 800;
    const int horizontalLimit = 55;
    const int verticalLimit = 50;
    Background background;
    Sprite *entities[5];   // Array to hold player, goalie and ball objects
    int score[2] = {0, 0}; // Array to hold scores for each team
    int timeLimit = 2;    // Time limit for the game in seconds
    int timeElapsed = 0;   // Time elapsed in seconds
    void isGoaled();
    void resetPositons();

public:
    FootballGame() : background(SCREEN_WIDTH, SCREEN_HEIGHT)
    {
        SetTargetFPS(60);
        background.loadBackground(SCREEN_WIDTH, SCREEN_HEIGHT);
        entities[0] = new Player("blue");
        entities[1] = new Player("red");
        entities[2] = new Goalie("blue");
        entities[3] = new Goalie("red");
        entities[4] = new Ball();
        for (int i = 0; i < 2; i++)
        {
            ((Player *)entities[i])->setPosition({float(SCREEN_WIDTH / 2.0 - 100 + i * 200), float(SCREEN_HEIGHT / 2.0)});
            ((Player *)entities[i])->setSpeed(3);
        }
        ((Ball *)entities[4])->updatePosition({float(SCREEN_WIDTH / 2.0 - 7), float(SCREEN_HEIGHT / 2.0 - 7)});
        ((Goalie *)entities[2])->setPosition({80, float(SCREEN_HEIGHT / 2.0)});
        ((Goalie *)entities[3])->setPosition({float(SCREEN_WIDTH - 100), float(SCREEN_HEIGHT / 2.0)});
        ((Goalie *)entities[2])->setSpeed(1);
        ((Goalie *)entities[3])->setSpeed(1);
        ((Player *)entities[0])->setDirection({1.0, 0.0});  // default direction is right
        ((Player *)entities[1])->setDirection({-1.0, 0.0}); // default direction is left
        ((Goalie *)entities[2])->setDirection({0.0, 1.0});
        ((Goalie *)entities[3])->setDirection({0.0, -1.0}); // default direction is left
        ((Goalie *)entities[2])->setMinHeight(320);
        ((Goalie *)entities[2])->setMaxHeight(450);
        ((Goalie *)entities[3])->setMinHeight(320);
        ((Goalie *)entities[3])->setMaxHeight(450);
    }
    void simulateGame();
};
#endif