#include "JsonManager.h"

JsonMenager::JsonMenager(ConsoleManager *_consoleManager)
	:consoleManager (_consoleManager), jsonsPath(fs::current_path() /= "jsons")
{
	consoleManager->log("JsonMenager Created!", "MODULE LOG");

	//test

	loadAllJsons();
}

bool JsonMenager::loadAllJsons()
{
	jsons.clear();
	//create an iterator for json files
	//watch for "jsonPath" folder
	consoleManager->log("Searching for jsons in \"" + jsonsPath.u8string() + "\"","JSON LOG");
	if (fs::is_directory(jsonsPath)) {
		//watch all files in "jsonPatch" folder
		for (auto& p : fs::recursive_directory_iterator("jsons")) {
			//search and load ".json" files
			if (p.path().u8string().find(".json") != std::string::npos) {
				file.open(p);
				string name;
				json j;
				file >> j;
				bool findName = false;
				for (auto &it = j.begin(); it != j.end(); ++it) {
					if (it.key().find("module") != std::string::npos && findName == false) {
						name = j["module"]["name"].get<std::string>();
						jsons[name] = j;
						consoleManager->log("Loaded json \"" + name + "\" from file \"" + p.path().u8string() + "\"", "JSON LOG");
						findName = true;
					}
				}
				if (findName == false)
					consoleManager->log("Cannot load \"" + p.path().u8string() + "\" add { \"module\" : { \"name\": \"Module Name\" } } to repair a problem!", "JSON WARNING");
				
				file.close();
			}
		}
	}
	else
	{
		consoleManager->log("Folder \"" + jsonsPath.u8string() + "\" are not exist or is empty!", "JSON ERROR");
		return false;
	}
	return true;
}

std::string JsonMenager::getDataFromJson(const string jsonName, const std::string name, std::vector<string> subname)
{
	json j = jsons[jsonName];
	bool findName = false;
	string s = "NONE";
	string jsonAsString = j.dump();
	auto subnameItems = subname.size();
	int i = 0;
	for (auto &it = jsons[jsonName].begin(); it != jsons[jsonName].end(); ++it) {
		if (it.key() == name)
		{
			if (jsonAsString.find(subname.back()) != std::string::npos)
			{
				consoleManager->log(to_string(i));
				if (subnameItems == 1) {
					s = j[name][subname.back()].get<std::string>();
				}
				else if (subnameItems == 2) {
					s = j[name][(&subname.back())[-1]][subname.back()].get<std::string>();
				}
				else if (subnameItems == 3) {
					s = j[name][(&subname.back())[-2]][(&subname.back())[-1]][subname.back()].get<std::string>();
				}
				else if (subnameItems == 4) {
					s = j[name][(&subname.back())[-3]][(&subname.back())[-2]][(&subname.back())[-1]]
						[subname.back()].get<std::string>();
				}
				else
				{
					consoleManager->log("JSON Tree is to big!", "JSON WARNING!");
				}
				++i;
			}
		}
	}
	if (findName == false)
		consoleManager->log("Cannot find \"" + name + "\" in " + jsonName, "JSON WARNING");
	return s;
}