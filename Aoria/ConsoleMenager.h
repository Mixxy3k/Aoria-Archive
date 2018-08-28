#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
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

	//Display a Log Message in Console
	void log(const string &message, const string &typeLog = "LOG");
	
private:
	string message;
	vector<string> *logs = new vector<string>;

	inline void hideConsole() {
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	}

	inline void showConsole()
	{
		::ShowWindow(::GetConsoleWindow(), SW_RESTORE);
	}
};