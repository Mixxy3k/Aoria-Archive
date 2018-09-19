#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "TextureMenager.hpp"
#include "consoleManager.h"
#include "JsonMenager.h"

class Engine {
public:
	const std::string version = "2.0";
#if _DEBUG
	const std::string DEBUG_VER = "1.1";
#endif
	void loadGame();
	void windowEventMenager();
	void runEngine();
	void runMenu();

	enum GameState { APP_ERROR, LOADING = 1, MENU, IN_GAME, };
	GameState *gameState = new GameState;
private:
#if _DEBUG
	ConsoleManager *consoleManager = new ConsoleManager(version, DEBUG_VER);
#else 
	ConsoleManager *consoleManager = new ConsoleManager(version);
#endif // _DEBUG

	sf::Vector2i windowResolution;
	sf::RenderWindow *window = new sf::RenderWindow;
	TextureMenager *textureMenager = new TextureMenager(consoleManager);
};