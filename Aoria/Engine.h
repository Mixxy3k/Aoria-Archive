#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "TextureMenager.hpp"
#include "ConsoleMenager.h"

class Engine {
public:
	const std::string version = "2.0";
#if _DEBUG
	const std::string DEBUG_VER = "1.01";
#endif

	Engine();

	void runEngine();
	void runMenu(sf::Vector2i screnResolution);

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