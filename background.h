#ifndef background_h
#define background_h

#include "raylib.h"

class Background{
    Texture2D stadium;

    public:
    Background(const float screenWidth, const float screenHeight){
        Image temp=LoadImage("images/stadium.jpg");
        ImageResize(&temp, (int)screenWidth, (int)screenHeight);
        stadium=LoadTextureFromImage(temp);
        // stadium = LoadTexture("images/stadium.h");
    }
    void loadBackground(const float screenWidth, const float screenHeight);
};





#endif