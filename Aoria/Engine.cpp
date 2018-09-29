#include "Engine.h"

#if _DEBUG
/*Create engine class in debug mode, its allow app to:
	- Show Console
	- Read Logs and Errors
*/
Engine::Engine()
	:version("2.0"), DEBUG_VER("1.2"),
	consoleManager(new ConsoleManager(version, DEBUG_VER)),
	gameState(new GameState), window(new sf::RenderWindow),
	jsonMenager(new JsonMenager(consoleManager)),
	textureMenager(new TextureMenager(consoleManager))
{
	consoleManager->log("Engine Loaded!", "MODULE LOG");
}
#else
/*Create engine class in debug mode. Features:
	- Hide Console
	- [NOT IN GAME YET]Log into file

*/
Engine::Engine()
	:version("2.0"),
	consoleManager(new ConsoleManager(version)),
	gameState(new GameState), window(new sf::RenderWindow),
	jsonMenager(new JsonMenager(consoleManager)),
	textureMenager(new TextureMenager(consoleManager))
{
	consoleManager->log("Engine Loaded!", "MODULE LOG");
}
#endif

Engine::~Engine() {
	delete this->window;
	delete this->textureMenager;
	delete this->gameState;
	delete this->consoleManager;
	cout << "Ram Cleared!" << endl;
}

void Engine::loadGame()
{
	*gameState = LOADING;
	//Set window resolution to 1024x512
	windowResolution = sf::Vector2i(1024, 512);
	//Creating a window and set title fo relase mode
	window->create(sf::VideoMode(windowResolution.x, windowResolution.y), "Voav " + version, sf::Style::Default);

	//Change tilte of window for debug mode
#if _DEBUG
	window->setTitle("Aoria v: " + version + " DEBUG BUILD " + DEBUG_VER);
#endif

	consoleManager->seperator();
	consoleManager->log("Loading jsons!");
	consoleManager->new_line();
	jsonMenager->loadAllJsons();

	consoleManager->seperator();
	consoleManager->log("Loading font and textures!");
	consoleManager->new_line();

	//Load font to memory
	textureMenager->loadFont("data/Fonts/good times/good times rg.ttf");

	//Display a Loading message, set window color to black
	//Create a object for Loading message
	sf::Text loadingText("Loading", textureMenager->getFont(), 90);
	loadingText.setPosition(window->getSize().x / 2 - loadingText.getGlobalBounds().width / 2, window->getSize().y / 2 - loadingText.getGlobalBounds().height / 2);
	window->clear();
	window->draw(loadingText);
	window->draw(loadingText);
	window->display();


	//Loading a texture
	textureMenager->loadTexture("background", "data/background-1409125_1280.png", 0);
	textureMenager->loadTexture("player", "data/Player/ship.png", 1);
	textureMenager->loadTexture("blueShip", "data/Si/bluemoob.png", 2);
	textureMenager->loadTexture("kineticBullet", "data/Kinetic/Kinetic.png", 3);
	textureMenager->loadTexture("topLeftBar", "data/Bar/Top Left Bar.png", 4);
	textureMenager->loadTexture("topRightBar", "data/Bar/Top Right Bar.png", 5);
	textureMenager->loadTexture("laser", "data/Laser/Laser.png", 6);
	consoleManager->seperator();
	consoleManager->log("All loaded succesful!");
	*gameState = MENU;
	runMenu();
}

void Engine::windowEventMenager()
{
	sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
}

void Engine::runEngine()
{
	while (*gameState == IN_GAME && window->isOpen())
	{
		windowEventMenager();
	}
}

void Engine::runMenu()
{
	while (*gameState == MENU && window->isOpen()) 
	{
		windowEventMenager();
	}
}