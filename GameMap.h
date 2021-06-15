#ifndef GameMap_h
#define GameMap_h

#include <string>
#include <vector>
#include <fstream>
#include "Potter.h"
#include "Gnome.h"
#include "Traal.h"
#include "Jewel.h"

using namespace std;

class GameMap
{
private:
    vector<vector<char>> map;
    Potter *potter;
    Gnome *gnome;
    Traal *traal;
    Jewel *jewel;
    int columns;
    int rows;
    int papyrusX;
    int papyrusY;
    bool papyrusIsVisible;

    int getRandom_X();
    int getRandom_Y();

public:
    GameMap(Potter *potter,Gnome *gnome,Traal *traal);
    void load(string harths);
    void print();
    //bool isPositionEmpty(int x, int y);
    void setStartPosition();
    //void nextPosition();
    int getRows();
    int getColumns();
    void moveTo(Moving * moving , int x, int y);
    bool isWall(int x, int y);
    bool isJewel(int x, int y);
	bool isPapyrus(int x, int y);
	bool isGnome(int x, int y);
	bool isTraal(int x, int y);
	bool isPotter(int x, int y);
	void showPapyrus();
    void removePapyrus();
	void deletePositions();
    char get(int x,int y);


    //Potter* getPotter();
};

#endif

