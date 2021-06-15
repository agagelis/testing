#ifndef Monster_h
#define Monster_h

#include <string>
#include <vector>
#include "Moving.h"

using namespace std;

class Monster : public Moving
{
private:

public:
    Monster(int x,int y,char symbol);
    Monster(char symbol);
    virtual void move() = 0;
};

#endif