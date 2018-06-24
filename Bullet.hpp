#ifndef BULLET_HPP
#define BULLET_HPP


class Bullet {

public:
    Bullet();
    ~Bullet();
    Bullet(Bullet const & src);

    Bullet & operator=(Bullet const & rhs);

    unsigned int y;
    unsigned int x;
    void setX(unsigned int);
    unsigned int getX() const;
    void setY(unsigned int);
    unsigned int getY() const;
};

#endif
