#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "BlueMoob.h"
#include "FileMenager.h"
class Engine {
public:
	Engine(sf::RenderWindow &win, FileMenager &fm);
	void runEngine();
private:
	sf::RenderWindow *window;
	FileMenager *fileMenager;
	Player *player;
	Si *si;
	void draw();
	void updateLogic();
};