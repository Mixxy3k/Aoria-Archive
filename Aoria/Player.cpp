#include "Player.h"

Player::Player(sf::Texture & texture)
{
	playerSprite.setTexture(texture);
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getGlobalBounds().width/2, playerSprite.getGlobalBounds().height/2));
	playerSprite.setPosition(300, 300);
}

void Player::move(float X, float Y)
{
	playerSprite.move(sf::Vector2f(X,Y) * 5.f);
}

bool Player::bulletCoolDown()
{
	time = bulletClock.getElapsedTime();
	if (time.asSeconds() >= cd) {
		bulletClock.restart();
		return true;
	}
	return false;
}
