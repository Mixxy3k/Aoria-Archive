#pragma once
#include "nlohmann JSON Library/json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "ConsoleMenager.h"

using json = nlohmann::json;
namespace fs = std::experimental::filesystem;
using namespace std;

class JsonMenager {
public:
	bool loadAllJsons();
	bool saveJsonFile() { throw "NOT IMPLEMENTED"; };
private:
	std::fstream *file = new std::fstream;
	fs::path jsonsPath = fs::current_path() /= "jsons";
};