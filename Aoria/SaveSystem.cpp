#include "SaveSystem.h"

Save::Save()
{
}

void Save::SaveGame(std::string name, int stage, int hp )
{
	std::ofstream file;
	//----------------- Save Game ----------------- 
	file.open(Position);
	if (!file.good()) {
		std::cout << "Cannot save game! Run game as Administaror (File position: Aoria.exe position/" + Position << std::endl;
		Beep(759, 300);
	}
	else {
		std::cout << "Save  Files" << std::endl;
		file << name << "\n" << stage << "\n" << hp;
	}
	file.close();
}

void Save::LoadGame()
{
	//----------------- Load Game ----------------- 
	std::ifstream file;
	file.open(Position);
	if (!file.good()) {
		//----------------- New File with default variables ----------------- 
		std::cout << " " << std::endl;
		std::cout << "Cannot load game! Creting new file: Aoria.exe position/" + Position << std::endl;
		std::cout << "Name = " + name << std::endl;
		std::cout << "Stage =" + stage << std::endl;
		std::cout << "Hp = " + hp << std::endl;
		SaveGame(name, stage, hp);
	}
	else {
		//----------------- Load variables ----------------- 
		file >> name >> stage >> hp;
		std::cout << "Load variables" << std::endl;
		std::cout << "Name = " + name << std::endl;
		std::cout << "Stage =" + stage << std::endl;
		std::cout << "Hp = " + hp << std::endl;
	}
	file.close();
}
