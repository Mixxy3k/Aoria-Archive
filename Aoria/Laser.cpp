#include "Laser.h"

Laser::Laser(sf::Texture & texture, sf::Vector2f & pos)
	:Bullet(texture, pos, SI)
{
	bulletClock.restart();
}

void Laser::move()
{
	bulletSprite.move(sf::Vector2f(0, 1) * speed);
}

bool Laser::deleteBullet()
{
	time = bulletClock.getElapsedTime();
	if (time.asSeconds() >= 2.f) {
		return true;
	}
	return false;
}

