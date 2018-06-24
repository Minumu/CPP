#include "Bullet.hpp"


Bullet::Bullet() {
    setX(200);
    setY(200);
}

Bullet::~Bullet() {}

Bullet::Bullet( Bullet const & src) {
    *this = src;
}

Bullet & Bullet::operator=(Bullet const & rhs) {
    this->y = rhs.y;
    this->x = rhs.x;
    return *this;
}

void Bullet::setX(unsigned int sx) {
    this->x = sx;
}

unsigned int Bullet::getX() const {

    return this->x;
}

void Bullet::setY(unsigned int sy) {
    this->y = sy;
}

unsigned int Bullet::getY() const {
    return this->y;
}

