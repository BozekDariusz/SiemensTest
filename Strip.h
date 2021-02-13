#pragma once

#include <time.h>

#include"UI.h"

enum planeType
{
	Big,
	Light
};

class Strip {

	clock_t timeOfLanding;


	clock_t getTimeInSeconds();

public:


	planeType stripType;


	int timeUntilNextPlaneCanLand;

	Strip(planeType plane, int timer);

	bool isFreeForLanding();

	void land();

};