#include "Enemy.hpp"

	Enemy::Enemy() { }

	Enemy::~Enemy() { }

	Enemy::Enemy(Enemy const & src) {
		*this = src;
	}

	Enemy & Enemy::operator=(Enemy const & rhs) {
		return *this;
	}
