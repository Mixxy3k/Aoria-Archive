#pragma once
#include "Si.h"

class BlueMoob : public Si {
public:
	BlueMoob(sf::Texture &texture)
		:Si(texture)
	{
		dmg = 2;
		hp = 2;
	}
	virtual bool timer();
};