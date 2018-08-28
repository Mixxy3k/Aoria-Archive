#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

class ConsoleMenager {
public:
	//If -> Debug, create console visable and out a version + debug version
#if _DEBUG
	ConsoleMenager(std::string version, std::string debugVersion)
	{
		showConsole();
		log("Aoria v: " + version + " DEBUG BUILD " + debugVersion, "");
	}
	//If -> Relase, create console invisable and out a version
#else
	ConsoleMenager(std::string version) 
	{
		hideConsole();
		log("Aoria v: " + version, "");
	}
#endif // _DEBUG

	void log(const string &message, const string &typeLog = "LOG");
	
private:
	string message;
	vector<string> *logs = new vector<string>;

	inline void hideConsole();
	void showConsole();
};