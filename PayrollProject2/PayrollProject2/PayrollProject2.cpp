/*File: Lab02.cpp
Programmer: Jeff Middendorf
Date: 11/14/2013
Description: The purpose of this program is to calculate gross wages with bonuses and penalties
based off arrays.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


/*This section is for function prototyping*/
void process_payroll(ifstream&, ofstream&, int&, string&, float&, int&, string);
int process_employee(ifstream&, int&, string&, float&, int&);
void min_max_avg(ofstream&, string[], float[], int);
void print_summary(ofstream&, string[], float[], int[], float[], string[], float[], int);

int main()
{

	/*  This is the main "driver" function for the program*/


	//Variable declaration	
	ifstream inFile;
	ofstream outFile;
	string name;


	//Variable initialization
	string inputfilename = "employee.txt";
	string outputfilename = "payroll.txt";
	int record_count = 0;
	float wage = 0;
	int hours = 0;
	string date_string = "October 2013";
	int value = 0;

	//Open files
	inFile.open(inputfilename.c_str());
	outFile.open(outputfilename.c_str());


	//Validation Check
	if (inFile.fail())
	{
		cout << "There was an issue reading the employee file.  Please contact your system administrator.";
		system("pause");
		exit(1);
	}


	//Validation Check
	if (outFile.fail())
	{
		inFile.close();
		cout << "There was an issue creating the payroll file.  Please contact your system administrator.";
		system("pause");
		exit(1);
	}


	//Function Call
	process_payroll(inFile, outFile, record_count, name, wage, hours, date_string);


	//Print out spacing
	outFile << endl;
	cout << endl;


	//Error checking
	if (record_count > 10)
		cout << "Error!  There are more than 10 records!" << endl << endl;



	//Close out files
	inFile.close();
	outFile.close();


	//Pause for the system
	system("pause");


	//Return value
	return 0;

}

void process_payroll(ifstream& inFile_proc, ofstream& outFile_proc, int& record_count_proc, string& name_proc, float& wage_proc, int& hours_proc, string file_date)
{

	/*This purpose of this function is to perform the processing of the of the payroll file.*/


	//Variable initialization - Constant
	const int SIZE = 20;
	const float PENALTY = 0.25;
	const float WAGE_BONUS = 50.0;


	//Variable declaration	
	string name_array[SIZE], bonus[SIZE];
	float wage_array[SIZE], gross_array[SIZE], adj_gross_array[SIZE];
	int hours_array[SIZE];


	//Variable initialization
	int array_count = 0;


	//While loop to store info into array
	while (process_employee(inFile_proc, record_count_proc, name_proc, wage_proc, hours_proc))
	{
		//Variable initialization
		name_array[array_count] = name_proc;
		hours_array[array_count] = hours_proc;
		wage_array[array_count] = wage_proc;
		++array_count;
	}


	/*Print Information*/
	cout << "Number of Employees: " << record_count_proc << endl << endl;
	outFile_proc << "Number of Employees: " << record_count_proc << endl << endl;


	//Function Call
	min_max_avg(outFile_proc, name_array, wage_array, record_count_proc);


	/*Print Information*/
	cout << file_date << " Payroll:" << endl << endl;
	outFile_proc << file_date << " Payroll:" << endl << endl;


	/*Calculate the gross information and store into an array.*/
	for (int x = 0; x < record_count_proc; x++)
	{

		gross_array[x] = (wage_array[x] * hours_array[x]);

		if (hours_array[x] > 45)
		{
			adj_gross_array[x] = (gross_array[x] + WAGE_BONUS);
			bonus[x] = "Y";
		}
		else if (hours_array[x] < 30)
		{
			adj_gross_array[x] = (gross_array[x] - (PENALTY*hours_array[x]));
			bonus[x] = "N";
		}
		else
		{
			adj_gross_array[x] = gross_array[x];
			bonus[x] = "N";
		}
	}


	//Function call
	print_summary(outFile_proc, name_array, wage_array, hours_array, gross_array, bonus, adj_gross_array, record_count_proc);


	//Return value
	return;
}

