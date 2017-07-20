#include "Player.h"

Player::Player(sf::Texture & texture)
{
	playerSprite.setTexture(texture);
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getGlobalBounds().width/2, playerSprite.getGlobalBounds().height/2));
	playerSprite.setPosition(500, 430);
	cd = 0.3;
}

void Player::move(float X, float Y)
{
	playerSprite.move(sf::Vector2f(X,Y) * 5.f);
}

bool Player::bulletCoolDown()
{
	time = bulletClock.getElapsedTime();
	if (time.asSeconds() >= cd) {
		return true;
	}
	return false;
}

void Player::resetBulltClock() {
	time = sf::Time::Zero;
	bulletClock.restart();
}