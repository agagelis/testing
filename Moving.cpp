#include <string.h>
#include <iostream>
#include "Moving.h"
#include "GameMap.h"

using namespace std;

Moving::Moving(int x, int y, char symbol)
{
    this->x = x;
    this->y = y;
    this->symbol = symbol;
}
Moving::Moving(char symbol)
{
    this->x = 0;
    this->y = 0;
    this->symbol = symbol;
}
int Moving::getX()
{
    return x;
}
int Moving::getY()
{
    return y;
}
char Moving::getSymbol()
{
    return symbol;
}
void Moving::setX(int x)
{
    this->x = x;
}
void Moving::setY(int y)
{
    this->y = y;
}