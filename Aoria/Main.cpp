#include <iostream>
#include "Engine.h"

using namespace std;
int main() {
#if __unix__
	std::cout << "AORIA RUN ON UNIX! (LINUX/MACOS)" << srd::endl;
#elif _WIN64
	std::cout << "AORIA ON WINDOWS (64BIT)" << std::endl;
#endif // __unix__

	Engine engine;
	engine.runEngine();
	system("pause");
	return 0;
}