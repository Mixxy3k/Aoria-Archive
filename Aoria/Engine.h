#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "Bullet.h"
#include "Kinetic.h"
#include "Player.h"
#include "BlueMoob.h"
#include "TextureMenager.h"
#include "InfoTab.h"
#include "Lvl.h"
#include "SaveSystem.h"

class Engine {
public:
	Engine(sf::RenderWindow *window, TextureMenager *textureMenager);
	void runEngine();
private:
	bool goMenu = false;
	sf::RenderWindow *window;	
	TextureMenager *textureMenager;
	InfoBar * rightInfoBar;
	InfoBar * leftInfoBar;
	//Save * saveSystem;

	Lvl *lvl;

	Player *player;

	std::vector <Si *> moob;

	typedef std::vector <Bullet *> bullet;
	bullet bullets;

	void draw();
	void updateLogic();

	const float FPS = 100.f;
};