#ifndef background_h
#define background_h

#include "raylib.h"

class Background
{
    Texture2D stadium;
    Texture2D goalLeft;
    Texture2D goalRight;

public:
    Background() {}
    Background(const float screenWidth, const float screenHeight)
    {
        Image temp = LoadImage("images/ground.jpg");
        ImageResize(&temp, (int)screenWidth, (int)screenHeight);
        stadium = LoadTextureFromImage(temp);
        temp = LoadImage("images/goalL.png");
        ImageResize(&temp, 80, 130);
        goalLeft = LoadTextureFromImage(temp);
        temp = LoadImage("images/goalR.png");
        ImageResize(&temp, 80, 130);
        goalRight = LoadTextureFromImage(temp);
        UnloadImage(temp); // Unload the image after loading the texture
    }
    ~Background()
    {
        UnloadTexture(stadium);
        UnloadTexture(goalLeft);
        UnloadTexture(goalRight);
    }
    void loadBackground(const float screenWidth, const float screenHeight);
};

#endif