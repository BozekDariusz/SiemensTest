#include"Strip.h"
#include"UI.h"

Strip::Strip(planeType plane, int timer) {

	timeUntilNextPlaneCanLand = timer;
	timeOfLanding = getTimeInSeconds() - timeUntilNextPlaneCanLand; // at the begining the strip is empty and plane can land 
	stripType = plane;

}

bool Strip::isFreeForLanding() {

	if (getTimeInSeconds() - timeOfLanding > timeUntilNextPlaneCanLand) {
		land();
		return true;
	}

	return false;
}
void Strip::land() {
	
		while (getTimeInSeconds() - timeOfLanding < timeUntilNextPlaneCanLand) {//print countdown

			UI::countDown(timeUntilNextPlaneCanLand - (getTimeInSeconds() - timeOfLanding));
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		}

		timeOfLanding = getTimeInSeconds();
		UI::confirmLanding();

}

clock_t Strip::getTimeInSeconds() {
	return clock() / CLOCKS_PER_SEC;
}