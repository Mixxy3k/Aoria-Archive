#include "Si.h"

void Si::generateVector()
{
	if (newMove == true) {
		//----------- Set time
		float a = (rand() % 5) + 1;
		timeToNewMove = 2.f / a;
		//----------- Attack Configuration
		float b = (rand() % 10) + 1;
		//----------- Set direction
		rotate = (rand() % 360);
		//----------- Restart Clock
		moobSprite.setRotation(rotate);
		moveClock.restart();
		newMove = false;
 	}
	if (newMove == false /*&& attackPlayer == true*/) {
		//---------- Set Move
		float vx = sin((rotate * M_PI) / 180.0f);

		float vy = -cos((rotate * M_PI) / 180.0f);
		moobSprite.move(sf::Vector2f(vx, vy)*5.f);
		// ---------- Orgins of move
		if (moobSprite.getPosition().x <= 0) {
			rotate = 90;
			moobSprite.setRotation(rotate);
		}
		if (moobSprite.getPosition().x >= 1024) {
			rotate = 270;
			moobSprite.setRotation(rotate);
		}
		if (moobSprite.getPosition().y <= 0) {
			rotate = 180;
			moobSprite.setRotation(rotate);
		}
		if (moobSprite.getPosition().y >= 512 / 1.5) {
			rotate = 0;
			moobSprite.setRotation(rotate);
		}
		
	}
	if (moveClock.getElapsedTime().asSeconds() >= timeToNewMove) {
		newMove = true;
	}
}

void Si::attack(sf::Vector2f &pPos)
{
	newMove = false;
	attackPlayer = true;
	if (newMove == false && attackPlayer == true) {
		sf::Vector2f mPos = moobSprite.getPosition();
		// mPos A                                              pPos B
		float Y = ((mPos.y - pPos.y) / (mPos.x - pPos.x)*mPos.x) + ((mPos.y - ((mPos.y - pPos.y) / (mPos.x - pPos.x)))*mPos.x);
		moobSprite.move(sf::Vector2f(mPos.x, Y));
		std::cout << "Y = " << Y << std::endl;
	}
}
