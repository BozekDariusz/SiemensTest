#pragma once

#include<iostream>
#include<string>
#include"Airport.h"

namespace UI {

	void confirmLanding();

	void countDown(int timer);

	void noAirport();

	void noStrip();

	void askForInput();

	std::pair<Airport::airportName, Strip::planeType> userInput();

	Strip::planeType takeAirplaneInput();

	Airport::airportName takeAirportInput();

}