#include <string.h>
#include <iostream>
#include "Potter.h"

using namespace std;

Potter::Potter(int x, int y, char symbol) : Moving(x, y, symbol)
{
}
Potter::Potter(char symbol) : Moving(symbol)
{
}
void Potter::moveUp()
{
    x--;
}
void Potter::moveDown()
{
    x++;
}
void Potter::moveRight()
{
    starty++;
}
void Potter::moveLeft()
{
    y--;
}
void Potter::notMove()
{
}

Moving::DIRECTION Potter::calculateNextposition()
{
    
    return DIRECTION::DOWN;
}