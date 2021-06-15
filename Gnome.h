#ifndef Gnome_h
#define Gnome_h

#include <string>
#include "Monster.h"

using namespace std;

class Gnome : public Monster
{

public:
  Gnome(int x, int y, char symbol);
  Gnome(char symbol);
  void move();
  virtual DIRECTION calculateNextposition();
};

#endif
