#ifndef Moving_h
#define Moving_h

#include <string>


using namespace std;

class GameMap;

class Moving
{
protected:
    int x;
    int y;
    char symbol;
    int startx;
    int starty;

public:
    enum DIRECTION
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Moving(int x, int y, char symbol);
    Moving(char symbol);
    int getX();
    int getY();
    char getSymbol();
    void setX(int x);
    void setY(int y);
    virtual DIRECTION calculateNextposition() = 0;
};

#endif
