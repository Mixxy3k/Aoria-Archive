#include "Laser.h"

Laser::Laser(sf::Texture & texture, sf::Vector2f & pos,int dmg)
	:Bullet(texture, pos, SI, dmg)
{
	bulletClock.restart();
}

void Laser::move()
{
	bulletSprite.move(sf::Vector2f(0, 1) * speed);
}


