#ifndef Jewel_h
#define Jewel_h

#include <string>
#include "Moving.h"

using namespace std;

class Jewel : public Moving
{

public:
    Jewel(int x, int y, char symbol);
    Jewel(char symbol);
};

#endif