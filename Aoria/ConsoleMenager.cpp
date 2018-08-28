#include "ConsoleMenager.h"

//Write Log to console if run in DEBUG, and prepare message to save to file
void ConsoleMenager::log(const string & message, const string & typeLog)
{
	if (typeLog.empty())
		this->message = "LOG: " + message;
	else
		this->message = typeLog + ": " + message;

	logs->push_back(this->message);

#if _DEBUG
	cout << this->message << endl;
#endif // _DEBUG
}

//Set console position to background 
inline void ConsoleMenager::hideConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

//Restore console from background
void ConsoleMenager::showConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_RESTORE);
}


