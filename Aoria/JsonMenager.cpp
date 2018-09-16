#include "JsonMenager.h"

bool JsonMenager::loadAllJsons()
{
	cout << jsonsPath << endl;
	string t;
	if (fs::is_directory(jsonsPath)) {
		for (auto& p : fs::recursive_directory_iterator("jsons")) {
			cout << "Loaded -> " << p << endl;
			file->open(p);
			json j;
			while (!file->eof())
			{
				std::getline(*file, t);
				j += t;
			}
			file->close();
		}
	}
	return false;
}
