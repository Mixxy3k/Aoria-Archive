#pragma once
#include <SFML\Graphics.hpp>
class Player: public sf::Drawable {
public:
	Player(sf::Texture &texture);
	void move(float X, float Y);
	sf::Vector2f getPlaerPosition() {
		return playerSprite.getPosition();
	}
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(playerSprite, states);
	}
	sf::Sprite playerSprite;
	struct Data
	{
		int hp = 100;
		float Speed = 200.f;
		std::string name = "[]";
	};
};