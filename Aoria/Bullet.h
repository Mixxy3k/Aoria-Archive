#pragma once
#include <SFML\Graphics.hpp>
class Bullet {
public:
	enum Owner { Player = 0, SI = 1 };
	Owner owner;
	Bullet(sf::Texture &texture, sf::Vector2f &pos, Owner own);
	bool colision(sf::FloatRect &object);
	virtual void move() = 0;
	virtual bool deleteBullet() = 0;
	virtual void draw(sf::RenderWindow &win) const {
			win.draw(bulletSprite);
	}
protected:
	sf::Sprite bulletSprite;
	sf::Clock bulletClock;
	sf::Time time;
	bool playerBullet;
};