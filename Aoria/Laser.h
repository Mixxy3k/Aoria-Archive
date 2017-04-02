#pragma once
#include "Bullet.h"
class Laser: public Bullet {
public:
	Laser(sf::Texture &texture, sf::Vector2f &pos);
	virtual void move();
	virtual bool deleteBullet();
private:
	float speed = 12.f;
	//dmg = 4.f;
};