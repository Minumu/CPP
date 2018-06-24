#include "Moves.hpp"

Moves::Moves() { }

Moves::Moves(Moves const & src) {
    *this = src;
}

Moves::~Moves() { }

Moves & Moves::operator=(Moves const & rhs) {
    return *this;
}

void Moves::crashChecking(int sy, int sx, int y, int x) {
    if ((sy == y && sx == x) || (sy == y && sx + 1 == x) || (sy == y && sx - 1 == x)) {
        nodelay(stdscr, true);
        endwin();
        std::cout << "Game over" << std::endl;
        exit(0);
    }
}

void Moves::playerMoves(unsigned int &sy, unsigned int &sx, Player player, Bullet *arrBullet[40], bool &space) {
    int ch;

    ch = getch();
    mvprintw(sy, sx, " ");
    if (ch == 'a') {
        if (sx - 1 > 0) {
            player.shipMoved(sy, sx - 2, "}");
            sx = (sx - 2);
        } else {
            player.shipMoved(sy, sx, "}");
        }
    } else if (ch == 'd') {
        if (sx + 1 < gMapX) {
            player.shipMoved(sy, sx + 2, "}");
            sx = (sx + 2);
        } else {
            player.shipMoved(sy, sx, "}");
        }
    } else if (ch == 'w') {
        if (sy - 1 > 0) {
            player.shipMoved(sy - 1, sx, "}");
            sy = (sy - 1);
        } else {
            player.shipMoved(sy, sx, "}");
        }
    } else if (ch == 's') {
        if (sy + 1 < gMapY) {
            player.shipMoved(sy + 1, sx, "}");
            sy = (sy + 1);
        } else {
            player.shipMoved(sy, sx, "}");
        }
    } else if (ch == ' ') {
        space = true;
    } else if (ch == 'q') {
        endwin();
        std::cout << "Game over" << std::endl;
        exit(0);
    } else {
        player.shipMoved(sy, sx, "}");
    }
    return;

}

void    Moves::enemyMoves(unsigned int &sy, unsigned int &sx, Bullet *arrBullet[40])
{
    int range = gMapY - 1;
    int sleep = 0;
    bool space = false;
    Player player = Player("}");
    Enemy enemy = Enemy();
    int x = gMapX - 2;
    int randNumberEnemies = rand() % 5 + 3;
    int arr[] = {std::rand() % range +1, std::rand() % range +1, std::rand() % range +1, std::rand() % range +1, std::rand() % range +1};
    const char *arrS[] = {"*", "$", "#", "X", "W"};
    while (x > 0) {
        playerMoves(sy, sx, player, &arrBullet[40], space);
        for (int idx = 0; idx < 40; ++idx) {
            if (arrBullet[idx] == NULL && space) {
                arrBullet[idx] = new Bullet;
                arrBullet[idx]->setY(sy);
                arrBullet[idx]->setX(sx + 1);
                space = false;
//            } else if (arrBullet[idx] != NULL) {
//                mvprintw(arrBullet[idx]->getY(), arrBullet[idx]->getX() - 1, " ");
//                player.shipMoved(arrBullet[idx]->getY(), arrBullet[idx]->getX(), "-");
//                if (arrBullet[idx]->getX() + 1 < gMapX)
//                    arrBullet[idx]->setX(arrBullet[idx]->getX() + 1);
//                else {
//                    mvprintw(arrBullet[idx]->getY(), arrBullet[idx]->getX(), " ");
//                    arrBullet[idx] = NULL;
//                }
            }
        }
        for (int h = 0; h < randNumberEnemies; h++) {
            mvprintw(arr[h], x + 1, " ");
        }
        for (int h = 0; h < randNumberEnemies; h++) {
            crashChecking(sy, sx, arr[h], x);
            enemy.shipMoved(arr[h], x, arrS[h]);
        }
        if (sleep == 700) {
            for (int h = 0; h < randNumberEnemies; h++) {
                mvprintw(arr[h], x, " ");
            }
            for (int idx = 0; idx < 40; ++idx) {
               if (arrBullet[idx] != NULL) {
                   mvprintw(arrBullet[idx]->getY(), arrBullet[idx]->getX() - 1, " ");
                   player.shipMoved(arrBullet[idx]->getY(), arrBullet[idx]->getX(), "-");
                   if (arrBullet[idx]->getX() + 1 < gMapX)
                       arrBullet[idx]->setX(arrBullet[idx]->getX() + 1);
                   else {
                       mvprintw(arrBullet[idx]->getY(), arrBullet[idx]->getX(), " ");
                       arrBullet[idx] = NULL;
                   }
               }
            }
            x--;
            sleep = 0;
        }
//        usleep(50000);
        sleep++;
    }
}