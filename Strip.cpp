#include"Strip.h"


Strip::Strip(int timer) {

	timeToReady = timer;
	timeOfLanding = clock() / CLOCKS_PER_SEC - timeToReady; // at the begining the strip is empty and plane can land 

}