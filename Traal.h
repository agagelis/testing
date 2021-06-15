#ifndef Traal_h
#define Traal_h

#include <string>
#include "Monster.h"

using namespace std;

class GameMap;

class Traal : public Monster
{

public:
    Traal(int x, int y, char symbol);
    Traal(char symbol);
    void move();
    virtual DIRECTION calculateNextposition();
};

#endif