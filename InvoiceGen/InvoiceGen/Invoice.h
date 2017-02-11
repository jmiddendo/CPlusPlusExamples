#include <string>
using namespace std;

#ifndef INVOICE_H
#define INVOICE_H

class Invoice
{

public:
	Invoice(string = "", string = "", int = 0, int = 0);
	void setPartNumber(string);
	void setPartDesctription(string);
	void setQty(int);
	void setPpi(int);
	string getPartNumber();
	string getPartDescription();
	int getQty();
	int getPpi();
	int getInvoiceAmount();
private:
	string partNumber;
	string partDescription;
	int qty;
	int ppi;

};


#endif