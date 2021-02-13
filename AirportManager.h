#pragma once
#include <time.h>
#include<map>
#include<vector>
#include<iostream>
#include <Windows.h>


#include"Airport.h"

class AirportManager {

	void checkAirport(std::pair<airportName, planeType> airportAndPlaneInfo);
	std::map<airportName, Airport> Airports;

public:


	AirportManager();

	void addAirport(Airport airport);


	void removeAirport(airportName airportID);

	void work();



};
