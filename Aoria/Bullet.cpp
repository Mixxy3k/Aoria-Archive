#include "Bullet.h"

Bullet::Bullet(int ID, sf::Texture &texture, sf::Vector2f &position, int damage, int lifeTime, float speed)
{
	this->destroyBullet = false;

	this->bulletSprite.setTexture(texture);
	this->bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	this->bulletSprite.setPosition(position);

	this->ID = ID;
	this->damage = damage;
	this->lifeTime = lifeTime;

	this->speed = speed;
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
	if (time.asSeconds() >= this->lifeTime || this->destroyBullet) {
		return true;
	}
	return false;
}
