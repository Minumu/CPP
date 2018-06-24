#include "Player.hpp"

	Player::Player() { 
		setScore(0);
	}

	Player::Player(const char* name) : Ship(1, 5, name) {

	}


	Player::~Player() { }

	Player::Player( Player const & src) {
		*this = src;
	}

	Player & Player::operator=(Player const & rhs) {
		_score = rhs.getScore();
		_lives = rhs.getLives();

		return *this;
	}

	unsigned int Player::getLives() const {
		return _lives;
	}

	void Player::setLives(unsigned int lives) {
		_lives = lives;
	}

	unsigned int Player::getScore() const {
		return _score;
	}

	void Player::setScore(unsigned int score) {
		_score = score;
	}
