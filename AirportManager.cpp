#include"AirportManager.h"
#include"UI.h"

AirportManager::AirportManager() {
	addAirport(Airport(Airport::airportName::LGW));
	addAirport(Airport(Airport::airportName::EMA));
	addAirport(Airport(Airport::airportName::MAN));
}

void AirportManager::addAirport(Airport airport) {//make a check to not override existing airport. maybe overload that function?


	Airports.insert({ airport.id,airport });

}

void AirportManager::removeAirport(Airport::airportName airportID) {
	auto exists = Airports.find(airportID);
	if (exists != Airports.end()) {
		Airports.erase(exists);
	}
}

void AirportManager::checkAirport(std::pair<Airport::airportName, Strip::planeType> airportAndPlaneInfo) {

	auto existsAirport = Airports.find(airportAndPlaneInfo.first);
	if (existsAirport != Airports.end()) {//check if the airport is in the database 
		existsAirport->second.checkAirplane(airportAndPlaneInfo.second);
	}
	else {
		UI::noAirport();
		return;
	}

}

void AirportManager::work() {

	
	checkAirport(UI::userInput());
}

int main() {
	AirportManager manager;
	while (1) {
		manager.work();
	}

}