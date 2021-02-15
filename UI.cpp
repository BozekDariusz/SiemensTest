#include"UI.h"

void UI::confirmLanding() {

	std::cout << "Landing Confirmed" << std::endl;

}

void UI::countDown(int timer) {

	std::cout << "Plane will be able to land in: " << timer << std::endl;

}

void UI::noAirport() {

	std::cout << "Airport not in database, try different airport or check your spelling" << std::endl;

}

void UI::noStrip() {

	std::cout << "Strip of such type not in database, try different airplane type or check your spelling" << std::endl;

}

void UI::askForInput() {

	std::cout << "Please input the type of Plane(e.g. Big, Light) and Airport's ID(e.g. MAN, LGW, EMA): ";

}

Strip::planeType UI::takeAirplaneInput() {
	std::string  airplane;
	std::cin >> airplane;
	Strip::planeType plane;
	if (airplane == "Big") plane = Strip::planeType::Big;
	else if (airplane == "Light") plane = Strip::planeType::Light;
	else plane = Strip::planeType::WrongType;
	return plane;

}

Airport::airportName UI::takeAirportInput() {

	std::string airport;
	std::cin >> airport;
	Airport::airportName portName;
	if (airport == "EMA") portName = Airport::airportName::EMA;
	else if (airport == "LGW") portName = Airport::airportName::LGW;
	else if (airport == "MAN") portName = Airport::airportName::MAN;
	else portName = Airport::airportName::WrongName;

	return portName;

}

std::pair<Airport::airportName, Strip::planeType> UI::userInput() {


	askForInput();
	Strip::planeType strip = takeAirplaneInput();
	Airport::airportName airport = takeAirportInput();
	return std::make_pair(airport, strip);

}