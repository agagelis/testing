#ifndef Engine_h
#define Engine_h

#include <string>
#include <vector>
#include <fstream>
#include "GameMap.h"

using namespace std;

class Engine
{
private:
    GameMap *map;
    Potter *potter;
    Gnome *gnome;
    Traal *traal;
    int numJewels;
    int result;
    
    void init_nCurses();
    void showMenu();
    void showScore();
    void updateScreen();
    int play();
    void updateScoreBoard();

public:
    void firstOption();
    Engine(string mapFilePath);
    void startGame();
	void showWin();
	void showLose();
	void putColor1();
	void putColor2();
	void putColor3();
	void putColor4();
};

#endif
