#pragma once
#include<map>
#include<vector>
#include<string>

#include"Strip.h"




class Airport {


public:

	std::map<std::string, std::vector<Strip*>> Strips; // map of all strips that the airport has 
	
	Airport();

	~Airport();


	void addStrip(std::string planeType, int timeToReady);


	void deleteStrip(std::string planeType);

};