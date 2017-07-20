#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "Player.h"
#include "BlueMoob.h"
#include "FileMenager.h"
#include "Kinetic.h"
#include "InfoTab.h"
#include "Lvl.h"
#include "Laser.h"
#include "SaveSystem.h"

class Engine {
public:
	Engine(sf::RenderWindow &win, FileMenager &fm);
	void runEngine();
private:
	bool goMenu = false;

	sf::RenderWindow *window;	
	FileMenager *fileMenager;
	InfoBar * rightInfoBar;
	InfoBar * leftInfoBar;
	Save * saveSystem;

	Lvl *lvl;

	Player *player;

	typedef std::vector <Bullet *> bullet;
	std::vector <Si *> moob;
	bullet allBullet;

	void draw();
	void updateLogic();

	const float FPS = 100.f;
};