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
	void shipMoved(int, int, const char*, short);

	int getHp() const;
	void setHp(int);
	int getSize() const;
	
private:
    int _size;
	int _hp;
	std::string _who;
};