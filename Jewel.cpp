#include <string.h>
#include <iostream>
#include "Jewel.h"

using namespace std;

Jewel::Jewel(int x, int y, char symbol) : Moving(x, y, symbol)
{
}

Jewel::Jewel(char symbol) : Moving(symbol)
{
}