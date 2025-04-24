#include "background.h"
#include "raylib.h"
#include <iostream>
using namespace std;

void Background ::loadBackground(const float screenWidth, const float screenHeight)
{
    DrawTexture(stadium, 0, 0, WHITE);
    // DrawTexturePro(stadium, Rectangle{0.0, 0.0, (float)stadium.width, (float)stadium.height}, Rectangle{0.0, 0.0, (float)screenWidth, (float)screenHeight}, Vector2{0.0, 0.0}, 0.0, WHITE);
}