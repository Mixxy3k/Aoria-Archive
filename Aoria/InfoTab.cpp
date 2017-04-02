#include "InfoTab.h"

#include <sstream>
std::string Convert(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

InfoBar::InfoBar(sf::Texture & texture, sf::Font & f,pos pos, sf::Vector2f position)
{
	barSprite.setTexture(texture);

	if (pos == LEFT) {
		text1.setFont(font);
		text1.setPosition(7, 4);

		text2.setFont(font);
		text2.setPosition(7, 27);
		barSprite.setOrigin(0, 0);
	}
	else if (pos == RIGHT) {
		text1.setFont(font);
		text1.setPosition(position.x - 237.f, position.y + 4.f);

		text2.setFont(font);
		text2.setPosition(position.x - 225.f, position.y + 27.f);

		barSprite.setOrigin(barSprite.getGlobalBounds().width, 0);
	}
	barSprite.setPosition(position);
	font = f;
	text1.setCharacterSize(14);
	text2.setCharacterSize(14);
}

void InfoBar::SetBar1(const std::string & msg,const float & number)
{
	text1.setString(msg + " " + Convert(number));
}

void InfoBar::SetBar2(const std::string & msg,const float & number)
{
	text2.setString(msg + " " + Convert(number));
}

void InfoBar::draw(sf::RenderWindow & win)
{
	win.draw(barSprite);
	win.draw(text2);
	win.draw(text1);

}
