#ifndef background_h
#define background_h

#include "raylib.h"

class Background
{
    Texture2D stadium;
    Texture2D goalLeft;
    Texture2D goalRight;

public:
    Background(const float screenWidth, const float screenHeight)
    {
        Image temp = LoadImage("images/stadium.jpg");
        ImageResize(&temp, (int)screenWidth, (int)screenHeight);
        stadium = LoadTextureFromImage(temp);
        temp = LoadImage("images/goalLeft.png");
        ImageResize(&temp, 150, 200);
        goalLeft=LoadTextureFromImage(temp);
        temp = LoadImage("images/goalRight.png");
        ImageResize(&temp, 150, 200);
        goalRight=LoadTextureFromImage(temp);
    }
    void loadBackground(const float screenWidth, const float screenHeight);
};

#endif