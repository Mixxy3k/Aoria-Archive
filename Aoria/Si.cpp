#include "Si.h"

Si::Si(sf::Texture & texture)
{
	moobSprite.setTexture(texture);
	moobSprite.setPosition(500, 250);
	moobSprite.setOrigin(moobSprite.getGlobalBounds().width / 2, moobSprite.getGlobalBounds().height / 2);
}

void Si::generateVector()
{
	if (newMove == true) {
		//----------- Set time
		float a = (rand() % 5) + 1;
		timeToNewMove = 2.f / a;

		//----------- Draw position
		int b = (rand() % 3) + 1;
		switch (b)
		{
		case 1:
			vector = UP;
			break;
		case 2:
			vector = DOWN;
			break;
		case 3:
			vector = LEFT;
			break;
		case 4:
			vector = RIGHT;
		default:
			break;
		}

		//----------- Restart Clock
		moveClock.restart();

		//----------
		newMove = false;
 	}
	if (newMove == false) {
		// -------- Move a sprite
		switch (vector)
		{
		case UP:
			moobSprite.move(sf::Vector2f(0.f, -1.f) * speed);
			break;
		case DOWN:
			moobSprite.move(sf::Vector2f(0.f, 1.f) * speed);
			break;
		case LEFT:
			moobSprite.move(sf::Vector2f(-1.f, 0.f) * speed);
			break;
		case RIGHT:
			moobSprite.move(sf::Vector2f(1.f, 0.f) * speed);
		default:
			break;
		}
		// ---------- Orgins of move
		if (moobSprite.getPosition().x <= 0) {
			vector = RIGHT;
		}
		if (moobSprite.getPosition().x >= 1024) {
			vector = LEFT;
		}
		if (moobSprite.getPosition().y <= 0) {
			vector = DOWN;
		}
		if (moobSprite.getPosition().y >= 512 / 1.5) {
			vector = UP;
		}				
	}
	if (moveClock.getElapsedTime().asSeconds() >= timeToNewMove) {
		newMove = true;
	}
}

void Si::attack()
{
	// Here will be a Bullet System
}
