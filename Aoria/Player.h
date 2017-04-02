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
	void resetBulltClock() {
		time = sf::Time::Zero;
		bulletClock.restart();
	}
	int getHp() {
		return hp;
	}
	void substarctHP(int dmg) {
		hp -= dmg;
	}
	sf::FloatRect getRect() {
		return playerSprite.getGlobalBounds();
	}
	int dmg = 1;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(playerSprite, states);
	}
	sf::Sprite playerSprite;
	sf::Clock bulletClock;
	sf::Time time;

	float cd;
	int hp = 100;
	float Speed = 290.f;
	std::string name = "[]";
};