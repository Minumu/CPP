#pragma once

#include <unistd.h>
#include "Window.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"


class Moves {
public:
    Moves();
    Moves(Moves const & src);
    ~Moves();
    Moves & operator=(Moves const & rhs);

    void crashChecking(int, int, int, int);
    void playerMoves(unsigned int &sy, unsigned int &sx, Player, Bullet*[], bool &);
    void enemyMoves(unsigned int &sy, unsigned int &sx, Bullet*[]);

};