#include "JSONmenager.h"

JsonMenager::JsonMenager()
{
	std::cout << "JsonMenager RUN" << std::endl;
}

bool JsonMenager::loadJson(int ID, const std::string position, const std::string name)
{
	this->file.open(position);
	if (this->file.good()) {
		std::string content((std::istreambuf_iterator<char>(this->file)), (std::istreambuf_iterator<char>()));
		this->j = content;
		Jsons[ID] = this->j;
		JsonList[ID] = name;
		std::cout << "LOADED FILE    ID: " << ID << "    POSITION: " << position << "    NAME: " << endl;
		file.close();
		return true;
	}
	else {
		std::cout << "ERROR WHILE LOADING A FILE!    ID: " << ID << "    POSITION: " << position << "    NAME: " << endl;
		file.close();
		return false;
	}
}

bool JsonMenager::saveJson(int ID, const std::string position, json j)
{
	this->file.open(position, std::ofstream::trunc);
	if (this->file.good()) {
		file << j;
		Jsons[ID] = this->j;
		std::cout << "SAVE FILE    ID: " << ID << "    POSITION: " << position << "    NAME: " << endl;
		file.close();
		return true;
	}
	else {
		std::cout << "ERROR WHILE SAVING A FILE!    ID: " << ID << "    POSITION: " << position << "    NAME: " << endl;
		file.close();
		return false;
	}
}
