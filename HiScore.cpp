#include <string.h>
#include <iostream>
#include "HiScore.h"

using namespace std;

HiScore::HiScore(char *name, int score)
{
    setName(name);
    setScore(score);
}
char *HiScore::getName()
{
    return name;
}
int HiScore::getScore()
{
    return score;
}
void HiScore::setName(char *onoma)
{
    // int length = strlen(onoma);
    name = new char[11];
    memcpy(name, onoma, (10 * sizeof(char)));
    name[11] = '\0';
}
void HiScore::setScore(int score)
{
    this->score = score;
}