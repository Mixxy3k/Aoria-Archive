#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, sf::Vector2f &pos, Owner own, int bdmg, int LT)
{
	bulletSprite.setTexture(texture);
	bulletSprite.setPosition(pos);
	bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	owner = own;
	dmg = bdmg;
	lifeTime = LT;
}

bool Bullet::colision(sf::FloatRect &object)
{
	sf::FloatRect bulletRect = bulletSprite.getGlobalBounds();
	if (bulletRect.intersects(object)) {
		return true;
	}
	return false;
}

bool Bullet::deleteBullet()
{
	time = bulletClock.getElapsedTime();
	if (time.asSeconds() >= lifeTime || off == true) {
		return true;
	}
	return false;
}
