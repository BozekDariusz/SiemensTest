#pragma once
#include <time.h>
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include <Windows.h>

#include"Airport.h"
#include"UI.h"


void addNewAirport(std::string airportID);

void addExistingAirport(std::string airportID, Airport* airport);

void deleteAirport(std::string airportID); 

void removeAirport(std::string airportID);

void canLand(std::vector<Strip*> strips);

void checkAirportAndAirplane(std::string airplaneType, std::string airportID);


void userInput();



