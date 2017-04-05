#pragma once
#include "Si.h"

class BlueMoob : public Si {
public:
	BlueMoob(sf::Texture &texture)
		:Si(texture)
	{
		dmg = 1;
		hp = 2;
		Si::speed = 3.f;
	}
	virtual bool timer();
};