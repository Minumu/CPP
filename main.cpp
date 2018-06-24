#include <ncurses.h>
#include <iostream>
#include "Moves.hpp"

void settings() {
    unsigned int sx = 5;
    unsigned int sy = 5;
    Window window;
    Bullet *arrBullet[40];
    Player player = Player("}");

    Moves moves = Moves();
    nodelay(stdscr, true);
    srand(time(NULL));
    refresh();
    while (1) {
        moves.enemyMoves(sy, sx, &arrBullet[40], player);
    }
}

int main() {
    settings();
    return 0;
}