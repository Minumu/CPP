#include "Player.hpp"

	Player::Player() : Ship() {
		setScore(0);
		setColor(10);
	}

	Player::Player(const char* name) : Ship(1, 3, name) {
		setScore(0);
		setColor(10);
		setLives(3);
	}

	Player::~Player() { }

	Player::Player(Player const & src) {
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

short Player::getColor() const {
	return _color;
}

void Player::setColor( short color) {
	_color = color;
}