#include <string.h>
#include <iostream>
#include "Engine.h"
#include "Moving.h"
#include <chrono>
#include <thread>
#include <ncurses.h>
#define WIN 1
#define LOOSE 2
#define BACK_TO_MAIN_MENU 0
#define EXIT 3

using namespace std;

Engine::Engine(string mapFilePath)
{
    potter = new Potter('P');
    gnome = new Gnome('G');
    traal = new Traal('T');
    map = new GameMap(potter, gnome, traal);
    map->load(mapFilePath);
    result = BACK_TO_MAIN_MENU;
    init_nCurses();
}

void Engine::showMenu()
{
    erase();
    putColor1();
    mvprintw(0, 0, "           Babis Poteridhs and the final challenge          ");
    mvprintw(1, 0, "          *****************************************         ");
    mvprintw(2, 0, "        ||             WELCOME   TO                ||         ");
    mvprintw(3, 0, "        ||              M . E . I.                 ||         ");
    mvprintw(4, 0, "          *****************************************        ");
    mvprintw(5, 0, "        =============================================         ");
    mvprintw(6, 0, "        The monsters Gnome(G) and Traal(T) are trying    ");
    mvprintw(7, 0, "        to catch you.Collect all the gems and then the   ");
    mvprintw(8, 0, "        magic parchment will be appear.         ");
    mvprintw(9, 0, "        You are Babis Poteridhs(P).             ");
    mvprintw(10, 0, "                        MAIN MENU:       ");
    mvprintw(11, 0, "        1--> Play the game        ");
    mvprintw(12, 0, "        2--> View the ScoreBoard        ");
    mvprintw(13, 0, "        3--> Quit       ");
    mvprintw(14, 0, "        Please select an option:       ");
    refresh();
}

void Engine::startGame()
{
    bool run = true;
    char c;
    result = BACK_TO_MAIN_MENU;

    while (result != EXIT)
    {
        numJewels = 0;
        if (result == BACK_TO_MAIN_MENU)
        {
            showMenu();
        }
        else if (result == LOOSE)
        {
            showLose();
        }
        else if (result == WIN)
        {
            showWin();
        }

        c = getch();
        switch (c)
        {
        case '1':
            result = play();
            break;
        case '2':
            showScore();
            break;
        case '3':
            result = EXIT;
            break;
        }
    }
}
void Engine::showScore()
{
}

void Engine::updateScoreBoard()
{
    mvprintw(1, 65, "  ScoreBoard  ");
    mvprintw(2, 65, "--------------");
    mvprintw(3, 65, " Jewels-->");
    mvprintw(3, 75, "%d", numJewels);
    mvprintw(3, 76, "   ");
    mvprintw(4, 65, " Points-->");
    mvprintw(4, 75, "%d", numJewels * 10);
    if (numJewels > 0)
    {
        mvprintw(4, 76, "  ");
    }
    else
    {
        mvprintw(4, 76, "   ");
    }

    mvprintw(7, 65, "Press 1 for menu  ");
    mvprintw(8, 65, "Press 2 for exit  ");
    mvprintw(map->getRows() + 1, 20, "  Map  ");
}
int Engine::play()
{
    int d;
    erase();
    putColor4();

    bool run = true;
    bool papyrusIsVisible = false;

    map->deletePositions();
    map->setStartPosition();
    map->print();

    while (run)
    {
        updateScoreBoard();
        //move potter
        int px = potter->getX();
        int py = potter->getY();
        keypad(stdscr, TRUE);
        d = getch();
        switch (d)
        {
        case KEY_UP:
            px--;
            break;
        case KEY_DOWN:
            px++;
            break;
        case KEY_RIGHT:
            py++;
            break;
        case KEY_LEFT:
            py--;
            break;
        case '1':
            return BACK_TO_MAIN_MENU;
        case '2':
            return EXIT;
        }
        // mvprintw(12, 65, "%d,%d: %c %d",px,py,map->get(px,py),map->isJewel(px, py));

        if (map->isJewel(px, py) == true)
        {
            // mvprintw(12, 65, "%d,%d: %c %d",px,py,map->get(px,py),map->isJewel(px, py));
            numJewels++;
            map->moveTo(potter, px, py);
        }
        else if (map->isGnome(px, py) || map->isTraal(px, py))
        {
            return LOOSE;
            break;
        }
        else if (map->isPapyrus(px, py))
        {
            
            return WIN;
        }
        else if (!map->isWall(px, py))
        {
            map->moveTo(potter, px, py);
        }
        else
        {
            continue;
        }

        if (numJewels == 3 && !papyrusIsVisible)
        {
            map->showPapyrus();
            papyrusIsVisible = true;
        }

        // move Traal
        Moving::DIRECTION direction;
        while (true)
        {
            direction = traal->calculateNextposition();
            int x = traal->getX();
            int y = traal->getY();

            switch (direction)
            {
            case Moving::DIRECTION::DOWN:
                x++;
                break;
            case Moving::DIRECTION::UP:
                x--;
                break;
            case Moving::DIRECTION::LEFT:
                y--;
                break;
            case Moving::DIRECTION::RIGHT:
                y++;
                break;
            }
            if (map->isPotter(x, y))
            {
                return LOOSE;
            }
            else if (!map->isWall(x, y) && !map->isJewel(x, y) && !map->isGnome(x, y))
            {
                map->moveTo(traal, x, y);
                break;
            }
        }

        //move Gnome
        while (true)
        {
            direction = gnome->calculateNextposition();
            int gx = gnome->getX();
            int gy = gnome->getY();

            switch (direction)
            {
            case Moving::DIRECTION::DOWN:
                gx++;
                break;
            case Moving::DIRECTION::UP:
                gx--;
                break;
            case Moving::DIRECTION::LEFT:
                gy--;
                break;
            case Moving::DIRECTION::RIGHT:
                gy++;
                break;
            }
            if (map->isPotter(gx, gy))
            {
                return LOOSE;
            }
            else if (map->isTraal(gx, gy))
            {
                continue;
            }
            else if (!map->isWall(gx, gy) && !map->isJewel(gx, gy))
            {
                map->moveTo(gnome, gx, gy);
                break;
            }
        }
    }
    return BACK_TO_MAIN_MENU;
}

