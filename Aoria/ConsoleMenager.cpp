#include "ConsoleMenager.h"

//Write Log to console if run in DEBUG, and prepare message to save to file
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
#if _DEBUG
	cout << this->message << endl;
#endif // _DEBUG
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