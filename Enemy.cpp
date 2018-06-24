#include "Enemy.hpp"

	Enemy::Enemy() { }

	Enemy::~Enemy() { }

	Enemy::Enemy(Enemy const & src) {
		*this = src;
	}

	Enemy & Enemy::operator=(Enemy const & rhs) {
		_isAlive = rhs.getStatus();
		return *this;
	}

	bool Enemy::getStatus() const {
		return _isAlive;
	}