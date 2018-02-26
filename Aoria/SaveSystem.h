#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "nlohmann JSON Library\json.hpp"

class JSONS {
public:
	void SaveGame(std::string name, int stage, int hp);
	void LoadGame();
	std::string GetName() { return name; }
	int GetStage() { return stage; }
	int GetHP() { return hp; }
private:
	const std::string Position = "save.txt";
	std::string name = "[]";
	int stage = 1;
	int hp = 100;

	std::string s_stage;
	std::string s_hp;
};