#include "InfoTab.h"

#include <sstream>
std::string Convert(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

InfoBar::InfoBar(sf::Texture & texture, sf::Font & f)
{
	barSprite.setTexture(texture);
	font = f;
}

void InfoBar::SetBar1(const std::string & msg, float & number)
{
	text1.setCharacterSize(14);
	text1.setFont(font);
	text1.setPosition(7, 4);
	text1.setString(msg + " " + Convert(number));
}

void InfoBar::SetBar2(const std::string & msg, float & number)
{
	text2.setCharacterSize(14);
	text2.setFont(font);
	text2.setPosition(7, 27);
	text2.setString(msg + " " + Convert(number));
}

void InfoBar::draw(sf::RenderWindow & win)
{
	win.draw(barSprite);
	win.draw(text2);
	win.draw(text1);

}
