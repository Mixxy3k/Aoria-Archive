#pragma once
#pragma once
#include "Bullet.h"
class KineticBullet : public Bullet
{
public:
	KineticBullet(int ID, sf::Texture &texture, sf::Vector2f &position, int damage, int lifeTime)
		: Bullet(ID, texture, position, damage, lifeTime, this->speed) {}

	virtual void move() { this->bulletSprite.move(sf::Vector2f(0, -1) * this->speed); };

private:

	float speed = 15.f;
};