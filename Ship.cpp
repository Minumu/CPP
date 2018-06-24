#include "Ship.hpp"

	Ship::Ship() {
		_size = 1;
		_hp = 3;
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

	void Ship::shipMoved(int y, int x, const char *who, short color) {
		wattron(stdscr, COLOR_PAIR(color));
		mvprintw(y, x, who);
		wattroff(stdscr, COLOR_PAIR(color));
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