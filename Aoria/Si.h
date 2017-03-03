#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
# define M_PI          3.141592653589793238462643383279502884L /* pi */

class Si {
public:
	Si(sf::Texture &texture);
protected:
	int id = 0;
	int posX = 0;
	int posY = 0;
	
	int rotate = 0;
	float speed = 7.f;
	int hp = 1;
	float timeToNewMove;
	float attackTime = 4.f;
	sf::Clock moveClock;
	bool newMove = true;
	sf::Sprite moobSprite;

	enum Vector{UP,DOWN,LEFT,RIGHT,STAY};
	Vector vector;
public:
	int dmg = 0;
	virtual void draw(sf::RenderWindow &window) const {
		window.draw(moobSprite);
	}
	void generateVector();
	void attack();
	sf::FloatRect getMoobRect() {
		return moobSprite.getGlobalBounds();
	}
	void substractHP(int substract){
		hp = hp - substract;
	}
	int getHp() {
		std::cout << hp << std::endl;
		return hp;
	}
};