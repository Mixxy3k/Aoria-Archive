#include "Kinetic.h"

KineticBullet::KineticBullet(sf::Texture &texture, sf::Vector2f &pos,int dmg)
	:Bullet(texture, pos, Player,dmg)
{
	bulletClock.restart();
}

void KineticBullet::move()
{
	bulletSprite.move(sf::Vector2f(0,-1) * speed);
}

