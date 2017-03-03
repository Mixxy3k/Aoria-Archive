#pragma once
#include "Bullet.h"
class KineticBullet : public Bullet {
public:
	KineticBullet(sf::Texture &texture, sf::Vector2f &pos);
	virtual void move();
private:
	float speed = 2.f;
};