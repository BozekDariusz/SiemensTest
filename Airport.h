#pragma once
#include <time.h>
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include <Windows.h>



struct Strip {
	Strip(int timer);
	clock_t timeOfLanding; // when last plane landed 
	int timeToReady; // how long before next plane can land 

};
struct Airport {
	Airport();

	~Airport();


	void addStrip(std::string planeType, int timeToReady);


	void deleteStrip(std::string planeType);

	std::map<std::string, std::vector<Strip*>> Strips; // map of all strips that the airport has 

};