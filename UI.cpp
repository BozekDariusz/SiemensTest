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

	std::cout << "Please input the type of Plane and Airport's ID: ";

}
std::string UI::takeAirplaneInput() {
	std::string  airplane;
	std::cin >> airplane;
	return airplane;

}
std::string UI::takeAirportInput() {

	std::string airport;
	std::cin >> airport;
	return airport;

}

std::pair<std::string, std::string> UI::userInput() {


	askForInput();
	std::string airport = takeAirportInput();
	std::string strip = takeAirplaneInput();
	return std::make_pair(airport, strip);

}