#include "Kinetic.h"

KineticBullet::KineticBullet(sf::Texture &texture, sf::Vector2f &pos)
	:Bullet(texture, pos, Player)
{
	bulletClock.restart();
}

void KineticBullet::move()
{
	bulletSprite.move(sf::Vector2f(0,-1) * speed);
}

bool KineticBullet::deleteBullet()
{
	time = bulletClock.getElapsedTime();
	if (time.asSeconds() >= 2.f) {
		return true;
	}
	return false;
}
