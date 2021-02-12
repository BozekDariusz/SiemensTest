

#include"AirportManager.h"

	std::map<std::string, Airport*> Airports;//map of all airports 

	void addNewAirport(std::string airportID) {//make a check to not override existing airport. maybe overload that function?

		Airport* airport = new Airport();
		Airports.insert({ airportID,airport });

	}

	void addExistingAirport(std::string airportID, Airport * airport) {//make a check to not override existing airport.maybe overload that function?

		Airports.insert({ airportID,airport });

	}

	void deleteAirport(std::string airportID) {// delete airport when sure that it is the only place it is used 
		auto exists = Airports.find(airportID);
		if (exists != Airports.end()) {
			delete exists->second;
			Airports.erase(exists);
		}
	}

	void removeAirport(std::string airportID) {//remove the airport withouth deleting it if for example it is used somewhere else 
		auto exists = Airports.find(airportID);
		if (exists != Airports.end()) {
			Airports.erase(exists);
		}
	}

	void canLand(std::vector<Strip*> strips) {//bad and not optimized 


		for (size_t i = 0; i < strips.size(); i++) {//find if any stip of given type is open for landing and if it is land
			if (clock() / CLOCKS_PER_SEC - strips[i]->timeOfLanding > strips[i]->timeToReady) {
				strips[i]->timeOfLanding = clock() / CLOCKS_PER_SEC;
				std::cout << "Landing Confirmed" << std::endl;
				return;
			}
		}

		if (clock() / CLOCKS_PER_SEC - strips[0]->timeOfLanding < strips[0]->timeToReady) {//since there isnt any free strip to land the plane needs to wait 
			

			while (clock() / CLOCKS_PER_SEC - strips[0]->timeOfLanding < strips[0]->timeToReady) {//print countdown

				std::cout << "Plane will be able to land in: " << strips[0]->timeToReady - (clock() / CLOCKS_PER_SEC - strips[0]->timeOfLanding) << std::endl;
				Sleep(1000);


			}
			strips[0]->timeOfLanding = clock() / CLOCKS_PER_SEC;
			std::cout << "Landing Confirmed" << std::endl;
			return;

		}
		else {//check if the first strip is still full, maybe it freed itself while checking all other strips
			strips[0]->timeOfLanding = clock() / CLOCKS_PER_SEC;
			std::cout << "Landing Confirmed" << std::endl;
			return;
		}

	}

	void checkAirportAndAirplane(std::string airplaneType, std::string airportID) {

		auto existsAirport = Airports.find(airportID);
		if (existsAirport != Airports.end()) {//check if the airport is in the database 
			auto existsStrip = existsAirport->second->Strips.find(airplaneType);
			if (existsStrip != existsAirport->second->Strips.end()) {//check if this airport can support plane of given type 
				canLand(existsStrip->second);
			}
			else {
				std::cout << "Airplane type not in database, try different airplane or check your spelling" << std::endl;
				return;
			}
		}
		else {
			std::cout << "Airport not in database, try different airport or check your spelling" << std::endl;
			return;
		}

	}


void userInput() {

	std::string airport, airplane;
	std::cout << "Please input the type of Plane and Airport's ID:";
	std::cin >> airplane >> airport;
	checkAirportAndAirplane(airplane, airport);
}




int main() {

	addNewAirport("LGW");
	addNewAirport("EMA");
	addNewAirport("MAN");
	deleteAirport("LGW");
	while (1) {
		userInput();
	}
	
}