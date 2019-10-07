#include "Headers.h"
#include <iostream>
using namespace std;

void ErrorMessage(string message)
{
	cout << "\x1b[31;1m" << message << "\x1b[0m" << endl;
}
void InfoMessage(string message)
{
	cout << "\x1b[34;1m" << message << "\x1b[0m" << endl;
}
void OutputMessage(string message)
{
	try
	{
		cout << "\x1b[32;1m" << message << "\x1b[0m" << endl;

	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}