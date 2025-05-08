#ifndef goalie_h
#define goalie_h
#include "raylib.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

class Goalie : public Sprite
{
    int minHeight;
    int maxHeight;

public:
    Goalie(string type)
    {
        Image temp = LoadImage("images/goalKeeper.png");
        if (type == "blue")
        {        
            direction = {0.0, 1.0};
            ImageRotate(&temp, 0.0f);
        }
        else
        {
            direction = {0.0, -1.0};
            ImageRotate(&temp, 180.0f);
        }
        playerImage = LoadTextureFromImage(temp);
        speed = 1;
    }
    int setMinHeight(int);
    int setMaxHeight(int);
    void update(int, int);
};

#endif