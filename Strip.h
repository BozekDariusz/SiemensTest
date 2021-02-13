#pragma once

#include <time.h>



class Strip {

	clock_t timeOfLanding;


	clock_t getTimeInSeconds();

public:
	enum class planeType
	{
		WrongType,
		Big,
		Light
	};


	planeType stripType;


	int timeUntilNextPlaneCanLand;

	Strip(planeType plane, int timer);

	bool isFreeForLanding();

	void land();

};