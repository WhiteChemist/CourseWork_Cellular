#include "Headers.h"
#include <iostream>
#include <fstream>
using namespace std;

void CheckInput(string path)
{
	int counter = 0;
	bool isAdmin = false;
	bool validLogin = false;
	bool validPassword = false;
	cout << "Input login:";
	string login;
	cin >> login;
	cout << endl << "Input password:";
	string password;
	cin >> password;
	string status;
	cout << endl << "Input status:";
	cin >> status;
	try
	{
		std::string line;

		std::ifstream in(path); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, line))
			{
				if (line.find(login) != string::npos)
					validLogin = true;
				else if (line.find(password) != string::npos)
					validPassword = true;
				else if (line.find(status) != string::npos && status == "admin")
					isAdmin = true;
				else if (line.find(status) != string::npos && status == "employer")
				{
					isAdmin = false;
				}
			}
		}
		in.close();     // закрываем файл
		if (validLogin == true && validPassword == true && isAdmin == true)
		{
			Administrator admin = Administrator(login, password, status);
			admin.InteractionInterface();
		}
		else if (validLogin == true && validPassword == true && isAdmin == false)
		{
			Employer employer = Employer(login, password, status);
			employer.InteractionInterface();
		}
		else
		{
			cout << "User is not found" << endl;
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
