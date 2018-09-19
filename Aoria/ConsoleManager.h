#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
#if _WIN64
	#include <Windows.h>
#endif

using namespace std;

class ConsoleManager {
public:
#if _DEBUG
	ConsoleManager(std::string version, std::string debugVersion);
#else
	ConsoleManager(std::string version);
#endif // _DEBUG
	~ConsoleManager();

	void hideConsole();
	void showConsole();

	void log(const string &message, const string &typeLog = "LOG");
	void seperator();

	void errorExit(string errorText, sf::RenderWindow *window);
private:
	string message;
	vector<string> *logs = new vector<string>;
};