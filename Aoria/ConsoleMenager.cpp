#include "ConsoleMenager.h"

void ConsoleMenager::log(const string & message, const string & typeLog)
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
//#if _DEBUG
	cout << this->message << endl;
//#endif // _DEBUG
}

void ConsoleMenager::seperator()
{
	cout << "--------------------" << endl;
}

void ConsoleMenager::errorExit(string errorText, sf::RenderWindow * window)
{
	//*gameState = APP_ERROR;
	window->close();
#if (_DEBUG == false)
	showConsole();
#endif
	log("Cannot run application correctly!");
	system("pause");
}

#if _WIN64
void ConsoleMenager::hideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ConsoleMenager::showConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_RESTORE);
}
#else
void ConsoleMenager::hideConsole()
{
	system(disdown)
}

void ConsoleMenager::showConsole()
{
	system(gnome-terminal);
}
#endif