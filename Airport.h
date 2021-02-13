#pragma once
#include<map>
#include<vector>

#include"Strip.h"

enum airportName {

	LGW,
	EMA,
	MAN

};


class Airport {


	void canLand(std::vector<Strip>& strips);

public:

	std::map<planeType, std::vector<Strip>> Strips;

	airportName id;

	Airport(airportName name);

	void addStrip(planeType plane, int timeToReady);

	void removeStrip(planeType plane);

	void checkAirplane(planeType plane);

};