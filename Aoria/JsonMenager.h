#pragma once
#include "nlohmann JSON Library/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include "ConsoleMenager.h"

using json = nlohmann::json;
namespace fs = std::experimental::filesystem;
using namespace std;

class JsonMenager {
public:
	JsonMenager(ConsoleMenager *consoleMenager);
	bool loadAllJsons();
	bool saveJsonFile() { throw "NOT IMPLEMENTED"; };
private:
	ConsoleMenager *consoleMenager;
	std::string pathToString(fs::path path);
	std::map<std::string, json> jsons;
	std::fstream file;
	fs::path jsonsPath = fs::current_path() /= "jsons";
};