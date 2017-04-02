#include "Engine.h"
sf::Color bg(10, 10, 15);

Engine::Engine(sf::RenderWindow & win, FileMenager &fm)
{
	window = &win;
	fileMenager = &fm;
	player = new Player(fileMenager->getRef("player"));
	leftInfoBar = new InfoBar(fileMenager->getRef("topLeftBar"), fileMenager->getFont(), leftInfoBar->LEFT,sf::Vector2f(0,0));
	rightInfoBar = new InfoBar(fileMenager->getRef("topRightBar"), fileMenager->getFont(), rightInfoBar->RIGHT, sf::Vector2f(1024, 0));

	lvl = new Lvl();
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
	for (auto obj : allBullet)
	{
		obj->draw(*window);
	}
	for (auto obj : moob) {
		obj->draw(*window);
	}
	window->draw(*player);
	rightInfoBar->draw(*window);
	leftInfoBar->draw(*window);
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
	// -------------- Lvl menager
	if (moob.empty()) {
		lvl->lvl++;
		lvl->lvlskl();
		for (int i = 0; i < lvl->BlueMoobResp; i++) {
			moob.push_back(new BlueMoob(fileMenager->getRef("blueShip")));
		}
	}
	// -------------- Control Player
	int X = player->getPlaerPosition().x;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && X > 32) {
		player->move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && X < window->getSize().x - 32) {
		player->move(1, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->bulletCoolDown() == true) {
		allBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition() - sf::Vector2f(25, 0))); // right
		//allBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"),player->getPlaerPosition())); // center
		allBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition() - sf::Vector2f(-25, 0))); // left
		player->resetBulltClock();
	}
	//------------- Si Move
	for (auto obj : moob) {
		obj->generateVector();
		obj->attack();
		if (obj->timer()) {
			allBullet.push_back(new Laser(fileMenager->getRef("laser"), obj->getPos()));
		}
	}
	//------------- Moob - Bullet interaction
	int i = 0;
	bool del = false;
	for (int j = 0; j < allBullet.size(); j++) {
		//move bullet
		allBullet[j]->move();
		for (int i = 0; i < moob.size(); i++) {
			//colision
			if (allBullet[j]->colision(moob[i]->getMoobRect()) && allBullet[j]->owner == allBullet[j]->Player) {
				moob[i]->substractHP(player->dmg);
				del = true;
				//slain?
				if (moob[i]->getHp() < 0) {
					//kill moob
					moob.erase(moob.begin() + i);
					return;
				}
			}
			if (allBullet[j]->colision(player->getRect()) && allBullet[j]->owner == allBullet[j]->SI) {
				player->substarctHP(moob[i]->dmg);
				del = true;
				if (player->getHp() <= 0) {
					//DIE
				}
			}
		}
		if (allBullet[j]->deleteBullet() || del) {
			allBullet.erase(allBullet.begin() + j);
		}
	}
	leftInfoBar->SetBar1("Health: ", player->getHp());
	leftInfoBar->SetBar2("Lvl: ", lvl->lvl);

	rightInfoBar->SetBar1("Bullets: ", allBullet.size());
	rightInfoBar->SetBar2("SI: ", moob.size());
}

