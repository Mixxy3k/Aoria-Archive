#include <iostream>
#include "Engine.h"

using namespace std;
int main() {
#if __unix__

#elif _WIN64

#endif // __unix__

	Engine engine;
	engine.runEngine();
	system("pause");
	return 0;
}