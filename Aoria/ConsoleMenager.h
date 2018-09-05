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
	/// <summary>This method wil log a message and it type to console (if Debug Mode) and to file.  
	/// <para><paramref name="message"/>: This parrametr take a string. It set a meesege witch will be outputed in console and file</para>
	/// <para><paramref name="log"/>: This parrametr take a string. By deafault it set as "LOG". It set a type of message</para>
	/// </summary> 
	void log(const string &message, const string &typeLog = "LOG");
	/// <summary>When the application gets any error it will display a messege in console(DEBUG) and save this message to file  
	/// <para><paramref name="errorText"/>: This parrametr take a string. It set a meesege witch will be outputed in console and file</para>
	/// <para><paramref name="window"/>: This parrametr take a sf::RenderWindow(). Used to close a window</para>
	/// </summary> 
	void errorExit(string errorText, sf::RenderWindow *window);
private:
	string message;
	vector<string> *logs = new vector<string>;
};