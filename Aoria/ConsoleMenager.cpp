#include "ConsoleMenager.h"

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
