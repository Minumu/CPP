#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

#include <ncurses.h>
#include <iostream>

unsigned int const gMapX = 100;
unsigned int const gMapY = 50;

class Window {

public:
    Window(void);
    ~Window(void);

    Window & operator = (Window const & rhs);

    Window(Window const & cpy);
    void initNcurses(void);
    void drawBorders(void);
    void initColors(void);
};

#endif
