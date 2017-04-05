#pragma once
#include <SFML\Graphics.hpp>
class Bullet {
public:
	enum Owner { Player = 0, SI = 1 };
	Owner owner;
	Bullet(sf::Texture &texture, sf::Vector2f &pos, Owner own, int dmg, int LT = 2.f);
	bool colision(sf::FloatRect &object);
	virtual void move() = 0;
	bool deleteBullet();
	virtual void draw(sf::RenderWindow &win) const {
			win.draw(bulletSprite);
	}
	int dmg;
	bool off = false;
protected:
	int lifeTime;
	sf::Sprite bulletSprite;
	sf::Clock bulletClock;
	sf::Time time;
	bool playerBullet;
};