#ifndef ball_h
#define ball_h
#include "raylib.h"
#include "player.h"
#include "sprite.h"
#include <iostream>
using namespace std;
class Player;              // forward declaration of Player class
class Ball : public Sprite // Inherit from Sprite class
{
    int groundResistance;
    Player *player = nullptr; // player who kicked the ball
    void checkPlayerCollision(Player *, Player *);
    bool isKicked();

public:
    Ball()
    {
        Image temp = LoadImage("images/football.png");
        ImageResize(&temp, 20, 20);
        spriteImage = LoadTextureFromImage(temp);
        position = {0.0, 0.0};
        speed = 0;
        groundResistance = 2;
        direction = {0.0, 0.0};
    }
    void update(Player *, Player *, int, int);
    void update(int, int) {}
};

#endif