#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "TextureMenager.hpp"
#include "consoleManager.h"
#include "JsonManager.h"

class Engine {
public:
	Engine();
	~Engine();

	const std::string version;
	void loadGame();
	void windowEventMenager();
	void runEngine();
	void runMenu();

	enum GameState { APP_ERROR, LOADING = 1, MENU, IN_GAME, };
	GameState *gameState;

#if _DEBUG
	const std::string DEBUG_VER;
#endif
private:
	ConsoleManager *consoleManager;
	JsonMenager *jsonMenager;

	sf::Vector2i windowResolution;
	sf::RenderWindow *window;
	TextureMenager *textureMenager;
};