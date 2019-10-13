#include "Headers.h"
#include <iostream>
#include <fstream>
using namespace std;

void checkInput(string path)
{
	string login;
	cout << "Input your login:";
	cin >> login;
	string password;
	cout << "Input your password:";
	cin >> password;
	vector<Employer>* employers = new vector <Employer>();
	Administrator::getEmployers(employers, path);
	for (int i = 0; i < (*employers).size(); i++)
	{
		if ((*employers)[i].getLogin() == login && (*employers)[i].getPassword() == password && (*employers)[i].getStatus() == "admin")
		{
			Administrator* administrator = new Administrator((*employers)[i].getLogin(), (*employers)[i].getPassword(), (*employers)[i].getStatus());
			administrator->showInterface();
		}
		else if ((*employers)[i].getLogin() == login && (*employers)[i].getPassword() == password && (*employers)[i].getStatus() == "employer")
		{
			Employer* employer = new Employer((*employers)[i].getLogin(), (*employers)[i].getPassword(), (*employers)[i].getStatus());
			employer->showInterface();
		}
	}
}
