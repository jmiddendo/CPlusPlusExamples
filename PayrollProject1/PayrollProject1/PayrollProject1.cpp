/*File: Lab01.cpp
Programmer: Jeff Middendorf
Date: 10/29/2013
Description: The purpose of this program is to calculate payroll taxes and net payroll
for an employee file*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

/*This section is for function prototyping*/
void createemployee(string);
int process_employee(ifstream&, int&, int&, float&);
void process_payroll(ifstream&, ofstream&, int&, int&, float&);
void print_summary(ofstream&, double, double, double, double, double);

int main()
{
	/*  This is the main "driver" function for the program*/


	//Variable declaration
	int employee_id, hours;
	float wage;
	ifstream inFile;
	ofstream outFile;
	string filein, fileout;

	//Variable initialization
	filein = "employee.txt";
	fileout = "payroll.txt";
	employee_id = 0;
	hours = 0;
	wage = 0.0;

	inFile.open(filein.c_str());
	outFile.open(fileout.c_str());

	//Validation Check
	if (inFile.fail())
	{
		cout << "There was an issue with the employee file.  Please contact you system administrator.";
		system("pause");
		exit(1);
	}

	//Validation Check
	if (outFile.fail())
	{
		cout << "There was an issue with the employee file.  Please contact you system administrator.";
		inFile.close();
		system("pause");
		exit(1);
	}

	process_payroll(inFile, outFile, employee_id, hours, wage);  //Function Call

	inFile.close();
	outFile.close();

	system("Pause");

	return 0;

}

void createemployee(string fname)
{

	/*The purpose of the this function is to create the initial employee file.
	This is the file that will be used to calculate the payroll file*/

	ofstream outFile;

	outFile.open(fname.c_str());

	/*Print Information*/
	outFile << 1121 << ' ' << 15.12 << ' ' << 40 << endl
		<< 9876 << ' ' << 9.50 << ' ' << 47 << endl
		<< 3333 << ' ' << 22.00 << ' ' << 35 << endl
		<< 2121 << ' ' << 5.45 << ' ' << 43 << endl
		<< 9999 << ' ' << 10.00 << ' ' << 25 << endl;

	outFile.close();

	return;

}

