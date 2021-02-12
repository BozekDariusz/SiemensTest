

#include"Airport.h"


	Strip::Strip(int timer) {

		timeToReady = timer;
		timeOfLanding = clock() / CLOCKS_PER_SEC - timeToReady; // at the begining the strip is empty and plane can land 

	}



	Airport::Airport() {//default two strips, big and light

		addStrip("Big", 60);
		addStrip("Light", 30);

	}

	Airport::~Airport() {//delete allocated memory for strips 
		for (auto const& vectorOfStrips : Strips)
		{
			for (auto const& strip : vectorOfStrips.second) {
				delete strip;
			}

		}
	}

	void Airport::addStrip(std::string planeType, int timeToReady) {

		auto existsStrip = Strips.find(planeType);//check if that type of strip is already added to the database and if it is add another entry 
		if (existsStrip != Strips.end()) {
			existsStrip->second.push_back(new Strip(timeToReady));
		}
		else {//if there isnt such type yet add it
			std::vector<Strip*> temp;
			temp.push_back(new Strip(timeToReady));
			Strips.insert({ planeType,temp });
		}
	}


	void Airport::deleteStrip(std::string planeType) { //make sure to delete allocated memory when deleting strips from airport
		auto existsStrip = Strips.find(planeType);
		if (existsStrip != Strips.end()) {
			delete existsStrip->second[existsStrip->second.size() - 1];
		}

	}
