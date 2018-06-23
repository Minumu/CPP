#pragma once

#include <iostream>
#include "Ship.hpp"

class Player : public Ship {
public:
	Player();
	~Player();
	Player( Player const & src);

	Player & operator=(Player const & rhs);
	unsigned int getLives() const;
	void setLives(unsigned int);
	unsigned int getScore() const;
	void setScore(unsigned int);

private:
	unsigned int _lives;
	unsigned int _score;
};