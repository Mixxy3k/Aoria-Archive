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

class Engine {
public:
	Engine(sf::RenderWindow &win, FileMenager &fm);
	void runEngine();
private:
	sf::RenderWindow *window;	
	FileMenager *fileMenager;
	InfoBar * infoBar;
	Lvl *lvl;

	Player *player;

	enum owners{PL=1,SI=0};

	typedef std::vector <Bullet *> bullet;
	std::vector <Si *> moob;
	bullet allBullet;

	void draw();
	void updateLogic();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};