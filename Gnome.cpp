#include <string.h>
#include <iostream>
#include "Gnome.h"
#include "Moving.h"

using namespace std;

Gnome::Gnome(int x,int y,char symbol) : Monster(x,y,symbol)
{

}

Gnome::Gnome(char symbol) : Monster(symbol)
{

}
void Gnome:: move()
{
    
}

Moving::DIRECTION Gnome::calculateNextposition()
{
        int dir = rand() % 4;
    DIRECTION moveTo = DIRECTION::DOWN;
    switch (dir)
    {
    case 0:
        moveTo = DIRECTION::UP;
       // x--;
        break;
    case 1:
        moveTo = DIRECTION::DOWN;
        //x++;
        break;
    case 2:
        moveTo = DIRECTION::LEFT;
        //y--;
        break;
    case 3:
        moveTo = DIRECTION::RIGHT;
        //y++;
        break;
    default:
        break;
    }
    return moveTo;
}
