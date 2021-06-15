#include <string.h>
#include <iostream>
#include "GameMap.h"
#include <time.h>
#include <ncurses.h>
using namespace std;

GameMap::GameMap(Potter *potter, Gnome *gnome, Traal *traal)
{
    this->potter = potter;
    this->gnome = gnome;
    this->traal = traal;

    papyrusIsVisible = false;

    // srand(time(NULL));
    srand(10);
}
void GameMap::load(string harths)
{
    char buffer[256];
    fstream xarths(harths);
    if (!xarths.is_open())
    {
        // cout << "Error opening file";
        exit(1);
    }

    char ch;
    int row = 0;
    int column = 0;
    vector<char> *rowVector;
    rowVector = new vector<char>();
    while (xarths.get(ch))
    {
        // cout << "(" << row << "," << column << ")" << endl;
        if (ch == '\n')
        {
            this->columns = column;

            row++;
            this->rows = row;
            column = 0;
            map.push_back(*rowVector);
            rowVector = new vector<char>();
        }
        else
        {
            rowVector->push_back(ch);
            column++;
        }
    }
    // cout << "r: " << rows << endl;
    // cout << "c: " << columns << endl;
    this->rows = row;
}
void GameMap::print()
{
    // cout << "Size: " << map.size() << "*" << map[0].size() << endl;
    // erase();
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            mvaddch(i, j, map[i][j]);
            // cout << map[i][j];
        }
        // cout << endl;
    }
}

void GameMap::setStartPosition()
{
    int px, py;
    //put Potter on map in random position
    do
    {
        px = getRandom_X();
        py = getRandom_Y();
    } while (map[px][py] != ' ');
    // cout <<endl<<"potter address: "<<potter<< endl;
    map[px][py] = potter->getSymbol();
    potter->setX(px);
    potter->setY(py);
    // cout << "Put p in " << px << "," << py << endl;

    //put Gnome on map in random position
    do
    {
        px = getRandom_X();
        py = getRandom_Y();
    } while (map[px][py] != ' ');

    map[px][py] = gnome->getSymbol();
    gnome->setX(px);
    gnome->setY(py);
    // cout << "Put G in " << px << "," << py << gnome->getSymbol() << endl;
    //this->print();
    //put Traal on map in random position
    do
    {
        px = getRandom_X();
        py = getRandom_Y();
    } while (map[px][py] != ' ');

    map[px][py] = traal->getSymbol();
    traal->setX(px);
    traal->setY(py);
    // cout << "Put tr in " << px << "," << py << endl;
    //this->print();

    //put jewel on map
    for (int i = 0; i < 3; i++)
    {
        do
        {
            px = getRandom_X();
            py = getRandom_Y();
        } while (map[px][py] != ' ');
        map[px][py] = '+';
    }
}

int GameMap::getRandom_X()
{
    return rand() % this->rows;
}

int GameMap::getRandom_Y()
{
    return rand() % this->columns;
}

int GameMap::getRows()
{
    return rows;
}
int GameMap::getColumns()
{
    return columns;
}

void GameMap::moveTo(Moving *moving, int x, int y)
{
    map[moving->getX()][moving->getY()] = ' ';
    mvaddch(moving->getX(), moving->getY(), map[moving->getX()][moving->getY()]);

    moving->setX(x);
    moving->setY(y);

    map[x][y] = moving->getSymbol();
    mvaddch(x, y, moving->getSymbol());
}

bool GameMap::isWall(int x, int y)
{
    // mvprintw(12, 65, "is wall: %c %d",map[x][y],map[x][y] == '*');
    return map[x][y] == '*';
}
bool GameMap::isJewel(int x, int y)
{
    // mvprintw(13, 65, "is Jewel: %c %d",map[x][y],map[x][y] == '+');
    return map[x][y] == '+';
}
bool GameMap::isGnome(int x, int y)
{

    return map[x][y] == 'G';
}
bool GameMap::isTraal(int x, int y)
{
    return map[x][y] == 'T';
}
bool GameMap::isPapyrus(int x, int y)
{
    return map[x][y] == '#';
}
bool GameMap::isPotter(int x, int y)
{
    return map[x][y] == 'P';
}
void GameMap::showPapyrus()
{
    papyrusX = getRandom_X();
    papyrusY = getRandom_Y();
    while (map[papyrusX][papyrusY] != ' ')
    {
        papyrusX = getRandom_X();
        papyrusY = getRandom_Y();
    }
    mvprintw(11, 65, "Take the Papyrus '#' to win!!");
    map[papyrusX][papyrusY] = '#';
    papyrusIsVisible = true;
    mvaddch(papyrusX, papyrusY, map[papyrusX][papyrusY]);
}

void GameMap::removePapyrus()
{
    if (papyrusIsVisible)
    {
        papyrusIsVisible = false;
        map[papyrusX][papyrusY] = ' ';
    }
}

void GameMap::deletePositions()
{
    map[traal->getX()][traal->getY()] = ' ';
    traal->setX(0);
    traal->setY(0);
    map[potter->getX()][potter->getY()] = ' ';
    potter->setX(0);
    potter->setY(0);
    map[gnome->getX()][gnome->getY()] = ' ';
    gnome->setX(0);
    gnome->setY(0);
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == '+')
            {
                map[i][j] = ' ';
            }
        }
    }
    removePapyrus();
}

char GameMap::get(int x, int y)
{
    char xar = map[x][y];
    return xar;
}