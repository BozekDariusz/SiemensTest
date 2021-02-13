#pragma once
#include <time.h>
#include<map>
#include<vector>
#include<iostream>
#include <Windows.h>


#include"Airport.h"

class AirportManager {

	void checkAirport(std::pair<Airport::airportName, Strip::planeType> airportAndPlaneInfo);
	std::map<Airport::airportName, Airport> Airports;

public:


	AirportManager();

	void addAirport(Airport airport);


	void removeAirport(Airport::airportName airportID);

	void work();



};
