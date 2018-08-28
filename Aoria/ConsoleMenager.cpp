#include "ConsoleMenager.h"

void ConsoleMenager::log(const string & message, const string & typeLog)
{
	//Craete message (typeLog is empty change it to LOG)
	if (typeLog.empty())
		this->message = "LOG: " + message;
	//Create message with custom typeLog
	else
		this->message = typeLog + ": " + message;
	//Push message to all sesion logs
	logs->push_back(this->message);
	//If debug -> Write message to console
	//If Relese -> Do nothinkg 
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


