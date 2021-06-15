#ifndef HiScore_h
#define HiScore_h

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class HiScore
{
private:
    char *name;
    int score;

public:
    HiScore(char *name, int score);
    char *getName();
    int getScore();
    void setName(char *onoma);
    void setScore(int score);
};

#endif