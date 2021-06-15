#include <string.h>
#include <iostream>
#include "Traal.h"
#include "GameMap.h"
#include "Moving.h"

using namespace std;

Traal::Traal(int x, int y, char symbol) : Monster(x, y, symbol)
{
}

Traal::Traal(char symbol) : Monster(symbol)
{
}

void Traal::move()
{
}

Moving::DIRECTION Traal::calculateNextposition()
{
        int dir = rand() % 4;
    DIRECTION moveTo = DIRECTION::DOWN;
    switch (dir)
    {
    case 0:
        moveTo = DIRECTION::UP;
       // x--;
        break;
    case 1:
        moveTo = DIRECTION::DOWN;
        //x++;
        break;
    case 2:
        moveTo = DIRECTION::LEFT;
        //y--;
        break;
    case 3:
        moveTo = DIRECTION::RIGHT;
        //y++;
        break;
    default:
        break;
    }
    return moveTo;
    // int rows = map->getRows();
    // int columns = map->getColumns();

    // int **mapOfWeights = new int *[rows];
    // for (size_t i = 0; i < rows; ++i)
    //     mapOfWeights[i] = new int[columns];

    // for (size_t i = 0; i < rows; ++i)
    // {
    //     for (size_t j = 0; j < columns; ++j)
    //     {
    //         mapOfWeights[i][j] = 0;
    //     }
    // }
    // int potterX = map->getPotter()->getX();
    // int potterY = map->getPotter()->getY();
    // int xTest, yTest;

    // // checkUp
    // xTest = potterX - 1;
    // yTest = potterY;

    // if (xTest >= 0)
    // {
    //     mapOfWeights[xTest][yTest]++;
    // }
    // else
    // {
    //     //exw vggei ektos oriwn pros ta panw
    // }

    // //checkDown
    // xTest = potterX + 1;
    // yTest = potterY;

    // if (xTest <= rows)
    // {
    //     mapOfWeights[xTest][yTest]++;
    // }
    // else
    // {
    //     //exw vggei ektos oriwn pros ta katw
    // }

    // //checkLeft
    // xTest = potterX;
    // yTest = potterY - 1;

    // if (yTest >= 0)
    // {
    //     mapOfWeights[xTest][yTest]++;
    // }
    // else
    // {
    //     //exw vggei ektos oriwn pros ta aristera
    // }
    // //checkRight
    // xTest = potterX;
    // yTest = potterY + 1;

    // if (yTest <= columns)
    // {
    //     mapOfWeights[xTest][yTest]++;
    // }
    // else
    // {
    //     //exw vggei ektos oriwn pros ta deksia
    // }

    // // deleting array
    // for (size_t i = 0; i < rows; ++i)
    //     delete mapOfWeights[i];

    // delete mapOfWeights;


}