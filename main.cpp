#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include "Window.class.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

Window::Window() {
    initNcurses();
    initColors();
    drawBorders();
    //drawField();
}

Window::~Window() {
    nodelay(stdscr, FALSE);
    getch();
    endwin();
}

Window::Window(Window const & cpy)
{
    (void)cpy;
    return;
}

Window & Window::operator = (Window const & rhs)
{
    (void)rhs;
    return *this;
}

void Window::initNcurses()
{
    initscr();
    curs_set(0);
    noecho();
    refresh();
}

void Window::initColors()
{
    start_color();
    init_pair(1, 8, COLOR_BLACK);
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    init_pair(20, COLOR_BLUE, COLOR_BLACK);
    init_pair(30, COLOR_RED, COLOR_BLACK);
    init_pair(40, COLOR_CYAN, COLOR_BLACK);
    init_pair(11, COLOR_BLACK, COLOR_GREEN);
    init_pair(12, COLOR_BLACK, COLOR_BLUE);
    init_pair(13, COLOR_BLACK, COLOR_RED);
    init_pair(14, COLOR_BLACK, COLOR_CYAN);
    init_pair(15, COLOR_BLACK, 8);
    init_pair(2, 8, 8);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, 167, COLOR_BLACK);
    init_pair(5, 28, COLOR_BLACK);
    init_pair(6, 160, COLOR_BLACK);
}

void Window::drawField()
{
   for (int i = 0; i < gMapX; i++)
   {
       for (int j = 0; j < gMapY; j++)
       {
           attron(COLOR_PAIR(30));
           mvprintw(i, j, "*");
           attroff(COLOR_PAIR(30));
       }
   }
}

void Window::drawBorders()
{
    int x;
    int y;
    for (x = 0; x < gMapX; x++)
    {
        y = gMapY;
        mvprintw(y, x, "-");
        y = 0;
        mvprintw(y, x, "-");
    }
    for (y = 0; y < gMapY; y++)
    {
        x = gMapX;
        mvprintw(y, x, "|");
        x = 0;
        mvprintw(y, x, "|");
    }
}

void playerMoved(int &sy, int &sx, Ship ship) {
    int ch;

    ch = getch();
    mvprintw(sy, sx, " ");
    if (ch == 'a') {
        if (sx - 1 > 0) {
            ship.shipMoved(sy, sx - 1, "}");
            sx = (sx - 1);
        } else {
            ship.shipMoved(sy, sx, "}");
        }
    } else if (ch == 'd') {
        if (sx + 1 < gMapX) {
            ship.shipMoved(sy, sx + 1, "}");
            sx = (sx + 1);
        } else {
            ship.shipMoved(sy, sx, "}");
        }
    } else if (ch == 'w') {
        if (sy - 1 > 0) {
            ship.shipMoved(sy - 1, sx, "}");
            sy = (sy - 1);
        } else {
            ship.shipMoved(sy, sx, "}");
        }
    } else if (ch == 's') {
        if (sy + 1 < gMapY) {
            ship.shipMoved(sy + 1, sx, "}");
            sy = (sy + 1);
        } else {
            ship.shipMoved(sy, sx, "}");
        }
    } else if (ch == 'q') {
        endwin();
        std::cout << "Game over" << std::endl;
        exit(0);
    } else {
        ship.shipMoved(sy, sx, "}");
    }
    return;

}

void    enemyMoved(int &sy, int &sx, Ship ship)
{
    int range = gMapY - 1;
    int x = gMapX - 1;
    int arr[] = {std::rand() % range +1, std::rand() % range +1, std::rand() % range +1};
    while (x > 0) {
        playerMoved(sy, sx, ship);
        for (int h = 0; h < 3; h++) {
            ship.shipMoved(arr[h], x, "*");
        }
        for (int h = 0; h < 3; h++) {
            mvprintw(arr[h], x, " ");
        }
        usleep(50000);
        x--;
    }
}

int main(int argv, char** argc) {
    int x = gMapX - 1;
    int y, ch;
    int sx = 5;
    int sy = 5;

    Window window;

    Ship ship = Ship(1, 5, "}");
    timeout(1);
    srand(time(NULL));
    initscr();
    noecho();
    refresh();
    ship.shipMoved(sy, sx, "}");
    while (1) {
        enemyMoved(sy, sx, ship);
    }
    return 0;
}