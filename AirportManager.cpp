

#include"AirportManager.h"

AirportManager::AirportManager() {
	addAirport(Airport(LGW));
	addAirport(Airport(EMA));
	addAirport(Airport(MAN));
}

void AirportManager::addAirport(Airport airport) {//make a check to not override existing airport. maybe overload that function?


	Airports.insert({ airport.id,airport });

}



void AirportManager::removeAirport(airportName airportID) {
	auto exists = Airports.find(airportID);
	if (exists != Airports.end()) {
		Airports.erase(exists);
	}
}



void AirportManager::checkAirport(std::pair<airportName, planeType> airportAndPlaneInfo) {

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

	UI::userInput();
	checkAirport(std::make_pair(MAN, Light));//FIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIX
}




int main() {
	AirportManager manager;
	while (1) {
		manager.work();
	}

}