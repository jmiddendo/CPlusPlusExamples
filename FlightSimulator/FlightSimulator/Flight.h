#include <string>
#include "FlightStatus.h"
using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight
{
public:
	Flight(string = "", string = "", int = 0, int = 0, string = "", FlightStatus = PREFLIGHT,
		string = "", string = "", string = "", string = "");
	string getMakeModel();
	string getCarrier();
	int getAirSpeed();
	int getAltitude();
	string getDirection();
	void getStatus();
	string getOrigin();
	string getDestination();
	string getDepartureTime();
	string getArrivalTime();
	void setMakeModel(string);
	void setCarrier(string);
	void setAirSpeed(int);
	void setAltitude(int);
	void setDirection(string);
	void setStatus(FlightStatus);
	void setOrigin(string);
	void setDestination(string);
	void setDepartureTime(string);
	void setArrivalTime(string);
	void toString();

private:
	string MakeModel;
	string Carrier;
	int AirSpeed;
	int Altitude;
	string Direction;
	FlightStatus Status;
	string Origin;
	string Destination;
	string DepartureTime;
	string ArrivalTime;
};



#endif