void Engine ::showWin()
{
    erase();
    putColor2();

    mvprintw(0, 0, "                    WO000000WWWWWWWWWW        ");
    mvprintw(1, 0, "          *****************************************         ");
    mvprintw(2, 0, "        ||              M . E . I.                 ||         ");
    mvprintw(3, 0, "          *****************************************        ");
    mvprintw(4, 0, "        =============================================         ");
    mvprintw(5, 0, "        YOU WON THE GAMEEEEE!!!    ");
    mvprintw(6, 0, "                         WIN   ");
    mvprintw(7, 0, "        	     WIN     WIN");
    mvprintw(8, 0, "        	  WIN           WIN");
    mvprintw(9, 0, "        	     WIN     WIN");
    mvprintw(10, 0, "                         WIN       ");
    mvprintw(11, 0, "        1--> Play new game        ");
    mvprintw(12, 0, "        2--> View the ScoreBoard        ");
    mvprintw(13, 0, "        3--> Quit       ");
}

void Engine ::showLose()
{
    erase();
    putColor3();

    mvprintw(0, 0, "                    OHHHH NOOOOOOOOOO        ");
    mvprintw(1, 0, "          *****************************************         ");
    mvprintw(2, 0, "        ||              M . E . I.                 ||         ");
    mvprintw(3, 0, "          *****************************************        ");
    mvprintw(4, 0, "        =============================================         ");
    mvprintw(5, 0, "        YOU LOSE THE GAMEEEEE!!!    ");
    mvprintw(6, 0, "                         LOSE   ");
    mvprintw(7, 0, "        	     LOSE     LOSE");
    mvprintw(8, 0, "        	  LOSE           LOSE");
    mvprintw(9, 0, "        	     LOSE     LOSE");
    mvprintw(10, 0, "                         LOSE       ");
    mvprintw(11, 0, "        1--> Play the game        ");
    mvprintw(12, 0, "        2--> View the ScoreBoard        ");
    mvprintw(13, 0, "        3--> Quit       ");
    // refresh();
    // getch();
    // char d = getch();
    // switch (d)
    // {
    // case '1':
    //     startGame();
    //     break;
    // case 'm':
    //     showMenu();
    //     break;
    // case 'e':
    //     break;
    // }
}

void Engine::init_nCurses()
{

    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

void Engine::putColor1()
{

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}

void Engine::putColor2()
{
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}
void Engine::putColor3()
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}
void Engine::putColor4()
{
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    attron(COLOR_PAIR(1));
}