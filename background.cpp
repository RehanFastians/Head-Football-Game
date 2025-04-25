#include "background.h"
#include "raylib.h"
#include <iostream>
using namespace std;

void Background ::loadBackground(const float screenWidth, const float screenHeight)
{
    DrawTexture(stadium, 0, 0, WHITE);
    DrawTexture(goalLeft, 80, screenHeight-300, WHITE);
    DrawTexture(goalRight, screenWidth - 200, screenHeight - 300, WHITE);
}