#include "Window.hpp"

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
    for (unsigned int i = 0; i < gMapX; i++)
    {
        for (unsigned int j = 0; j < gMapY; j++)
        {
            attron(COLOR_PAIR(30));
            mvprintw(i, j, "*");
            attroff(COLOR_PAIR(30));
        }
    }
}

void Window::drawBorders()
{
    unsigned int x;
    unsigned int y;
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
