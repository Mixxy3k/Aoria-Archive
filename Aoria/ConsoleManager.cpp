#include "ConsoleManager.h"

#if _DEBUG
ConsoleManager::ConsoleManager(std::string version, std::string debugVersion)
	:message()
{
	sf::err().rdbuf(NULL);
	showConsole();
	log("Aoria v" + version + " DEBUG BUILD " + debugVersion, "");
}
#else
ConsoleManager::ConsoleManager(std::string version)
	:message()
{
	sf::err().rdbuf(NULL);
	hideConsole();
	log("Aoria v: " + version, "");
}
#endif // _DEBUG
ConsoleManager::~ConsoleManager()
{
	delete logs;
}
void ConsoleManager::log(const string & message, const string & typeLog)
{
	//If somthing go wrong and typeLog is empty, change typeLog to "LOG:"
	if (typeLog.empty())
		this->message = "LOG: " + message;

	//Create message <3
	else
		this->message = typeLog + ": " + message;

	//Prepare log to save to file
	logs->push_back(this->message);

	//If DEBUG -> Write log to console
	//If RELASE -> Do nothing <3
#if _DEBUG
	cout << this->message << endl;
#endif // _DEBUG
}

void ConsoleManager::seperator()
{
	cout << "--------------------" << endl;
}

void ConsoleManager::errorExit(string errorText, sf::RenderWindow * window)
{
	//*gameState = APP_ERROR;
	window->close();
#if (_DEBUG == false)
	showConsole();
#endif
	log("Cannot run application correctly!");
	system("pause");
}

#if  _WIN64
void ConsoleManager::hideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ConsoleManager::showConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_RESTORE);
}
#else
void consoleManager::hideConsole()
{
	system(disdown)
}

void consoleManager::showConsole()
{
	system(gnome-terminal);
}
#endif // _WIN64