#include "goalie.h"
#include "raylib.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

int Goalie::setMinHeight(int minHeight)
{
    this->minHeight = minHeight;
    return minHeight;
}
int Goalie::setMaxHeight(int maxHeight)
{
    this->maxHeight = maxHeight;
    return maxHeight;
}
void Goalie::update(int horizontalLimit, int verticalLimit)
{
    if(direction.y==1){
        position.y+=speed;
    }else if(direction.y==-1){
        position.y-=speed;
    }
    if(position.y<minHeight){
        position.y=minHeight;
        direction.y=1;
    }else if(position.y>maxHeight){
        position.y=maxHeight;
        direction.y=-1;
    }
}