void process_payroll(ifstream& inFile_pay, ofstream& outFile_pay, int& employee_id_pay, int& hours_pay, float& wage_pay)
{
	/*This purpose of this function is to perform the processing of the of the payroll file.
	It also keeps track of the running total of the payroll information for the summary print-out.*/

	//Variable declaration
	const float FEDERAL_TAX_RATE = .16;
	const float STATE_TAX_RATE = .0542;
	const float SOC_TAX_RATE = .07;
	float gross, net, federal, state, soc, total_gross, total_net, total_federal, total_state, total_soc;

	//Variable initialization
	int counter = 1;
	total_gross = 0;
	total_net = 0;
	total_federal = 0;
	total_state = 0;
	total_soc = 0;

	/*Print Information*/
	outFile_pay << "Employee Payroll" << endl << endl
		<< setw(8) << "Employee" << setw(7) << "Hours" << ' ' << setw(7)
		<< "Rate" << setw(8) << "Gross" << setw(8) << "Net" << setw(8) << " Fed"
		<< setw(8) << "State" << setw(8) << "SocSec" << endl << endl;

	cout << "Employee Payroll" << endl << endl
		<< setw(8) << "Employee" << setw(7) << "Hours" << ' ' << setw(7)
		<< "Rate" << setw(8) << "Gross" << setw(8) << "Net" << setw(8) << " Fed"
		<< setw(8) << "State" << setw(8) << "SocSec" << endl << endl;

	//Variable initialization
	counter = process_employee(inFile_pay, employee_id_pay, hours_pay, wage_pay);

	//For loop o process payroll
	for (counter = 1; counter == 1; counter = process_employee(inFile_pay, employee_id_pay, hours_pay, wage_pay))
	{
		if (hours_pay <= 35)
		{
			wage_pay += 0.15;
			gross = wage_pay * hours_pay;
			federal = gross * FEDERAL_TAX_RATE;
			state = gross * STATE_TAX_RATE;
			soc = gross * SOC_TAX_RATE;
			net = gross - federal - state - soc;

			/*Print Information*/
			outFile_pay << setw(8) << employee_id_pay << setw(7) << noshowpoint << hours_pay << '*' << fixed << showpoint << setprecision(2)
				<< setw(7) << wage_pay << setw(8) << gross << setw(8) << net << setw(8) << federal << setw(8) << state << setw(8) << soc << endl;

			cout << setw(8) << employee_id_pay << setw(7) << noshowpoint << hours_pay << '*' << fixed << showpoint << setprecision(2)
				<< setw(7) << wage_pay << setw(8) << gross << setw(8) << net << setw(8) << federal << setw(8) << state << setw(8) << soc << endl;
		}
		else if (hours_pay > 35 && hours_pay <= 40)
		{
			gross = wage_pay * hours_pay;
			federal = gross * FEDERAL_TAX_RATE;
			state = gross * STATE_TAX_RATE;
			soc = gross * SOC_TAX_RATE;
			net = gross - federal - state - soc;

			/*Print Information*/
			outFile_pay << setw(8) << employee_id_pay << setw(7) << noshowpoint << hours_pay << ' ' << fixed << showpoint << setprecision(2)
				<< setw(7) << wage_pay << setw(8) << gross << setw(8) << net << setw(8) << federal << setw(8) << state << setw(8) << soc << endl;

			cout << setw(8) << employee_id_pay << setw(7) << noshowpoint << hours_pay << ' ' << fixed << showpoint << setprecision(2)
				<< setw(7) << wage_pay << setw(8) << gross << setw(8) << net << setw(8) << federal << setw(8) << state << setw(8) << soc << endl;
		}
		else
		{
			gross = ((40 * wage_pay) + ((hours_pay - 40)*(wage_pay*1.5)));
			federal = gross * FEDERAL_TAX_RATE;
			state = gross * STATE_TAX_RATE;
			soc = gross * SOC_TAX_RATE;
			net = gross - federal - state - soc;

			/*Print Information*/
			outFile_pay << setw(8) << employee_id_pay << setw(7) << noshowpoint << hours_pay << '$' << fixed << showpoint << setprecision(2)
				<< setw(7) << wage_pay << setw(8) << gross << setw(8) << net << setw(8) << federal << setw(8) << state << setw(8) << soc << endl;

			cout << setw(8) << employee_id_pay << setw(7) << noshowpoint << hours_pay << '$' << fixed << showpoint << setprecision(2)
				<< setw(7) << wage_pay << setw(8) << gross << setw(8) << net << setw(8) << federal << setw(8) << state << setw(8) << soc << endl;
		}


		//Summary assignments
		total_gross += gross;
		total_net += net;
		total_federal += federal;
		total_state += state;
		total_soc += soc;
	}
	print_summary(outFile_pay, total_gross, total_net, total_federal, total_state, total_soc);  //Function Call
}

int process_employee(ifstream& inFile_emp, int& employee_id_emp, int& hour_emp, float& wage_emp)
{

	/*The purpose of this function is to read the variables from the employee file.
	Once the file has been read it will return a zero to end the loop.*/

	while (inFile_emp >> employee_id_emp >> wage_emp >> hour_emp)
		return 1;


	return 0;
}

void print_summary(ofstream& outFile_print, double total_gross, double total_net, double total_federal, double total_state, double total_soc)
{
	/*This purpose of this function is to display the summary data*/

	/*Print Information*/
	outFile_print << endl << endl
		<< "Summary - Totals for All Employees" << endl << endl
		<< setw(13) << "GrossPay" << setw(12) << "NetPay" << setw(13) << "FederalTax"
		<< setw(11) << "StateTax" << setw(14) << "SocSecurity" << endl << endl
		<< setw(13) << total_gross << setw(12) << total_net << setw(13) << total_federal
		<< setw(11) << total_state << setw(14) << total_soc << endl << endl;

	cout << endl << endl
		<< "Summary - Totals for All Employees" << endl << endl
		<< setw(13) << "GrossPay" << setw(12) << "NetPay" << setw(13) << "FederalTax"
		<< setw(11) << "StateTax" << setw(14) << "SocSecurity" << endl << endl
		<< setw(13) << total_gross << setw(12) << total_net << setw(13) << total_federal
		<< setw(11) << total_state << setw(14) << total_soc << endl << endl;
}