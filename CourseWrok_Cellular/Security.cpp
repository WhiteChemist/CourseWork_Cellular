#include "Headers.h"
#include <iostream>
#include <fstream>
using namespace std;

void checkInput(string path)
{
	bool isAutorize = false;
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
			isAutorize = true;
			Administrator* administrator = new Administrator((*employers)[i].getLogin(), (*employers)[i].getPassword(), (*employers)[i].getStatus());
			administrator->showInterface();
			break;
		}
		else if ((*employers)[i].getLogin() == login && (*employers)[i].getPassword() == password && (*employers)[i].getStatus() == "employer")
		{
			isAutorize = true;
			Employer* employer = new Employer((*employers)[i].getLogin(), (*employers)[i].getPassword(), (*employers)[i].getStatus());
			employer->showInterface();
			break;
		}
		else
			isAutorize = false;
	}
	if (isAutorize == false)
		showErrorMessage("Employer has not found");
}
