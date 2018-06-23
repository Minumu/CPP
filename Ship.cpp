#include "Ship.hpp"

	Ship::Ship() {
		_size = 1;
		_hp = 5;
		_who = "}";
	}

	Ship::Ship(int size, int hp, std::string who) : _size(size), _hp(hp), _who(who) { }

	Ship::~Ship() { }

	Ship::Ship( Ship const & src) {
		*this = src;
	}

	Ship & Ship::operator=(Ship const & rhs) {
		_hp = rhs.getHp();
		_size = rhs.getSize();
		return (*this);
	}

	void Ship::shipMoved(int y, int x, const char *who) {
		mvprintw(y, x, who);
		refresh();
	}

	int Ship::getHp() const {
		return _hp;
	}

	void Ship::setHp(int hp) {
		_hp = hp;
	}

	int Ship::getSize() const {
		return _size;
	}