#pragma once

#include<iostream>
#include <Windows.h>
#include<string>

namespace UI {

	void confirmLanding();

	void countDown(int timer);

	void noAirport();

	void noStrip();

	void askForInput();

	std::pair<std::string, std::string> userInput();

	std::string takeAirplaneInput();

	std::string takeAirportInput();

}