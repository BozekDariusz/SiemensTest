#pragma once

#include <time.h>


class Strip {
public:
	Strip(int timer);
	clock_t timeOfLanding; // when last plane landed 
	int timeToReady; // how long before next plane can land 

};