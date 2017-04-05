#pragma once
#include "Bullet.h"
class Laser: public Bullet {
public:
	Laser(sf::Texture &texture, sf::Vector2f &pos,int dmg);
	virtual void move();
private:
	float speed = 5.f;
	//dmg = 4.f;
};