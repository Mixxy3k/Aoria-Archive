#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, sf::Vector2f &pos, Owner own)
{
	bulletSprite.setTexture(texture);
	bulletSprite.setPosition(pos);
	bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	owner = own;
}

bool Bullet::colision(sf::FloatRect &object)
{
	sf::FloatRect bulletRect = bulletSprite.getGlobalBounds();
	if (bulletRect.intersects(object)) {
		return true;
	}
	return false;
}