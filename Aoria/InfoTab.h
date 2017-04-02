#pragma once
#include <SFML\Graphics.hpp>

class InfoBar {
public:
	enum pos { LEFT = 0, RIGHT = 1 };
	InfoBar(sf::Texture &texture, sf::Font &f, pos pos,sf::Vector2f position);
	void SetBar1(const std::string &msg,const float &number);
	void SetBar2(const std::string &msg,const float &number);
	void draw(sf::RenderWindow &win);
private:
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Sprite barSprite;
};