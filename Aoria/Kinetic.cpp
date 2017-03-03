#include "Kinetic.h"

KineticBullet::KineticBullet(sf::Texture &texture, sf::Vector2f &pos)
	:Bullet(texture, pos)
{ }

void KineticBullet::move()
{
	bulletSprite.move(sf::Vector2f(1,0) * speed);
}
