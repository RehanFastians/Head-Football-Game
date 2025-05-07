#ifndef goalie_h
#define goalie_h
#include "raylib.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

class Goalie : private Player{
    int speed;
    Texture2D playerImage;
};





#endif