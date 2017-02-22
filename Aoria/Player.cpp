#include "Player.h"

Player::Player(sf::Texture & texture)
{
	playerSprite.setTexture(texture);
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getGlobalBounds().width, playerSprite.getGlobalBounds().height));
	playerSprite.setPosition(300, 300);
}

void Player::move(float X, float Y)
{
	playerSprite.move(sf::Vector2f(X,Y) * 400.f / 120.f);
}
