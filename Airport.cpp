

#include"Airport.h"






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


	void Airport::deleteStrip(std::string planeType) { //make sure to delete allocated memory when deleting strips from airport//only deleting last strip of given type if there are more than one
		auto existsStrip = Strips.find(planeType);
		if (existsStrip != Strips.end()) {


			if (existsStrip->second.size() > 1) {
				delete existsStrip->second[existsStrip->second.size()-1];
				existsStrip->second.erase(existsStrip->second.end()-1);

			}
			else {
				delete existsStrip->second[0];

				Strips.erase(existsStrip);
			}
		}

	}
