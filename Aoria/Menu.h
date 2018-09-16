#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;

class Menu {
public:
	Menu(sf::RenderWindow *window, sf::Vector2i windowResolution) {
		this->window = window;
		this->windowResolution = windowResolution;
	}

	int menu();
private:
	sf::Vector2i windowResolution;
	struct buttonsSpecyfication {
		sf::Text text;
		int size = 11;
		string buttonText = "[]";
		sf::Vector2i position;
	};
	::map<int, buttonsSpecyfication> *buttons = new ::map<int, buttonsSpecyfication>;
	sf::Vector2f center(sf::Vector2f bounds);

	sf::RenderWindow *window;
	sf::Sprite background;
};