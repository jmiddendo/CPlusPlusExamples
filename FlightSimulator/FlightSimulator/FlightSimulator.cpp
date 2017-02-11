#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Flight.H"

bool manageFlights(Flight&);

int main()
{

	Flight a("Boeing 747", "Delta", 600, 37000, "South", EN_ROUTE, "ORD", "ATL", "2:00 PM", "3:50 PM");
	Flight b("Airbus A300", "US Airways", 150, 16000, "East", DEPARTURE, "SEA", "CLE", "12:00 AM", "6:15 AM");
	Flight c("Douglas DC-9", "Spirit", 0, 0, "West", PREFLIGHT, "BOS", "DFW", "6:00 AM", "9:50 AM");

	int response = 0;
	bool keepGoing = true;
	bool mainKeep = true;

	do
	{
		do
		{

			system("cls");

			cout << "Please select a flight." << endl
				<< "     1 - Flight " << setw(10) << a.getCarrier() << setw(11) << "From: " << a.getOrigin() << setw(9) << "To: " << a.getDestination() << endl
				<< "     2 - Flight " << setw(10) << b.getCarrier() << setw(11) << "From: " << b.getOrigin() << setw(9) << "To: " << b.getDestination() << endl
				<< "     3 - Flight " << setw(10) << c.getCarrier() << setw(11) << "From: " << c.getOrigin() << setw(9) << "To: " << c.getDestination() << endl
				<< "     4 - Exit Application" << endl
				<< "Please enter an option: ";
			cin >> response;
		} while (response < 1 || response > 4);


		switch (response)
		{
		case 1:
			while (manageFlights(a));
			break;
		case 2:
			while (manageFlights(b));
			break;
		case 3:
			while (manageFlights(c));
			break;
		case 4:
			break;
		default:
			cout << "Invalid response!" << endl;
		}

	} while (response != 4);

	system("pause");

	return 0;

}

bool manageFlights(Flight& plane)
{

	int response = 0;

	system("cls");

	do
	{
		cout << setw(13) << "Altitude" << setw(14) << "Speed" << setw(12) << "Direction" << setw(7) << "Dest"
			<< "\n" << setw(13) << "----------" << setw(14) << "----------" << setw(12) << "----------" << setw(7) << "-----"
			<< "\n" << setw(10) << plane.getAltitude() << " ft" << setw(10) << plane.getAirSpeed() << " mph" << setw(12) << plane.getDirection() << setw(7) << plane.getDestination() << endl << endl;

		cout << "Please select a flight." << endl
			<< "     1 - Change Altitude" << endl
			<< "     2 - Change Speed" << endl
			<< "     3 - Change Direction" << endl
			<< "     4 - Change Destination" << endl
			<< "     5 - Return to Previous Menu" << endl
			<< "Please enter an option: ";
		cin >> response;
	} while (response < 1 || response > 5);

	switch (response)
	{
	case 1:
	{
		int alt = 0;
		char resp = 'y';

		cout << "Please enter a new altitude: ";
		cin >> alt;
		system("cls");
		plane.setAltitude(alt);

		cout << "\nDo you want to perform another task (Y or y)? ";
		cin >> resp;

		if (resp == 'y' || resp == 'Y')
			return true;
		else
			return false;
	}
	case 2:
	{
		int spd;
		char resp = 'y';

		cout << "Please enter a new speed: ";
		cin >> spd;
		system("cls");
		plane.setAirSpeed(spd);

		cout << "\nDo you want to perform another task (Y or y)? ";
		cin >> resp;

		if (resp == 'y' || resp == 'Y')
			return true;
		else
			return false;
	}
	case 3:
	{

		string dir;
		char resp = 'y';

		cout << "Please enter a new direction: ";
		cin >> dir;
		system("cls");
		plane.setDirection(dir);

		cout << "\nDo you want to perform another task (Y or y)? ";
		cin >> resp;

		if (resp == 'y' || resp == 'Y')
			return true;
		else
			return false;
	}
	case 4:
	{
		string dest;
		char resp = 'y';

		cout << "Please enter a new destination: ";
		cin >> dest;
		system("cls");
		plane.setDestination(dest);

		cout << "\nDo you want to perform another task (Y or y)? ";
		cin >> resp;

		if (resp == 'y' || resp == 'Y')
			return true;
		else
			return false;
	}
	case 5:
	{
		return false;
	}
	default:
	{
		cout << "Invalid Please try again.";
		return true;
	}
	}

	return false;

}
