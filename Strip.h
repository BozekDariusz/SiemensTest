#pragma once
#include <thread>
#include <time.h>

class Strip {

	clock_t timeOfLanding;

	int timeUntilNextPlaneCanLand;

	clock_t getTimeInSeconds();

public:

	enum class planeType
	{
		WrongType,
		Big,
		Light
	};


	Strip(planeType plane, int timer);

	bool isFreeForLanding();

	void land();

private:

	planeType stripType;

};