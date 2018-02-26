#pragma once
#include "Bullet.h"
class KineticBullet : public Bullet 
{
public:
	KineticBullet(int ID, sf::Texture &texture, sf::Vector2f &position)
		: Bullet(ID, texture, position, 2, 8.f, 10.f) {}

	virtual void move() { this->bulletSprite.move(sf::Vector2f(0, -1) * this->speed); };
};