#pragma once
#include <iostream>
#include <string>
#include <vector>
#if _WIN64
	#include <Windows.h>
#endif

using namespace std;

class ConsoleMenager {
public:
#if _DEBUG
	ConsoleMenager(std::string version, std::string debugVersion)
	{
		showConsole();
		log("Aoria v: " + version + " DEBUG BUILD " + debugVersion, "");
	}
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

	void hideConsole();
	void showConsole();
};