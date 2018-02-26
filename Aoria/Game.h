#pragma once
#include <SFML\Graphics.hpp>
#include "Engine.h"
#include "TextureMenager.h"
class Game {
public:
	Game();
	void runGame();

protected:
	enum GameState{MENU, GAME, GAME_OVER, END};
	GameState gameState;

	float width = 1024;
	float height = 512;

private:
	sf::RenderWindow* window = new sf::RenderWindow();

	void initEngine();
	void menu();

	TextureMenager* textureMenager = new TextureMenager();

};