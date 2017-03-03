#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <windows.h>
class FileMenager {
public:
	//--------- Textures Name: name of texture  Pos: Position in folder-----------------
	void LoadTexture(const std::string& Name, const std::string& Pos) {
		sf::Texture Texture;
		if (!Texture.loadFromFile(Pos)) {
			system("cls");
			std::cout << "Cannot Load File " + Pos << std::endl;
			Beep(759, 300);
			Sleep(3000);
			exit(1);
		}
		else {
			MapTexture[Name] = Texture;
			std::cout << "Load File: Aoria.exe Position/" + Pos << std::endl;
		}
	}
	sf::Texture& getRef(const std::string &texture) {

		return this->MapTexture.at(texture);
	}
	//----------- Font (only one) Pos - position in folder ------------
	void loadFont(const std::string& Pos) {
		if (!font.loadFromFile(Pos)) {
			system("cls");
			std::cout << "Cannot Load File " + Pos << std::endl;
			Beep(759, 300);
			Sleep(3000);
			exit(1);
		}
		else {
			std::cout << "Load File: Aoria.exe Position/" + Pos << std::endl;
		}
	}
	// ------- Take last loaded font -----------
	sf::Font& getFont() {
		return this->font;
	}
private:
	sf::Font font;

	std::map<std::string, sf::Texture> MapTexture;
};
