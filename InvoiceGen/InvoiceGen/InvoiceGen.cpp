#include <iostream>
#include <string>
#include "Invoice.h"
using namespace std;

int main()
{

	string number, description;
	int quantity, price;
	char answer;

	cout << "Please enter a part number: ";
	cin >> number;
	cout << "Please enter a description: ";
	cin >> description;
	cout << "Please enter a quantity: ";
	cin >> quantity;
	cout << "Please enter a price: ";
	cin >> price;

	cout << endl << endl;

	Invoice a(number, description, quantity, price);

	cout << "Part number: " << a.getPartNumber() << endl
		<< "Description: " << a.getPartDescription() << endl
		<< "Quantity: " << a.getQty() << endl
		<< "Price per item: " << a.getPpi() << endl
		<< "Invoice amount: " << a.getInvoiceAmount() << endl;

	cout << endl << endl;

	system("pause");

	return 0;

}