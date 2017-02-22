#pragma once
#include "Si.h"

class BlueMoob : public Si {
public:
	BlueMoob(sf::Texture &texture) {
		Si::moobSprite.setTexture(texture);
		Si::moobSprite.setPosition(500, 250);
		Si::moobSprite.setOrigin(Si::moobSprite.getGlobalBounds().width / 2, Si::moobSprite.getGlobalBounds().height / 2);
	}
};