int process_employee(ifstream& inFile_emp, int& record_count_emp, string& name_emp, float& wage_emp, int& hours_emp)
{

	/*The purpose of this function is to read the variables from the employee file. It also tracks the record
	counts. Once the file has been read it will return a zero to end the loop.*/


	if (inFile_emp >> name_emp >> wage_emp >> hours_emp)
	{
		++record_count_emp;
		return 1;
	}
	else
		return 0;

}

void min_max_avg(ofstream& outFile_avg, string name_avg[], float wage_avg[], int record_count_avg)
{

	/*The purpose of this function is to calculate the minimum wage, the maximum wage, and the average wage
	for the population set.*/


	//Variable initialization
	float avg_value_sum = 0;
	float avg_value = 0;
	string max_name = name_avg[0];
	float max_wage = wage_avg[0];
	string min_name = name_avg[0];
	float min_wage = wage_avg[0];


	//A for loop to determine the minimum and maximum wage.
	for (int x = 0; x < record_count_avg; x++)
	{
		if (wage_avg[x] > max_wage)
		{
			max_wage = wage_avg[x];
			max_name = name_avg[x];
		}

		if (wage_avg[x] < min_wage)
		{
			min_wage = wage_avg[x];
			min_name = name_avg[x];
		}

		avg_value_sum += wage_avg[x];
	}


	//Assignment statement to determine the average value
	avg_value = (avg_value_sum / record_count_avg);


	/*Print information*/
	outFile_avg << "Maximum Pay Rate: " << max_name << " @ $" << fixed << setprecision(2) << max_wage << endl << endl
		<< "Minimum Pay Rate: " << min_name << " @ $" << fixed << setprecision(2) << min_wage << endl << endl
		<< "Average Pay: $" << fixed << setprecision(2) << avg_value << endl << endl;

	cout << "Maximum Pay Rate: " << max_name << " @ $" << fixed << setprecision(2) << max_wage << endl << endl
		<< "Minimum Pay Rate: " << min_name << " @ $" << fixed << setprecision(2) << min_wage << endl << endl
		<< "Average Pay: $" << fixed << setprecision(2) << avg_value << endl << endl;


	//Return value
	return;

}

void print_summary(ofstream& outFile_print, string name_print[], float wage_print[], int hours_print[], float gross_print[], string bonus_print[], float adj_gross_print[], int counter)
{

	/*This purpose of this function is to display the payroll information.*/


	/*Print headers*/
	outFile_print << setw(15) << "Name" << setw(6) << "Hours" << setw(7) << "Rate" << setw(9)
		<< "Gross" << setw(7) << "Bonus" << setw(16) << "Adjusted_Gross" << endl;

	cout << setw(15) << "Name" << setw(6) << "Hours" << setw(7) << "Rate" << setw(9) << "Gross" << setw(7)
		<< "Bonus" << setw(16) << "Adjusted_Gross" << endl;


	//A for loop to print the payroll information.
	for (int x = 0; x < counter; x++)
	{
		/*Print Information*/
		outFile_print << setw(15) << name_print[x] << setw(6) << hours_print[x] << setw(7) << fixed << setprecision(2) << wage_print[x]
			<< setw(9) << fixed << setprecision(2) << gross_print[x] << setw(7) << noshowpoint << bonus_print[x]
			<< setw(16) << fixed << setprecision(2) << adj_gross_print[x] << endl;

		cout << setw(15) << name_print[x] << setw(6) << hours_print[x] << setw(7) << fixed << setprecision(2) << wage_print[x]
			<< setw(9) << fixed << setprecision(2) << gross_print[x] << setw(7) << noshowpoint << bonus_print[x]
			<< setw(16) << fixed << setprecision(2) << adj_gross_print[x] << endl;
	}

	//Return value
	return;

}