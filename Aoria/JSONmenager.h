#pragma once
#include "nlohmann JSON Library\json.hpp"
#include <stdarg.h>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class JsonMenager {
public:
	JsonMenager();
	bool loadJson(int ID, const std::string position, const std::string name = "");
	bool saveJson(int ID, const std::string position, json j);
	// ------------ ID -> id of json

	json getJson(int ID) { return this->Jsons.at(ID); }

private:
	fstream file;
	json j;

	std::map<int, json> Jsons;
	std::map<int, std::string> JsonList;
};