#include "Engine.h"

Engine::Engine(sf::RenderWindow & win, FileMenager &fm)
{
	window = &win;
	fileMenager = &fm;
	moob.push_back(new BlueMoob(fileMenager->getRef("blueShip")));
	moob.push_back(new BlueMoob(fileMenager->getRef("blueShip")));
	player = new Player(fileMenager->getRef("player"));
}
//----------- Main Loop of game ------------
void Engine::runEngine()
{
	while (window->isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			updateLogic();
			timeSinceLastUpdate -= TimePerFrame;
			draw();

		}
	}
}
//--------- Draw Graphic
void Engine::draw()
{
	window->clear();
	window->draw(*player);
	for (auto obj : moob) {
		obj->draw(*window);
	}
	for (auto obj: playerBullet)
	{
		obj->draw(*window);
	}
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		playerBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"),player->getPlaerPosition()));
	}
	//------------- Si Move
	for (auto obj : moob) {
		obj->generateVector();
		obj->attack();
	}
	//------------ Bullet Move
	int i = 0;
	for (auto obj : playerBullet) {
		obj->move();
		for (int i = 0; i < moob.size(); i++){
			if (obj->colision(moob[i]->getMoobRect())) {
				std::cout << "Col" << std::endl;
				moob[i]->substractHP(moob[i]->dmg);
				if (moob[i]->getHp() < 0) {
					std::cout << "hi" << std::endl;
					moob.erase(moob.begin() + i);
				}
			}
		}
	}
}

