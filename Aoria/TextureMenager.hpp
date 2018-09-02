#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "ConsoleMenager.h"

class TextureMenager {
private:
	sf::Font font;

	std::map<int, sf::Texture> MapTexture;
	std::map<int, std::string> TextureList;
	ConsoleMenager *consoleMenager;
public:
	TextureMenager(ConsoleMenager *consoleMenager) {
		this->consoleMenager = consoleMenager;
	}

	sf::Texture& getTexture(int id) { return this->MapTexture.at(id); }

	//Load texture to ram, first parametr is name, second position in file and last is Identification Number(ID)
	bool loadTexture(const std::string &name, const std::string& position, const int& ID) {
		sf::Texture Texture;
		//If somthing go wrong
		if (!Texture.loadFromFile(position)) {
			//Error message
			consoleMenager->log("Cannot load file! + name", "ERROR");
			TextureList[ID] = "ERROR_TEXTURE!";
			return false;
		}
		else {
			MapTexture[ID] = Texture;
			TextureList[ID] = name;
#if _DEBUG 
			consoleMenager->log(name, "LOADED" );
#endif
			return true;
		}
	}
	
	void textureList() {
		for (auto elem : TextureList)
		{
			std::cout << "ID: " << elem.first << " Name: " << elem.second << std::endl;
		}
	}

	bool loadFont(const std::string& position) {
		if (font.loadFromFile(position)) {
#if _DEBUG
			consoleMenager->log("font", "LOADED");
#endif // _DEBUG
			return true;
		}
		return false;
	}

	sf::Font& getFont() {
		return this->font;
	}
};