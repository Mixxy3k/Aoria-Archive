#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "Player.h"
#include "BlueMoob.h"
#include "FileMenager.h"
#include "Kinetic.h"

class Engine {
public:
	Engine(sf::RenderWindow &win, FileMenager &fm);
	void runEngine();
private:
	sf::RenderWindow *window;	
	FileMenager *fileMenager;

	Player *player;

	typedef std::vector <Bullet *> bullet;
	std::vector <Si *> moob;
	bullet playerBullet;

	void draw();
	void updateLogic();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};