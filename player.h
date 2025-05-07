#ifndef player_h
#define player_h

#include "raylib.h"
#include "ball.h"
#include <iostream>
#include <string>

using namespace std;
class Player
{
    string type;
    Texture2D playerImage;
    Vector2 position;
    int speed;
    double groundResistance;
    int controlsKey[4];
    Vector2 direction; // direction of player
    int kickKey;       // key to kick the ball
    int kickPower;     // power of kick
public:
    Player(string type)
    {
        this->type = type;
        Image temp;
        if (type == "blue")
        {
            temp = LoadImage("images/playerBlue.png");
            controlsKey[0] = KEY_W; // up
            controlsKey[1] = KEY_S; // down
            controlsKey[2] = KEY_A; // left
            controlsKey[3] = KEY_D; // right
            kickKey = KEY_SPACE;    // kick key
            direction = {1.0, 0.0}; // default direction is right
        }
        else
        {
            temp = LoadImage("images/playerRed.png");
            controlsKey[0] = KEY_UP;    // up
            controlsKey[1] = KEY_DOWN;  // down
            controlsKey[2] = KEY_LEFT;  // left
            controlsKey[3] = KEY_RIGHT; // right
            kickKey = KEY_ENTER;        // kick key
            direction = {-1.0, 0.0};    // default direction is left
        }

        kickPower = 30; // default kick power
        playerImage = LoadTextureFromImage(temp);
        position = {0.0, 0.0};
        speed = 0;
        groundResistance = 5;
    }
    Vector2 getDirection();
    Vector2 getPosition();
    Texture2D getPlayerImage();
    void setSpeed(int);
    void update(int, int);
    void updatePosition(Vector2);
    void draw();
    void setPosition(Vector2);
    ~Player()
    {
        UnloadTexture(playerImage);
    }
    friend class Ball; // allow Ball class to access private members of Player class
};
#endif