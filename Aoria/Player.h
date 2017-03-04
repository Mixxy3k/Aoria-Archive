#pragma once
#include <SFML\Graphics.hpp>
class Player : public sf::Drawable {
public:
	Player(sf::Texture &texture);
	void move(float X, float Y);
	sf::Vector2f getPlaerPosition() {
		return playerSprite.getPosition();
	}
	bool bulletCoolDown();
	float getHp() {
		return hp;
	}
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(playerSprite, states);
	}
	sf::Sprite playerSprite;
	sf::Clock bulletClock;
	float cd = 1.f;
	sf::Time time;

	int hp = 100;
	float Speed = 200.f;
	std::string name = "[]";
};