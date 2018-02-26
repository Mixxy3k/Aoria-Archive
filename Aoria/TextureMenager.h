#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <windows.h>
class TextureMenager {
public:

	/*
	background	->	0
	player		->	1
	blueShip	->	2
	kineticBullet -> 3
	topLeftBar	->	4
	topRightBar	->	5
	laser		-> 6	*/
	sf::Texture& getTexture(int id) { return this->MapTexture.at(id); }

	//--------- Textures Name: name of texture  Pos: Position in folder-----------------
	bool LoadTexture(const std::string &name, const std::string& position, const int& ID) {
		sf::Texture Texture;
		if (!Texture.loadFromFile(position)) {
			system("cls");
			std::cout << "Cannot Load File " + position << std::endl;
			return false;
		}
		else {
			MapTexture[ID] = Texture;
			TextureList[ID] = name;
			std::cout << "Load File: Aoria.exe Position/" + position << std::endl;
			return true;
		}
	}

	void textureList() {
		for (auto elem : TextureList)
		{
			std::cout << "ID: " << elem.first << " Name: " << elem.second << std::endl;
		}
	}
	bool loadFont(const std::string& Pos) {
		if (!font.loadFromFile(Pos)) {
			system("cls");
			std::cout << "Cannot Load File " + Pos << std::endl;
			return false;
		}
		else {
			std::cout << "Load File: Aoria.exe Position/" + Pos << std::endl;
			return true;
		}
	}
	sf::Font& getFont() {
		return this->font;
	}
private:
	sf::Font font;

	std::map<int, sf::Texture> MapTexture;
	std::map<int, std::string> TextureList;
};