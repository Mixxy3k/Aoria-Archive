#include "JsonMenager.h"

JsonMenager::JsonMenager(ConsoleMenager *consoleMenager)
{
	this->consoleMenager = consoleMenager;
}

bool JsonMenager::loadAllJsons()
{
	//create an iterator for json files
	int i = 0;
	//watch for "jsonPath" folder
	if (fs::is_directory(jsonsPath)) {
		//watch all files in "jsonPatch" folder
		for (auto& p : fs::recursive_directory_iterator("jsons")) {
			//search and load ".json" files
			if (pathToString(p).find(".json") != std::string::npos) {
				consoleMenager->log(pathToString(p), "LOADED");
				file.open(p);
				json j;
				file >> j;
				for (json::iterator it = j.begin(); it != j.end(); ++it) {
					if (pathToString(it.key()).find("button") != std::string::npos) {
						int a = j[it.key()]["size"].get<int>();
						string b = j[it.key()]["color"].get<std::string>();
						string c = j[it.key()]["buttonText"].get<std::string>();

						cout << "Text: " + c + "\n" + "Color: " + b + "\n" + "Size: " + to_string(a) << endl;
					}
				}

				jsons[1] = j;
				file.close();
			}
		}
		consoleMenager->log("Test json! " + std::to_string(i), "JSON TEST");
		return true;
	}
}

std::string JsonMenager::pathToString(fs::path path)
{
	return path.u8string();
}
