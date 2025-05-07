#ifndef ball_h
#define ball_h
#include "raylib.h"
#include "player.h"
using namespace std;
class Player; // forward declaration of Player class
class Ball
{
    Texture2D ballImage;
    Vector2 position;
    int speed;
    int groundResistance;
    Vector2 direction;        // direction of ball
    Player *player = nullptr; // player who kicked the ball
    void checkPlayerCollision(Player *, Player *);
    bool isKicked();
public:
    Ball()
    {
        Image temp = LoadImage("images/football.png");
        ImageResize(&temp, 20, 20);
        ballImage = LoadTextureFromImage(temp);
        position = {0.0, 0.0};
        speed = 0;
        groundResistance = 2;
        direction = {0.0, 0.0};
    }
    Vector2 getPosition();
    void setSpeed(int);
    void update(Player *, Player *);
    void updatePosition(Vector2);
    void draw();
};

#endif