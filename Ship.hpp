#pragma once

#include <iostream>
#include <ncurses.h>

class Ship {
public:
	Ship();
	Ship(int, int, std::string);
	~Ship();
	Ship( Ship const & src);

	Ship & operator=(Ship const & rhs);
	void shipMoved(int, int, const char*);

	int getHp() const;
	void setHp(int);
	int getSize() const;
	
private:
	int _hp;
	int _size;
	std::string _who;
};