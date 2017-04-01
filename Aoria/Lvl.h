#pragma once
#include <iostream>
class Lvl {
public:
	bool end = false;
	int lvl = 0;
	std::string lvls = "ERROR";
	int BlueMoobResp = NULL;
	void lvlskl() {
		switch (lvl) {
		case 1:
			BlueMoobResp = 1;
			break;
		case 2:
			BlueMoobResp = 2;
			break;
		case 3:
			BlueMoobResp = 5;
			break;
		case 4:
			BlueMoobResp = 10;
			break;
		case 5:
			BlueMoobResp = 3;
			break;
		case 6:
			BlueMoobResp = 10;
			break;
		case 7:
			break;
		case 8:
			end = true;
			break;
		}
	}
};