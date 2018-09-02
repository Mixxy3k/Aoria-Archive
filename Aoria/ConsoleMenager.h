#pragma once
#include "SFML/Graphics.hpp"
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
		sf::err().rdbuf(NULL);
		showConsole();
		log("Aoria v" + version + " DEBUG BUILD " + debugVersion, "");
	}
#else
	ConsoleMenager(std::string version)
	{
		sf::err().rdbuf(NULL);
		hideConsole();
		log("Aoria v: " + version, "");
	}
#endif // _DEBUG

	void hideConsole();
	void showConsole();
	void log(const string &message, const string &typeLog = "LOG");
	void errorExit(string errorText, sf::RenderWindow *window);
private:
	string message;
	vector<string> *logs = new vector<string>;
};