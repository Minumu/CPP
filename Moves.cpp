#include "Moves.hpp"

Moves::Moves() { }

Moves::Moves(Moves const & src) {
    *this = src;
}

Moves::~Moves() { }

Moves & Moves::operator=(Moves const & rhs) {
    (void)rhs;
    return *this;
}

bool Moves::crashChecking(int sy, int sx, int y, int x, Player &player) {
    if ((sy == y && sx == x) || (sy == y && sx + 1 == x) || (sy == y && sx - 1 == x)) {
        player.setLives(player.getLives() - 1);

        refresh();
        if (player.getLives() == 0) {
            nodelay(stdscr, true);
            endwin();
            std::cout << "Game over" << std::endl;
            exit(0);
        }
        return (true);
    }
    return (false);
}

void Moves::playerMoves(unsigned int &sy, unsigned int &sx, Player player, bool &space) {
    int ch;

    ch = getch();

    if (ch == 'a') {
        if (sx - 1 > 0) {
            mvprintw(sy, sx, " ");
            player.shipMoved(sy, sx - 2, "}", 10);
            sx = (sx - 2);
        } else {
            player.shipMoved(sy, sx, "}", 10);
        }
    } else if (ch == 'd') {
        if (sx + 1 < gMapX) {
            mvprintw(sy, sx, " ");
            player.shipMoved(sy, sx + 2, "}", 10);
            sx = (sx + 2);
        } else {
            player.shipMoved(sy, sx, "}", 10);
        }
    } else if (ch == 'w') {
        if (sy - 1 > 0) {
            mvprintw(sy, sx, " ");
            player.shipMoved(sy - 1, sx, "}", 10);
            sy = (sy - 1);
        } else {
            player.shipMoved(sy, sx, "}", 10);
        }
    } else if (ch == 's') {
        if (sy + 1 < gMapY) {
            mvprintw(sy, sx, " ");
            player.shipMoved(sy + 1, sx, "}", 10);
            sy = (sy + 1);
        } else {
            player.shipMoved(sy, sx, "}", 10);
        }
    } else if (ch == ' ') {
        space = true;
    } else if (ch == 'p') {
        while (getch() != 'p') {}
    } else if (ch == 'q') {
        endwin();
        std::cout << "Game over" << std::endl;
        exit(0);
    } else {
        player.shipMoved(sy, sx, "}", 10);
    }
    return;

}

static void	navigation(Player &player)
{
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 5, gMapX + 8, "Score: %d ", player.getScore());
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 7, gMapX + 8, "Lives: %d ", player.getLives());
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 15, gMapX + 8, "Up: w");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 17, gMapX + 8, "Down: s");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 19, gMapX + 8, "Left: a");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 21, gMapX + 8, "Right: d");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 23, gMapX + 8, "Shoot: space");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(4));
    mvwprintw(stdscr, 25, gMapX + 8, "Pause: p");
    attroff(COLOR_PAIR(4));
}

void    Moves::enemyMoves(unsigned int &sy, unsigned int &sx, Bullet * arrBullet, Player &player)
{
    int range = gMapY - 1;
    bool space = false;
    Enemy enemy = Enemy();
    unsigned int x = gMapX - 2;
    int randNumberEnemies = rand() % 5 + 3;
    int arr[] = {std::rand() % range +1, std::rand() % range +1, std::rand() % range +1, std::rand() % range +1, std::rand() % range +1};
    const char *arrS[] = {"*", "$", "#", "X", "W"};
    while (x > 0) {
        navigation(player);
        playerMoves(sy, sx, player, space);
         for (int idx = 0; idx < 40; ++idx) {
             if (arrBullet[idx].getX() == 200 && space) {
                 arrBullet[idx].setY(sy);
                 arrBullet[idx].setX(sx + 1);
                 space = false;
             } else if (arrBullet[idx].getX() != 200) {
                 mvprintw(arrBullet[idx].getY(), arrBullet[idx].getX() - 1, " ");
                 player.shipMoved(arrBullet[idx].getY(), arrBullet[idx].getX(), "-", 10);
                 if (arrBullet[idx].getX() + 1 < gMapX) {
                     for (int h = 0; h < randNumberEnemies; h++) {
                         if ((arrBullet[idx].getX() == x || arrBullet[idx].getX() == x - 1) && arrBullet[idx].getY() == (unsigned int)arr[h]) {
                             player.setScore(player.getScore() + 10);
                             mvprintw(arr[h], x, " ");
                             arr[h] = -1;
                             refresh();
                         }
                     }
                     arrBullet[idx].setX(arrBullet[idx].getX() + 1);
                 }
                 else {
                     mvprintw(arrBullet[idx].getY(), arrBullet[idx].getX(), " ");
                     arrBullet[idx].setX(200);
                 }
             }
         }
        for (int h = 0; h < randNumberEnemies; h++) {
            if (arr[h] == -1) {

            } else {
               if (crashChecking(sy, sx, arr[h], x, player)) {
                   mvprintw(arr[h], x + 1, " ");

                   arr[h] = -1;
               } else {
                   mvprintw(arr[h], x + 1, " ");
                   if (x > 1)
                       enemy.shipMoved(arr[h], x, arrS[h], 30);
               }
            }
        }
        usleep(25000);
        x--;
    }
}