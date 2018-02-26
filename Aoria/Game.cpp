#include "Game.h"

Game::Game()
{
	gameState = END;
	// ------------ Window ------------------------//
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window->create(sf::VideoMode(width, height), "Aoria", sf::Style::Default, settings);
	window->setFramerateLimit(60);

	//------------- Font --------------------------//
	textureMenager->loadFont("data/Fonts/good times/good times rg.ttf");

	//------------- Textures ----------------------//
	textureMenager->LoadTexture("background",		"data/background-1409125_1280.png",	0);
	textureMenager->LoadTexture("player",			"data/Player/ship.png",				1);
	textureMenager->LoadTexture("blueShip",			"data/Si/bluemoob.png",				2);
	textureMenager->LoadTexture("kineticBullet",	"data/Kinetic/Kinetic.png",			3);
	textureMenager->LoadTexture("topLeftBar",		"data/Bar/Top Left Bar.png",		4);
	textureMenager->LoadTexture("topRightBar",		"data/Bar/Top Right Bar.png",		5);
	textureMenager->LoadTexture("laser",			"data/Laser/Laser.png",				6);
	gameState = MENU;
	runGame();
}

void Game::runGame()
{
	while (gameState != END) {
		switch (gameState)
		{
		case MENU:
			menu();
			break;
		case GAME:
			initEngine();
			break;
		case GAME_OVER:
			break;
		default:
			break;
		}
	}
}

void Game::initEngine()
{
	Engine engine(this->window, this->textureMenager);
	engine.runEngine();
	gameState = MENU;
	runGame();
}

void Game::menu()
{

	using namespace std;
	using namespace sf;
	sf::Sprite bg;
	bg.setTexture(textureMenager->getTexture(0));
	Text title("Aoria", textureMenager->getFont(), 80);
	title.setStyle(Text::Bold);

	title.setPosition(width / 2 - title.getGlobalBounds().width / 2, 20);

	const int ile = 2;

	Text tekst[ile];

	string str[] = { "Play","Exit" };
	for (int i = 0; i < ile; i++)
	{
		tekst[i].setFont(textureMenager->getFont());
		tekst[i].setCharacterSize(65);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(width / 2 - tekst[i].getGlobalBounds().width / 2, 250 + i * 120);
	}

	while (gameState == MENU)
	{
		// Real Real coords to window coords
		sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
		sf::Vector2f mouse = window->mapPixelToCoords(pixelPos);

		Event event;

		while (this->window->pollEvent(event))
		{
			// -------- Pressed [X] or ESC
			if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				gameState = END;

			//--------- chose MENU                          
			else if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				gameState = GAME;
			}

			//--------- Pressed Exit
			else if (tekst[1].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				gameState = END;
			}
		}
		for (int i = 0; i < ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setFillColor(Color::Cyan);
			else tekst[i].setFillColor(Color::White);

			window->clear();
			window->draw(bg);
			window->draw(title);
			for (int i = 0; i < ile; i++)
				window->draw(tekst[i]);

			window->display();
	}
}
