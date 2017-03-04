#pragma once
#include <SFML\Graphics.hpp>

class InfoBar {
public:
	InfoBar(sf::Texture &texture, sf::Font &f);
	void SetBar1(const std::string &msg, float &number);
	void SetBar2(const std::string &msg, float &number);
	void draw(sf::RenderWindow &win);
private:
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Sprite barSprite;
};