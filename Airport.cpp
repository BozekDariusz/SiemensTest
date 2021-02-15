#include"Airport.h"

#include"UI.h"

Airport::Airport(airportName name) {
	id = name;
	addStrip(Strip::planeType::Big, 60);
	addStrip(Strip::planeType::Light, 30);

}

void Airport::canLand(std::vector<Strip>& strips) {//bad and not optimized //checking if plane can land and if it cant how long before it can


	for (size_t i = 0; i < strips.size(); i++) {//find if any stip of given type is open for landing and if it is land
		if (strips[i].isFreeForLanding()) return;
	}

	strips[0].land();
	return;

}

void Airport::checkAirplane(Strip::planeType plane) {//check if this airport can support plane of given type 


	auto existsStrip = Strips.find(plane);
	if (existsStrip != Strips.end()) {
		canLand(existsStrip->second);
	}
	else {
		UI::noStrip();
		return;
	}
}

void Airport::addStrip(Strip::planeType plane, int timeToReady) {

	auto existsStrip = Strips.find(plane);//check if that type of strip is already added to the database and if it is add another entry 
	if (existsStrip != Strips.end()) {
		existsStrip->second.push_back(Strip(plane, timeToReady));
	}
	else {//if there isnt such type yet add it
		std::vector<Strip> temp;
		temp.push_back(Strip(plane, timeToReady));
		Strips.insert({ plane,temp });
	}
}

void Airport::removeStrip(Strip::planeType plane) { //only deleting last strip of given type if there are more than one

	auto existsStrip = Strips.find(plane);

	if (existsStrip != Strips.end()) {

		if (existsStrip->second.size() > 1) {

			existsStrip->second.erase(existsStrip->second.end() - 1);

		}
		else {

			Strips.erase(existsStrip);
		}
	}

}
