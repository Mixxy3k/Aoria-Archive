#include <iostream>
#include "Engine.h"

using namespace std;
int main() {
#if _WIN64
	std::cout << "AORIA ON WINDOWS (64BIT)" << std::endl;
#else
	std::cerr << "NOT 64 BIT WINDOWS! [App is only 64 bit]]" << std::endl;
#endif
	Engine engine;
	engine.loadGame();
	return 0;
}