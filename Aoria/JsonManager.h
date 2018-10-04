#pragma once
#include "nlohmann JSON Library/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <vector>
#include "ConsoleManager.h"

using json = nlohmann::json;
namespace fs = std::experimental::filesystem;
using namespace std;

class JsonMenager {
public:
	JsonMenager(ConsoleManager *consoleManager);
	bool loadAllJsons();
private:
	std::string getDataFromJson(const string jsonName,const std::string name,std::vector<string> subname );
	ConsoleManager *consoleManager;
	std::map<std::string, json> jsons;
	std::fstream file;
	fs::path jsonsPath; 
};