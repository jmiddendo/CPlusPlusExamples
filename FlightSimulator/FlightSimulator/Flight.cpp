#include <string>
#include <iostream>
using namespace std;
#include "Flight.h"

const string AIRPORTS[20] = { "SEA", "OAK", "LAX", "SLC", "ABQ", "MSP", "MSI", "DFW", "HOU", "ORD", "CLE", "IND", "ATL", "JAX", "MIA", "IAD", "LGA", "BOS", "DEN", "MEM" };
const string DIRECTIONS[8] = { "North", "South", "East", "West", "Northwest", "Northeast", "Southwest", "Southeast" };

Flight::Flight(string mm, string car, int spd, int alt, string dir, FlightStatus stat,
	string org, string dest, string dtime, string atime)
{
	MakeModel = mm;
	Carrier = car;
	AirSpeed = spd;
	Altitude = alt;
	Direction = dir;
	Status = stat;
	Origin = org;
	Destination = dest;
	DepartureTime = dtime;
	ArrivalTime = atime;
}

string Flight::getMakeModel()
{
	return MakeModel;
}

string Flight::getCarrier()
{
	return Carrier;
}

int Flight::getAirSpeed()
{
	return AirSpeed;
}

int Flight::getAltitude()
{
	return Altitude;
}

string Flight::getDirection()
{
	return Direction;
}

void Flight::getStatus()
{
	toString();
	return;
}

string Flight::getOrigin()
{
	return Origin;
}

string Flight::getDestination()
{
	return Destination;
}

string Flight::getDepartureTime()
{
	return DepartureTime;
}

string Flight::getArrivalTime()
{
	return ArrivalTime;
}

void Flight::setMakeModel(string mm)
{
	MakeModel = mm;
	return;
}

void Flight::setCarrier(string car)
{
	Carrier = car;
	return;
}

void Flight::setAirSpeed(int spd)
{
	FlightStatus tempStatus;

	if (spd < 0)
		cout << "Air speed cannot be a negative value." << endl;
	else if (Status == 0)
		cout << "A Pre-Flight plane cannot increase speed." << endl;
	else if (Status < 3 && spd < AirSpeed)
		cout << "Air speed cannot be lowered until en route." << endl;
	else if (Status > 3 && spd > AirSpeed)
		cout << "Air speed cannot be raised at the end of the flight.";
	else
	{
		tempStatus = Status;
		Status = CHANGING_SPEED;
		cout << "The speed is: " << AirSpeed << "mph" << endl;
		toString();
		Status = tempStatus;
		AirSpeed = spd;
		cout << "The speed is now " << AirSpeed << " mph" << endl;
	}
	return;
}

void Flight::setAltitude(int alt)
{
	FlightStatus tempStatus;

	if (alt < 0)
		cout << "Altitude cannot be below zero" << endl;
	else if (Status == 0)
		cout << "A Pre-Flight plane cannot increase altitude." << endl;
	else if (Status < 3 && alt < Altitude)
		cout << "Altitude cannot be lowered until en route." << endl;
	else if (Status > 3 && alt > Altitude)
		cout << "Altitude cannot be raised at the end of the flight.";
	else
	{
		tempStatus = Status;
		Status = CHANGING_ALTITUDE;
		toString();
		Status = tempStatus;
		Altitude = alt;
		cout << "The altitude is now " << Altitude << " feet" << endl;
	}

	return;
}

void Flight::setDirection(string dir)
{
	FlightStatus tempStatus;
	bool runMe = false;

	for (int x = 0; x < ((sizeof(DIRECTIONS)) / (sizeof(DIRECTIONS[0]))); x++)
	{
		if (DIRECTIONS[x] == dir)
		{
			runMe = true;
			break;
		}

	}

	tempStatus = Status;
	Status = CHANGING_DIRECTION;
	toString();
	Status = tempStatus;

	if (runMe)
	{
		Direction = dir;
		cout << "The plane's direction is now " << Direction << endl;
	}
	else
	{
		cout << "Not a valid direction!" << endl;
		cout << "The plane's direction is " << Direction << endl;
	}
	return;
}

void Flight::setStatus(FlightStatus stat)
{
	if (Status < 7)
		Status = stat;
	else
		cout << "The plane is parked.  Please select a different flight." << endl;
	toString();
	return;
}

void Flight::setOrigin(string Org)
{
	Origin = Org;
	return;
}

void Flight::setDestination(string dest)
{
	FlightStatus tempStatus;
	bool runMe = false;

	for (int x = 0; x < ((sizeof(AIRPORTS)) / (sizeof(AIRPORTS[0]))); x++)
	{
		if (AIRPORTS[x] == dest)
		{
			runMe = true;
			break;
		}

	}

	tempStatus = Status;
	Status = CHANGING_DESTINATION;
	toString();
	Status = tempStatus;

	if (runMe)
	{
		Destination = dest;
		cout << "The plane's destination is now " << Destination << endl;
	}
	else
	{
		cout << "Not a valid airport!" << endl;
		cout << "The plane's destination is " << Destination << endl;
	}

	return;
}

void Flight::setDepartureTime(string dTime)
{
	DepartureTime = dTime;
	return;
}

void Flight::setArrivalTime(string aTime)
{
	ArrivalTime = aTime;
	return;
}

void Flight::toString()
{
	switch (Status)
	{
	case 0:
	{
		cout << "The flight status is PREFLIGHT." << endl;
		break;
	}
	case 1:
	{
		cout << "The flight status is TAKEOFF." << endl;
		break;
	}
	case 2:
	{
		cout << "The flight status is DEPARTURE." << endl;
		break;
	}
	case 3:
	{
		cout << "The flight status is EN_ROUTE." << endl;
		break;
	}
	case 4:
	{
		cout << "The flight status is DESCENT" << endl;
		break;
	}
	case 5:
	{
		cout << "The flight status is APPROACH." << endl;
		break;
	}
	case 6:
	{
		cout << "The flight status is LANDING." << endl;
		break;
	}
	case 7:
	{
		cout << "The flight status is PARKED." << endl;
		break;
	}
	case 8:
	{
		cout << "The flight status is CHANGING_ALTITUDE." << endl;
		break;
	}
	case 9:
	{
		cout << "The flight status is CHANGING_SPEED." << endl;
		break;
	}
	case 10:
	{
		cout << "The flight status is CHANGING_DESTINATION." << endl;
		break;
	}
	case 11:
	{
		cout << "The flight status is CHANGING_DIRECTION." << endl;
		break;
	}
	default:
		cout << "Status could not be determined!" << endl;
		break;
	}
	return;
}