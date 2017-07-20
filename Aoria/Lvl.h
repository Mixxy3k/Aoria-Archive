#pragma once
#include <iostream>
class Lvl {
private:
	bool end = false;
	int lvl = 0;
	std::string lvls = "No Name";
	int BlueMoobResp = 0;
	int stage = 1;
	bool save = false;
public:
	void NewLvl() { lvl++; }
	void SetStage(int Stage) { stage = Stage; }
	void SetLvl(int Lvl) { lvl = Lvl; }

	int Stage() { return stage; }
	int LastLvl() { return lvl; }
	int HowMuchBlue() { return BlueMoobResp; }
	bool Save() { return save; }
	void lvlskl() {
		if (stage == 1) {
			switch (lvl) {
			case 1:
				BlueMoobResp = 1;
				break;
			case 2:
				BlueMoobResp = 2;
				break;
			case 3:
				BlueMoobResp = 3;
				break;
			case 4:
				BlueMoobResp = 4;
				break;
			case 5:
				BlueMoobResp = 5;
				break;
			case 6:
				BlueMoobResp = 6;
				break;
			case 7:
				BlueMoobResp = 7;
				break;
			case 8:
				stage++;
				lvl = 0;
				save = true;
				break;
			}
		}
		if (stage == 2) {
			switch (lvl) {
			case 1:
				BlueMoobResp = 10;
				save = false;
				break;
			case 2:
				BlueMoobResp = 20;
				break;
			case 3:
				BlueMoobResp = 30;
				break;
			case 4:
				BlueMoobResp = 40;
				break;
			case 5:
				BlueMoobResp = 50;
				break;
			case 6:
				BlueMoobResp = 60;
				break;
			case 7:
				BlueMoobResp = 70;
				break;
			case 8:
				save = true;
				end = true;
				break;
			case 9:
				save = false;
				break;
			}
		}
	}
};