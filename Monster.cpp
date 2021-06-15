#include <string>
#include <vector>
#include "Monster.h"
#include "Moving.h"

using namespace std;

Monster::Monster(int x,int y,char symbol) : Moving(x,y,symbol){

}

Monster::Monster(char symbol) : Moving(symbol){

}