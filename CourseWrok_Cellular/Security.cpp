#include "Headers.h"
#include <iostream>
#include <fstream>
using namespace std;

void CheckInput(string path)
{
	int counter=0;
	cout << "Input login:";
	string login;
	cin >> login;
	cout << endl << "Input password:";
	string password;
	cin >> password;
	try
	{
		std::string line;

		std::ifstream in(path); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, line))
			{
				if (line.find(login)!=string::npos)
				{
					counter++;
				}
				else if (line.find(password) != string::npos)
				{
					counter++;
				}
			}
		}
		in.close();     // закрываем файл
		if (counter / 2 == 0)
		{
			
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
