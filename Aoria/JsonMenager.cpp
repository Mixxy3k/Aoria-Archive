#include "JsonMenager.h"

JsonMenager::JsonMenager(ConsoleMenager *consoleMenager)
{
	this->consoleMenager = consoleMenager;
}

bool JsonMenager::loadAllJsons()
{
	//create an iterator for json files
	//watch for "jsonPath" folder
	if (fs::is_directory(jsonsPath)) {
		//watch all files in "jsonPatch" folder
		for (auto& p : fs::recursive_directory_iterator("jsons")) {
			//search and load ".json" files
			if (pathToString(p).find(".json") != std::string::npos) {
				file.open(p);
				string name;
				json j;
				file >> j;
				bool find = false;

				for (auto &it = j.begin(); it != j.end(); ++it) {
					if (pathToString(it.key()).find("module") != std::string::npos && find == false) {
						name = j["module"]["name"].get<std::string>();
						jsons[name] = j;
						consoleMenager->log("Loaded json \"" + name + "\" from file \"" + pathToString(p) + "\"", "JSON LOG");

						find = true;
					}
				}
				if (!find)
					consoleMenager->log("Cannot load \"" + pathToString(p) + "\" add { \"module\" : { \"name\": \"name\" } } to repair a problem!", "JSON WARNING");

				find = false;
				file.close();
			}
			return true;
		}

		consoleMenager->log("Folder \"" + pathToString(jsonsPath) + "\" are empty!", "JSON ERROR");
		return false;
	}

	consoleMenager->log("Folder \"" + pathToString(jsonsPath) + "\" are not exist", "JSON ERROR");
	return false;
}
/*
for (auto it = jsons.cbegin(); it != jsons.cend(); ++it)
{
	std::cout << it->first << endl;
}
*/
/*
//Json test (load data from json if exist);
consoleMenager->seperator();
for (json::iterator it = j.begin(); it != j.end(); ++it) {
	if (pathToString(it.key()).find("button") != std::string::npos) {
		int a = j[it.key()]["size"].get<int>();
		string b = j[it.key()]["color"].get<std::string>();
		string c = j[it.key()]["buttonText"].get<std::string>();
		if (pathToString(it.key()).find("button1") != std::string::npos) {
			int rgb = j[it.key()]["test"]["r"].get<int>();
			cout << "rgb: " + to_string(rgb);
		}
		cout << "Text: " + c + "\n" + "Color: " + b + "\n" + "Size: " + to_string(a) << endl;
	}
}
*/
std::string JsonMenager::pathToString(fs::path path)
{
	return path.u8string();
}
