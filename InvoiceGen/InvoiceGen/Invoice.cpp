#include <iostream>
#include "Invoice.h"
using namespace std;

Invoice::Invoice(string num, string desc, int quantity, int price)
{
	partNumber = num;
	partDescription = desc;

	if (quantity < 0)
		qty = 0;
	else
		qty = quantity;

	if (price < 0)
		ppi = 0;
	else
		ppi = price;
}

void Invoice::setPartNumber(string num)
{
	partNumber = num;
	return;
}

void Invoice::setPartDesctription(string desc)
{
	partDescription = desc;
	return;
}

void Invoice::setQty(int quantity)
{
	if (quantity < 0)
		qty = 0;
	else
		qty = quantity;

	return;

}
void Invoice::setPpi(int price)
{
	if (price < 0)
		ppi = 0;
	else
		ppi = price;

	return;
}

string Invoice::getPartNumber()
{
	return partNumber;
}

string Invoice::getPartDescription()
{
	return partDescription;
}

int Invoice::getQty()
{
	return qty;
}

int Invoice::getPpi()
{
	return ppi;
}

int Invoice::getInvoiceAmount()
{
	return qty * ppi;
}