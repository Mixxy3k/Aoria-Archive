#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "TextureMenager.hpp"
#include "ConsoleMenager.h"

class Engine {
public:
	const std::string version = "2.0";
#if _DEBUG
	const std::string DEBUG_VER = "1";
#endif

	Engine();
	
	void windowEventMenager();
	void runEngine();
	void runMenu();
	void errorExit();
	//void 
	enum GameState { APP_ERROR, LOADING = 1, MENU, IN_GAME, };
	GameState *gameState = new GameState;
private:
#if _DEBUG
	ConsoleMenager *consoleMenager = new ConsoleMenager(version, DEBUG_VER);
#else 
	ConsoleMenager *consoleMenager = new ConsoleMenager(version);
#endif // _DEBUG

	sf::Vector2i windowResolution;
	sf::RenderWindow *window = new sf::RenderWindow;
	TextureMenager *textureMenager = new TextureMenager(consoleMenager);
};