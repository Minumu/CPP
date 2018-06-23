#pragma once

#include <iostream>
#include "Ship.hpp"

class Enemy : public Ship {
public:
	Enemy();
	~Enemy();
	Enemy(Enemy const & src);

	Enemy & operator=(Enemy const & rhs);

};