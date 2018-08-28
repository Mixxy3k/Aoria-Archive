#include "Engine.h"

Engine::Engine()
{
	//Set window resolution to 1024x512
	windowResolution = sf::Vector2i(1024, 512);
}

void Engine::runEngine()
{
	//Creating a window and set title fo relase mode
	window->create(sf::VideoMode(windowResolution.x, windowResolution.y), "Voav " + version, sf::Style::Default);

	//Change tilte of window for debug mode
#if _DEBUG
	window->setTitle("Aoria v: " + version + " DEBUG BUILD " + DEBUG_VER);
#endif

	//Load font to memory
	if (!textureMenager->loadFont("data/Fonts/good times/good times rg.ttf")) {
		consoleMenager->log("Cannot load font!", "ERROR");
	}


	//Create a object for Loading message
	sf::Text loadingText("Loading", textureMenager->getFont(), 90);
	loadingText.setPosition(window->getSize().x / 2 - loadingText.getGlobalBounds().width / 2, window->getSize().y / 2 - loadingText.getGlobalBounds().height / 2);


	//Display a Loading message, set window color to black
	window->clear();
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
}

void Engine::runMenu(sf::Vector2i screnResolution)
{

}
