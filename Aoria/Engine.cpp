#include "Engine.h"
sf::Color bg(10, 10, 15);

Engine::Engine(sf::RenderWindow *window, TextureMenager *textureMenager)
{
	this->window = window;
	this->textureMenager = textureMenager;
	lvl = new Lvl();
	player = new Player(this->textureMenager->getTexture(1));

	leftInfoBar = new InfoBar(this->textureMenager->getTexture(4), this->textureMenager->getFont(), leftInfoBar->LEFT,sf::Vector2f(0,0));
	rightInfoBar = new InfoBar(this->textureMenager->getTexture(5), this->textureMenager->getFont(), rightInfoBar->RIGHT, sf::Vector2f(1024, 0));
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
	for (auto obj : bullets)
	{
		obj->draw(window);
	}
	for (auto obj : moob) {
		obj->draw(window);
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
		//	saveSystem->SaveGame(player->GetName(), lvl->Stage(), player->getHp());
		}
		lvl->NewLvl();
		lvl->lvlskl();
		for (int i = 0; i < lvl->HowMuchBlue(); i++) {
			moob.push_back(new BlueMoob(this->textureMenager->getTexture(2)));
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
		int x = 0;
		while (x <= 3) {
			bullets.push_back(new KineticBullet(0, textureMenager->getTexture(3), player->getPlaerPosition()));
			x++;
		}
	}
	//------------- Si Move
	for (int i = 0; i < moob.size(); i++) {
		moob[i]->generateVector();
		if (moob[i]->timer()) {
			// allBullet.push_back(new Laser(this->textureMenager->getTexture(6), moob[i]->getPos(), moob[i]->dmg));
		}
	}
	//------------- Moob - Bullet interaction
	int i = 0;
	bool del = false;
	for (int j = 0; j < bullets.size(); j++) {
		//move bullet
		bullets[j]->move();
		if (bullets[j]->deleteBullet()) {
			bullets.erase(bullets.begin() + j);
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

	//rightInfoBar->SetBar1("Bullets: ", allBullet.size());
	rightInfoBar->SetBar2("SI: ", moob.size());
}

