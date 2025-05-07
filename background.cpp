#include "background.h"
#include "raylib.h"
#include <iostream>
using namespace std;

void Background ::loadBackground(const float screenWidth, const float screenHeight)
{
    DrawTexture(stadium, 0, 0, WHITE);
    DrawTexture(goalLeft, 0, 335, WHITE);
    DrawTexture(goalRight, screenWidth - 80, 335, WHITE);
}