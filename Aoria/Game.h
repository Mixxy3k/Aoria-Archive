#pragma once
#include <SFML\Graphics.hpp>
#include "Engine.h"
#include "FileMenager.h"
class Game {
public:
	Game();
	void runGame();

protected:
	enum GameState{MENU, GAME, GAME_OVER, END};
	GameState gameState;

	int width = 1024;
	int height = 512;

private:
	sf::RenderWindow window;

	void initEngine();
	void menu();

	FileMenager fileMenager;

};