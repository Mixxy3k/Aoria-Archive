#pragma once
#include <SFML\Graphics.hpp>
class Player : public sf::Drawable {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(playerSprite, states);
	}
	sf::Sprite playerSprite;
	sf::Clock bulletClock;
	sf::Time time;

	float cd;
	int hp = 100;
	int dmg = 1;
	std::string name = "[]";

public:
	Player(sf::Texture &texture);
	void move(float X, float Y);
	bool bulletCoolDown();
	void resetBulltClock();

	std::string GetName() { return name; }
	sf::Vector2f getPlaerPosition() { return playerSprite.getPosition(); }
	int GetDmg() { return dmg; }
	int getHp() { return hp; }
	void setHp(int newHp) { hp = newHp; }
	void substarctHP(int dmg) { hp -= dmg; }
	sf::FloatRect getRect() { return playerSprite.getGlobalBounds(); }
};