#include "JsonManager.h"

JsonMenager::JsonMenager(ConsoleManager *_consoleManager)
	:consoleManager (_consoleManager), jsonsPath(fs::current_path() /= "jsons")
{
	consoleManager->log("JsonMenager Created!", "MODULE LOG");
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