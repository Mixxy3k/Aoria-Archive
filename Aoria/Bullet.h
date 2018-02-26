#pragma once
#include <SFML\Graphics.hpp>
class Bullet {
public:
	Bullet(int ID, sf::Texture &texture, sf::Vector2f &position, int damage, int lifeTime, float speed);

	bool colision(sf::FloatRect &object);
	bool deleteBullet();

	int getLifeTime() { return this->lifeTime; }
	int getDamage() { return this->damage; }
	int getID() { return this->ID; }

	virtual void move() = 0;
	virtual void draw(sf::RenderWindow *window) const { window->draw(bulletSprite); }

protected:
	bool destroyBullet;

	int ID;
	int damage;
	int lifeTime;

	float speed;

	sf::Sprite bulletSprite;
	sf::Clock bulletClock;
	sf::Time time;
};