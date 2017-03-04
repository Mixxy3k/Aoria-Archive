#include "Engine.h"
sf::Color bg(10, 10, 15);

Engine::Engine(sf::RenderWindow & win, FileMenager &fm)
{
	window = &win;
	fileMenager = &fm;
	moob.push_back(new BlueMoob(fileMenager->getRef("blueShip")));
	moob.push_back(new BlueMoob(fileMenager->getRef("blueShip")));
	player = new Player(fileMenager->getRef("player"));
	infoBar = new InfoBar(fileMenager->getRef("topLeftBar"), fileMenager->getFont());
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
	window->clear(bg);
	window->draw(*player);
	for (auto obj : moob) {
		obj->draw(*window);
	}
	for (auto obj: playerBullet)
	{
		obj->draw(*window);
	}
	infoBar->draw(*window);
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
	int X = player->getPlaerPosition().x;
	int Y = player->getPlaerPosition().y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Y > 64) {
		player->move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Y < window->getSize().y) {
		player->move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && X > 64) {
		player->move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && X < window->getSize().x) {
		player->move(1, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->bulletCoolDown()) {
		playerBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition() - sf::Vector2f(25,0))); // right
		playerBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"),player->getPlaerPosition())); // center
		playerBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition() - sf::Vector2f(-25, 0))); // left

	}
	//------------- Si Move
	for (auto obj : moob) {
		obj->generateVector();
		obj->attack();
	}
	//------------- Moob - Bullet interaction
	int i = 0;
	for (int j = 0; j < playerBullet.size();j++) {
		//move bullet
		playerBullet[j]->move();
		for (int i = 0; i < moob.size(); i++){
			//colision
			if (playerBullet[j]->colision(moob[i]->getMoobRect())) {
				moob[i]->substractHP(moob[i]->dmg);
				//slain?
				if (moob[i]->getHp() < 0) {
					//kill moob
					moob.erase(moob.begin() + i);
					return;
				}
			}
		}
		if (playerBullet[j]->deleteBullet()) {
			playerBullet.erase(playerBullet.begin() + j);
		}
	}
	float hp = player->getHp();
	float lvl = 1;
	infoBar->SetBar1("Player HP: ", hp);
	infoBar->SetBar2("Lvl: ", lvl);
}

