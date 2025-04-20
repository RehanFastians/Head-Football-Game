#ifndef ball_h
#define ball_h
#include "raylib.h"
using namespace std;

class Ball
{
    Texture2D ballImage;
    Vector2 position;
    Vector2 speed;
    double gravity;
    double airResistance;
    public:
    Ball(){
        ballImage= LoadTexture("images\football.png");
        position={0, 0};
        speed = {0,0};
        gravity = 10;
        airResistance=7;
    } 
    Vector2 getPosition();
    void setSpeed(Vector2);
    void update();
    void updatePosition(Vector2);
};

#endif