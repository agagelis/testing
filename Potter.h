#ifndef Potter_h
#define Potter_h

#include <string>
#include "Moving.h"

using namespace std;

class Potter : public Moving
{

public:
    Potter(int x, int y, char symbol);
    Potter(char symbol);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void notMove();
    virtual DIRECTION calculateNextposition();
};

#endif