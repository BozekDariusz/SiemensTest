#pragma once
#include<map>
#include<vector>
#include"Strip.h"

class Airport {

	void canLand(std::vector<Strip>& strips);

public:

	enum class airportName {

		WrongName,
		LGW,
		EMA,
		MAN

	};

	std::map<Strip::planeType, std::vector<Strip>> Strips;

	airportName id;

	Airport(airportName name);

	void addStrip(Strip::planeType plane, int timeToReady);

	void removeStrip(Strip::planeType plane);

	void checkAirplane(Strip::planeType plane);

};