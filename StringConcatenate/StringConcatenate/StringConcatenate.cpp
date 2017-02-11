#include <iostream>
#include <string>
#include <exception>
using namespace std;

string concatenateString(string, string);

int main()
{

	string str1, str2;

	str1 = "Hello World!";
	str2 = "Goodbye World!";

	cout << concatenateString(str1, str1);

	cout << endl << endl;

	system("pause");

	return 0;

}

string concatenateString(string str1, string str2)
{

	string retVal;

	try
	{
		if (str1 == str2)
			throw "There strings cannot be a the same.";
		else
			retVal = str1 + str2;
	}

	catch (const char* errorMsg)
	{
		cout << errorMsg;
		retVal = "\n\nThe command could not be processed.";
	}

	return retVal;

}