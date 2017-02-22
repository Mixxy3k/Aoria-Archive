#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
# define M_PI          3.141592653589793238462643383279502884L /* pi */

class Si : public sf::Drawable {
protected:
	int id = 0;
	int posX = 0;
	int posY = 0;
	
	int rotate = 0;
	float speed = 100.f;
	int hp = 1;
	float timeToNewMove;
	float attackTime = 4.f;
	sf::Clock moveClock;
	sf::Clock attackClock;
	bool newMove = true;
	bool attackPlayer;
	sf::Sprite moobSprite;

public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(moobSprite, states);
	}
	void generateVector();
	void attack(sf::Vector2f &pPos);
};