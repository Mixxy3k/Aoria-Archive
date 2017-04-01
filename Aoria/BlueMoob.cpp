#include "BlueMoob.h"

bool BlueMoob::timer()
{
	if (bulletClock.getElapsedTime().asSeconds() >= attackTime) {
		bulletClock.restart();
		return true;
	}
	return false;
}
