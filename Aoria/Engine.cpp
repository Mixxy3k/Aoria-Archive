#include "Engine.h"

Engine::Engine(sf::RenderWindow & win, FileMenager &fm)
{
	window = &win;
	fileMenager = &fm;
	si = new BlueMoob(fileMenager->getRef("blueShip"));
	player = new Player(fileMenager->getRef("player"));
}
//----------- Main Loop of game ------------
void Engine::runEngine()
{
	while (window->isOpen()) {
		draw();
		updateLogic();
	}
}
//--------- Draw Graphic
void Engine::draw()
{
	window->clear();
	window->draw(*player);
	window->draw(*si);
	window->display();
}
//--------- Upate logic
void Engine::updateLogic()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		// Request for closing the window
		if (event.type == sf::Event::Closed)
			window->close();
		// The escape key was pressed
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window->close();
	}
	// -------------- Control Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(0, -1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(0, 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(1, 0);
	//------------- Si Move
	si->generateVector();
	//si->attack(player->getPlaerPosition());
}

