#include "Engine.h"
sf::Color bg(10, 10, 15);

Engine::Engine(sf::RenderWindow & win, FileMenager &fm)
{
	saveSystem = new Save();
	window = &win;
	fileMenager = &fm;
	lvl = new Lvl();
	player = new Player(fileMenager->getRef("player"));

	saveSystem->LoadGame();
	player->setHp(saveSystem->GetHP());
	lvl->SetStage(saveSystem->GetStage());
	leftInfoBar = new InfoBar(fileMenager->getRef("topLeftBar"), fileMenager->getFont(), leftInfoBar->LEFT,sf::Vector2f(0,0));
	rightInfoBar = new InfoBar(fileMenager->getRef("topRightBar"), fileMenager->getFont(), rightInfoBar->RIGHT, sf::Vector2f(1024, 0));
}
//----------- Main Loop of game ------------
void Engine::runEngine()
{
	sf::Clock clock;
	sf::Time time;
	while (window->isOpen() && goMenu == false)
	{
		if (time.asSeconds() > (1.0f / FPS))
		{
			updateLogic();
			clock.restart();
			time = sf::Time::Zero;
		}
		draw();
		time = clock.getElapsedTime();
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
			goMenu = true;
	}
	// -------------- Lvl menager
	if (moob.empty()) {
		if (lvl->Save()) {
			saveSystem->SaveGame(player->GetName(), lvl->Stage(), player->getHp());
		}
		lvl->NewLvl();
		lvl->lvlskl();
		for (int i = 0; i < lvl->HowMuchBlue(); i++) {
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
		allBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition() - sf::Vector2f(25, 0), player->GetDmg())); // right
		allBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition(), player->GetDmg())); // center
		allBullet.push_back(new KineticBullet(fileMenager->getRef("kineticBullet"), player->getPlaerPosition() - sf::Vector2f(-25, 0), player->GetDmg())); // left
		player->resetBulltClock();
	}
	//------------- Si Move
	for (int i = 0; i < moob.size(); i++) {
		moob[i]->generateVector();
		if (moob[i]->timer()) {
			allBullet.push_back(new Laser(fileMenager->getRef("laser"), moob[i]->getPos(), moob[i]->dmg));
		}
	}
	//------------- Moob - Bullet interaction
	int i = 0;
	bool del = false;
	for (int j = 0; j < allBullet.size(); j++) {
		//move bullet
		allBullet[j]->move();
		//Bullet colision with SI
		for (int i = 0; i < moob.size(); i++) {
			if (allBullet[j]->colision(moob[i]->getMoobRect()) && allBullet[j]->owner == allBullet[j]->Player) {
				moob[i]->substractHP(allBullet[j]->dmg);
				allBullet[j]->off = true;
			}
		}
		//Bullet colision with Player
		if (allBullet[j]->colision(player->getRect()) && allBullet[j]->owner == allBullet[j]->SI && allBullet[j]->off == false) {
			player->substarctHP(allBullet[j]->dmg);
			allBullet[j]->off = true;
			if (player->getHp() <= 0) {
				//DIE
			}
		}
		if (allBullet[j]->deleteBullet()) {
			allBullet.erase(allBullet.begin() + j);
		}
	}
	for (int i = 0; i < moob.size(); i++) {
		if (moob[i]->getHp() < 0) {
			//kill moob
			moob.erase(moob.begin() + i);
		}
	}
	leftInfoBar->SetBar1("Hp: ", player->getHp());
	leftInfoBar->SetBar2("Lvl: ", lvl->LastLvl());

	rightInfoBar->SetBar1("Bullets: ", allBullet.size());
	rightInfoBar->SetBar2("SI: ", moob.size());
}

