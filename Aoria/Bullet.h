#pragma once
#include <SFML\Graphics.hpp>
class Bullet{
public:
	Bullet(sf::Texture &texture, sf::Vector2f &pos);
	bool colision(sf::FloatRect &object);
	virtual void move() = 0;
		virtual void draw(sf::RenderWindow &win) const {
			win.draw(bulletSprite);
	}
protected:
	sf::Sprite bulletSprite;
	sf::Clock bulletClock;
	sf::Time time;
	bool playerBullet;
};