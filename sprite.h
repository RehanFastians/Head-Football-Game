#ifndef sprite_h
#define sprite_h

#include "raylib.h"
#include <iostream>
#include <iostream>
#include <string>
using namespace std;
class Sprite
{
protected:
    string type; // team type
    Texture2D playerImage; // Image of the sprite
    Vector2 position;      // Position of the sprite
    int speed;             // Speed of the sprite
    Vector2 direction;     // Direction of the sprite
public:
    Sprite()
    {
        position = {0.0, 0.0};
        speed = 0;
    }
    Vector2 getDirection();
    Vector2 getPosition();
    Texture2D getPlayerImage();
    void setSpeed(int);
    void updatePosition(Vector2);
    void draw();
    void setPosition(Vector2);
};

#endif