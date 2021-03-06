#pragma once

#include <iostream>
#include "Ship.hpp"

class Player : public Ship {
public:
	Player();
	Player(const char*);
	~Player();
	Player( Player const & src);

	Player & operator=(Player const & rhs);
	unsigned int getLives() const;
	void setLives(unsigned int);
	unsigned int getScore() const;
	void setScore(unsigned int);
	short getColor() const;
	void setColor(short);


private:
	unsigned int _lives;
	unsigned int _score;
	short _color;
};