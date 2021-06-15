#include "Engine.h"
#include "HiScore.h"
#include "HiScoreManager.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
// #include <time.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
  
  if (argc == 4)
  {
    cout << argc << endl;
    // for(int i= 0 ; i<argc;i++)
    // {
    // cout << argv[i] << endl;
    // }

    cout << "Map file: "<<argv[1] << endl<<endl;

    Engine engine(argv[1]);
    engine.startGame();

    HiScoreManager man;
    man.load(argv[2], argv[3]);

    

    man.writeToFile();

    endwin(); // Memory deallocation && End ncurses
  }
  else{
    cout<<"Dwse swsta orismata......"<<endl;
  }

  return 0;
}
