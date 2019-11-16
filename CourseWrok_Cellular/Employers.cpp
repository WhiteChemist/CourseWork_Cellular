#include "Headers.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
using namespace std;

#pragma region IEmployer
Abonent IEmployer::createAbonent()
{
	Abonent emptyAbonent = Abonent::Abonent();
	cout << "Input surname:";
	string surname;
	cin >> surname;
	cout << "Input name:";
	string name;
	cin >> name;
	cout << "Input midname:";
	string midname;
	cin >> midname;
	cout << "Input phone:";
	string phone;
	cin >> phone;
	bool isYear = false;
	unsigned short int year;
	while (isYear == false)
	{
		cout << "Input year:";
		cin >> year;
		if (cin.fail())
		{
			showErrorMessage("Please correct input! \n");
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			isYear = true;
		}
	}
	cout << "Input plane:";
	string plane;
	cin >> plane;
	Abonent abonent = Abonent::Abonent();
	try
	{/*
		if ((abonent.setMidName(midname) == false && abonent.setSurname(surname) == false) && (abonent.setName(name) == false && abonent.setPhone(phone) == false) && (abonent.setPlane(plane) == false && abonent.setYear(year) == false))
	*/ 	if (Abonent::checkFieldsObject(abonent, surname, name, midname, phone, year, plane))
		return abonent;
	else
		throw string("Error creating abonent. Try again");

	}
	catch (string ex)
	{
		showErrorMessage(ex);
	}
	return emptyAbonent;
}
void IEmployer::searchPhone(vector<Abonent>* abonents, string phone)
{
	bool isFound = false;
	if (phone != "")
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].getPhone().find(phone) != string::npos)
			{
				showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + (to_string((*abonents)[i].getYear()) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
				isFound = true;

			}
		}
	}
	else
	{
		cout << "Input phone:" << endl;
		cin >> phone;
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].getPhone().find(phone) != string::npos)
			{
				showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + (to_string((*abonents)[i].getYear()) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
				isFound = true;

			}
		}
	}
	if (isFound == false)
		showErrorMessage("Abonent hasn't been found");
}

void IEmployer::outputAllAbonentsByYear(vector<Abonent>* abonents, unsigned short int year)
{
	bool isFound = false;
	if (year == 0)
	{
		int tempYear;
		cout << "Input year:" << endl;
		cin >> tempYear;
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].getYear() >= tempYear)
			{
				showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + ((to_string((*abonents)[i].getYear())) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
				isFound = true;
			}
		}
	}
	else
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].getYear() >= year)
			{
				showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + (to_string((*abonents)[i].getYear()) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
				isFound = true;
			}
		}
	}
	if (isFound == false)
	{
		showErrorMessage("Abonents hasn't been found!");
	}
}
void IEmployer::searchSurname(vector<Abonent>* abonents, string surname)
{
	bool isFound = false;
	if (abonents->size() == 0)
	{
		showErrorMessage("Please fill file with abonents and try again");
	}
	else
	{
		if (surname != "")
			for (int i = 0; i < (*abonents).size(); i++)
			{
				if ((*abonents)[i].getSurname().find(surname) != string::npos)
				{
					showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + ((to_string((*abonents)[i].getYear())) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
					isFound = true;
				}
			}
		else
		{
			cout << "Input surname:" << endl;
			cin >> surname;
			for (int i = 0; i < (*abonents).size(); i++)
			{
				if ((*abonents)[i].getSurname().find(surname) != string::npos)
				{
					showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + (to_string((*abonents)[i].getYear())) + " Phone: " + (*abonents)[i].getPhone() + " Plane: " + (*abonents)[i].getPlane());
					isFound = true;
				}
			}
		}

	}
	if (isFound == false)
	{
		showErrorMessage("Abonent hasn't been found");
	}
}
void IEmployer::searchYear(vector<Abonent>* abonents, unsigned short int year)
{
	bool isFound = false;//Флаг отображает найден ли пользователь
	if (year > 0)
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].getYear() == year)
			{
				showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + ((to_string((*abonents)[i].getYear())) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
				isFound = true;
			}
		}
	}
	else
	{
		cout << "Input year:" << endl;
		cin >> year;
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].getYear() == year)
			{
				showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + ((to_string((*abonents)[i].getYear())) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
				isFound = true;
			}
		}
	}
	if (isFound == false)
		showErrorMessage("Abonent hasn't been found");
}
void IEmployer::showAllAbonents(vector<Abonent>* abonents)
{
	setlocale(LC_ALL, "Russian");

	if ((*abonents).size() == 0)
	{
		showErrorMessage("List abonents is empty!");
	}
	else
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{


			showOutputMessage(("Surname: " + (*abonents)[i].getSurname() + " Name: " + (*abonents)[i].getName() + " MidName: " + (*abonents)[i].getMidName() + " Year: ") + (to_string((*abonents)[i].getYear()) + " Phone: " + (*abonents)[i].getPhone() + " Plane: ") + (*abonents)[i].getPlane());
		}
	}
}
void IEmployer::sortSurname(vector<Abonent>* abonents)
{
	if (abonents->size() == 0)
	{
		showErrorMessage("Abonents not found! Please fill file and try again");
	}
	else
		for (int i = 0; i < (*abonents).size(); i++)
		{
			for (int j = 0; j < (*abonents).size(); j++)
			{
				if ((*abonents)[i].getSurname() < (*abonents)[j].getSurname())
				{
					swap((*abonents)[i], (*abonents)[j]);
				}
			}
		}
}
void IEmployer::sortYear(vector<Abonent>* abonents)
{
	try
	{
		if (abonents->size() == 0)
		{
			showErrorMessage("Abonents not found! Please fill file and try again");
		}
		else
			for (int i = 0; i < (*abonents).size(); i++)
			{
				for (int j = 0; j < (*abonents).size(); j++)
				{
					if ((*abonents)[i].getYear() < (*abonents)[j].getYear())
					{
						swap((*abonents)[i], (*abonents)[j]);
					}
				}
			}
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
void IEmployer::getAbonents(vector<Abonent>* abonents, string path)
{
	auto temp = new Abonent[getCountAbonents(path)];
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < getCountAbonents(path); i++)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						(*abonents).push_back(temp[i]);
						i++;

					}
					else if (line.find("Surname:") != std::string::npos)
					{
						temp[i].setSurname(line.substr(_countof("Surname:") - 1, line.capacity()));//делаем -1 т.к. не считывает первый символ фамилии

					}
					else if (line.find("Name:") != std::string::npos)
					{
						temp[i].setName(line.substr(_countof("Name:") - 1, line.capacity()));

					}
					else if (line.find("Midname:") != std::string::npos)
					{
						temp[i].setMidName(line.substr(_countof("Midname:") - 1, line.capacity()));

					}
					else if (line.find("Year:") != std::string::npos)
					{
						temp[i].setYear(std::stoi(line.substr(_countof("Year:") - 1, line.capacity())));

					}
					else if (line.find("Phone:") != std::string::npos)
					{
						temp[i].setPhone(line.substr(_countof("Phone:") - 1, line.capacity()));

					}
					else if (line.find("Plane:") != std::string::npos)
					{
						temp[i].setPlane(line.substr(_countof("Plane:") - 1, line.capacity()));
					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
string IEmployer::getLogin()
{
	return this->login;
}
string IEmployer::getPassword()
{
	return this->password;
}
void IEmployer::setLogin(string login)
{
	this->login = login;
}
void IEmployer::setPassword(string password)
{
	this->password = password;
}
void IEmployer::setStatus(string status)
{
	this->status = status;
}
string IEmployer::getStatus()
{
	return this->status;
}
IEmployer::IEmployer() {}
IEmployer::IEmployer(string login, string password, string status)
{
	this->login = login;
	this->password = password;
	this->status = status;
}
int IEmployer::getCountAbonents(string path)
{
	int count = 0;
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.find("*") != std::string::npos)
				{
					count++;
				}
			}
		}
		file.close();
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}
	return count;
}
IEmployer::~IEmployer()
{

}
void IEmployer::showInterface() {}
#pragma endregion
#pragma region Employer
Employer::Employer() {
	abonents = new vector<Abonent>();
}

Employer::Employer(string login, string password, string status) :IEmployer(login, password, status)
{
	string path;
	cout << "Input path abonents:";
	cin >> path;
	this->pathAbonents = path;
	abonents = new vector<Abonent>();
	getAbonents(abonents, pathAbonents);
}
Employer::Employer(string login, string password, string status, bool isAbonent) :IEmployer(login, password, status)
{
	if (isAbonent == true)
	{
		string path;
		cout << "Input path abonents:";
		cin >> path;
		this->pathAbonents = path;
		abonents = new vector<Abonent>();
		getAbonents(abonents, pathAbonents);
	}
	else
	{
		abonents = new vector<Abonent>();
	}
}
Employer::~Employer()
{
	abonents->clear();
}
void Employer::writeInFileAbonent(string path, Abonent abonent)
{
	try
	{
		ofstream file;
		file.open(path, ios::app);
		if (file.is_open())
		{
			file << "Surname:" << abonent.getSurname() << endl;
			file << "Name:" << abonent.getName() << endl;
			file << "Midname:" << abonent.getMidName() << endl;
			file << "Phone:" << abonent.getPhone() << endl;
			file << "Year:" << abonent.getYear() << endl;
			file << "Plane:" << abonent.getPlane() << endl;
			file << "*" << endl;
		}
		file.close();
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
void Employer::showInterface()
{
	Abonent tempabonent;
	bool isExit = false;
	int switcher=0;
	while (isExit == false)
	{
		showInfoMessage("--------------------------------------------------------------------------");
		showInfoMessage("--------------------------User--------------------------------------------");
		showInfoMessage("--------------------------------------------------------------------------");
		cout << "0.Exit." << endl;
		cout << "1.Create new abonent." << endl;
		cout << "2.Sort by surname." << endl;
		cout << "3.Sort by year." << endl;
		cout << "4.Search by surname." << endl;
		cout << "5.Search by phone." << endl;
		cout << "6.Search by year." << endl;
		cout << "7.Show all abonents." << endl;
		switcher = CorrectInput(switcher);
		switch (switcher)
		{
		case 0:
			isExit = true;
			break;
		case 1:
			Write(pathAbonents);
			abonents->clear();
			getAbonents(abonents, pathAbonents);
			break;
		case 2:
			sortSurname(abonents);
			break;
		case 3:
			sortYear(abonents);
			break;
		case 4:
			searchSurname(abonents, "");
			break;
		case 5:
			searchPhone(abonents, "");
			break;
		case 6:
			searchYear(abonents, 0);
			break;
		case 7:
			showAllAbonents(abonents);
			break;
		default:
			showErrorMessage("Please input correct value");
			break;
		}
	}
}

#pragma endregion
#pragma region Administrator
Employer Administrator::createNewEmployer()
{
	Employer employer;
	string login;
	string password;
	cout << "Input Login:";
	cin >> login;
	employer.setLogin(login);
	cout << endl << "Input Password:";
	cin >> password;
	employer.setPassword(password);
	string status;
	cout << "Input Status:" << endl;
	cin >> status;
	employer.setStatus(status);
	return employer;
}
void Employer::Write(string path) {

	Abonent temp = createAbonent();
	if (formatMatching(temp) == true)
	{
		writeInFileAbonent(path, temp);
	}
	else
	{
		showErrorMessage("Error format matching");
	}
}
bool Employer::formatMatching(Abonent abonent)
{
	vector<bool>* checkAbonent = new vector<bool>();
	(*checkAbonent).push_back(checkValidSurname(abonent.getSurname(), "[^0-9]{1,20}", 20));
	(*checkAbonent).push_back(checkValidName(abonent.getName(), "[^0-9]{1,30}", 30));
	(*checkAbonent).push_back(checkValidMidName(abonent.getMidName(), "[^0-9]{1,30}", 30));
	(*checkAbonent).push_back(checkValidYear(abonent.getYear(), "[0-9]{4}"));
	(*checkAbonent).push_back(checkValidPhoneNumber(abonent.getPhone(), "[0-9]{3}\\([0-9]{2}\\)[0-9]{3}-[0-9]{2}-[0-9]{2}", "\\+[0-9]{3}\\([0-9]{2}\\)[0-9]{3}-[0-9]{2}-[0-9]{2}"));
	(*checkAbonent).push_back(checkValidPlane(abonent.getPlane(), "[^0-9]{1,20}", 20));
	for (int i = 0; i < (*checkAbonent).size(); i++)
	{
		if ((*checkAbonent)[i] == false)
		{
			return false;
			break;
		}
	}
	(*checkAbonent).clear();//освобождаем память
	return true;
}
void Administrator::showEmployers(vector<Employer>* admemployers)
{
	if ((*admemployers).size() != 0)
	{
		for (int i = 0; i < (*admemployers).size(); i++)
		{
			showOutputMessage(("Login: " + (*admemployers)[i].getLogin() + " ") + ("Password: " + (*admemployers)[i].getPassword() + " ") + ("Status: " + (*admemployers)[i].getStatus()));
		}

	}
	else
	{
		showErrorMessage("Please fill employers from file and repeat again");
	}

}
void Administrator::deleteEmployer(vector<Employer>* admemployers)
{
	bool isFound = false;
	string login;
	cout << "Input login:" << ends;
	cin >> login;
	if ((*admemployers).size() != 0)
	{
		for (int i = 0; i < (*admemployers).size(); i++)
		{
			if ((*admemployers)[i].getLogin() == login)
			{
				isFound = true;
				(*admemployers).erase((*admemployers).begin() + i);
				rewriteEmployers(admemployers);
				showInfoMessage("Employer has been deleted");
				break;
			}
		}
	}
	else
	{
		showErrorMessage("Please fill vector with employers and will try again");
	}
	if (isFound == false)
		showErrorMessage("Employer has not been found");
}
void Administrator::deleteEmployer(vector<Employer>* admemployers, string login)
{
	bool isFound = false;
	if (login != "")
	{
		if ((*admemployers).size() != 0)
		{
			for (int i = 0; i < (*admemployers).size(); i++)
			{
				if ((*admemployers)[i].getLogin() == login)
				{
					isFound = true;
					(*admemployers).erase((*admemployers).begin() + i);
					rewriteEmployers(admemployers);
					break;
				}
			}
		}
		else
		{
			showErrorMessage("Please fill vector with employers and will try again");
		}
	}
	else
	{
		showErrorMessage("Login must not be empty");
	}
	if (isFound == false)
		showErrorMessage("Employer has not been found");
}
unsigned short int Administrator::getCountEmployers(string path)
{
	unsigned short int count = 0;
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.find("*") != std::string::npos)
				{
					count++;
				}
			}
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		showErrorMessage(ex.what());
	}
	return count;
}
void Administrator::getEmployers(vector<Employer>* admemployers, string path)
{
	Employer* temp;
	string login;
	string password;
	string status;
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < getCountEmployers(path);)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						temp = new Employer(login, password, status, false);
						(*admemployers).push_back((*temp));
						temp++;
						i++;
					}
					else if (line.find("Login") != string::npos)
					{
						login = line.substr(_countof("Login:") - 1, line.capacity());//äåëàåì -1 ò.ê. íå ñ÷èòûâàåò ïåðâûé ñèìâîë ôàìèëèè
					}
					else if (line.find("Password:") != string::npos)
					{
						password = line.substr(_countof("Password:") - 1, line.capacity());
					}
					else if (line.find("Status:") != string::npos)
					{
						status = line.substr(_countof("Status:") - 1, line.capacity());
					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
Administrator::Administrator(string login, string password, string status) :IEmployer(login, password, status)
{
	try
	{
		cout << "Identify path to file with employers" << endl;
		string pathEmployers;
		cin >> pathEmployers;
		cout << "Identify path to file with abonents" << endl;
		string pathAbonents;
		cin >> pathAbonents;
		if (pathAbonents != "" && pathEmployers != "")
		{
			this->pathAbonents = pathAbonents;
			this->pathEmployers = pathEmployers;
		}
		abonents = new vector<Abonent>();
		admemployers = new vector<Employer>();
		getAbonents(abonents, pathAbonents);
		getEmployers(admemployers, pathEmployers);
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}

}
void Administrator::writeInFileAbonent(string path, Abonent abonent)
{
	try
	{
		if (Abonent::isNullObject(abonent) == true)
		{
			showErrorMessage("Error creating abonent! Please try again");
		}
		else
		{
			ofstream file;
			file.open(path, ios_base::app);
			if (file.is_open())
			{
				file << "Surname:" << abonent.getSurname() << endl;
				file << "Name:" << abonent.getName() << endl;
				file << "Midname:" << abonent.getMidName() << endl;
				file << "Phone:" << abonent.getPhone() << endl;
				file << "Year:" << abonent.getYear() << endl;
				file << "Plane:" << abonent.getPlane() << endl;
				file << "*" << endl;
			}

		}
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
void Administrator::writeInFileEmployer(string path, Employer employer)
{
	try
	{
		ofstream file;
		file.open(path, ios::app);
		if (file.is_open())
		{
			file << "Login:" << employer.getLogin() << endl;
			file << "Password:" << employer.getPassword() << endl;
			file << "Status:" << employer.getStatus() << endl;
			file << "*" << endl;
		}
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
void Administrator::showInterface()
{
	bool isExit = false;
	while (isExit == false)
	{
		int switcher=0;
		showInfoMessage("--------------------------------------------------------------------------");
		showInfoMessage("--------------------------Administrator-----------------------------------");
		showInfoMessage("--------------------------------------------------------------------------");
		cout << "0. Exit." << endl;
		cout << "1. Create new employer." << endl;
		cout << "2. Create new abonents." << endl;
		cout << "3. Show all abonents." << endl;
		cout << "4. Show all employers." << endl;
		cout << "5. Delete employer." << endl;
		cout << "6. Delete abonent." << endl;
		cout << "7. Override path to file with abonents." << endl;
		cout << "8. Override path to file with employers." << endl;
		cout << "9.Sort by surname." << endl;
		cout << "10.Sort by year." << endl;
		cout << "11.Search by surname." << endl;
		cout << "12.Search by phone." << endl;
		cout << "13.Search by year." << endl;
		cout << "14.Show all abonents by year" << endl;
		switcher = CorrectInput(switcher);
		switch (switcher)
		{
		default:
			showErrorMessage("Please input correct value");
			break;
		case 0:
			isExit = true;
			break;
		case 1:
			writeInFileEmployer(pathEmployers, createNewEmployer());
			admemployers->clear();
			getEmployers(admemployers, pathEmployers);
			break;
		case 2:
			writeInFileAbonent(pathAbonents, createAbonent());
			abonents->clear();
			getAbonents(abonents, pathAbonents);
			break;
		case 3:
			showAllAbonents(abonents);
			break;
		case 4:
			showEmployers(admemployers);
			break;
		case 5:
			deleteEmployer(admemployers);
			rewriteEmployers(admemployers);
			break;
		case 6:
			DeleteAbonent(abonents);
			break;
		case 7:
			setPathAbonents();
			break;
		case 8:
			setPathEmployers();
			break;
		case 9:
			sortSurname(abonents);
			break;
		case 10:
			sortYear(abonents);
			break;
		case 11:
			searchSurname(abonents, "");//можем передавать пустую строку чтобы в последствии ее внести
			break;
		case 12:
			searchPhone(abonents, "");
			break;
		case 13:
			searchYear(abonents, 0);//можем передавать 0 чтобы в последствии его ввести
			break;
		case 14:
			outputAllAbonentsByYear(abonents, 0);
			break;
		}
	}
}
int CorrectInput(int variable)
{
	cout << "Make a choice:";
	cin >> variable;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		showErrorMessage("You can only enter numbers.");
		cout << "Make a choice:";
		cin >> variable;
	}
	return variable;
}
bool Administrator::checkOnValidLogin(string login, string path)
{
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.find(login) != std::string::npos)
				{
					return true;
					break;

				}
			}
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		showErrorMessage(ex.what());
	}
	return false;
}
void Administrator::deleteAbonentByPhone()
{
	bool isFound = false;
	string phone;
	cout << "Input phone:" << ends;
	cin >> phone;
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].getPhone() == phone)
		{
			isFound = true;
			(*abonents).erase((*abonents).begin() + i);
			rewriteAbonents(abonents);
			break;
		}
		else
		{
			isFound = false;
		}
	}
	if (isFound == false)
		showErrorMessage("Abonent hasn't been found");
}
void Administrator::deleteAbonentByPhone(string phone)
{
	bool isFound = false;
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].getPhone() == phone)
		{
			isFound = true;
			(*abonents).erase((*abonents).begin() + i);
			rewriteAbonents(abonents);
			break;
		}
		else
		{
			isFound = false;
		}
	}
	if (isFound == false)
		showErrorMessage("Abonent hasn't been found");
}
void Administrator::deleteAbonentBySurname()
{
	bool isFound = false;
	string surname;
	cout << "Input surname abonent:" << ends;
	cin >> surname;
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].getSurname() == surname)
		{
			isFound = true;
			(*abonents).erase((*abonents).begin() + i);
			rewriteAbonents(abonents);
			break;
		}
		else
		{
			isFound = false;
		}
	}
	if (isFound == false)
		showErrorMessage("Abonent hasn't been found");
}
void Administrator::deleteAbonentBySurname(string surname)
{
	bool isFound = false;
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].getSurname() == surname)
		{
			isFound = true;
			(*abonents).erase((*abonents).begin() + i);
			rewriteAbonents(abonents);
			break;
		}
		else
		{
			isFound = false;
		}
	}
	if (isFound == false)
		showErrorMessage("Abonent hasn't been found");
}
void Administrator::rewriteAbonents(vector<Abonent>* abonents)
{
	try
	{
		ofstream file;
		file.open(pathAbonents);
		if (file.is_open())
		{
			for (int i = 0; i < (*abonents).size(); i++)
			{
				file << "Surname:" << (*abonents)[i].getSurname() << endl;
				file << "Name:" << (*abonents)[i].getName() << endl;
				file << "Midname:" << (*abonents)[i].getMidName() << endl;
				file << "Phone:" << (*abonents)[i].getPhone() << endl;
				file << "Year:" << (*abonents)[i].getYear() << endl;
				file << "Plane:" << (*abonents)[i].getPlane() << endl;
				file << "*" << endl;
			}
		}
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
void Administrator::rewriteEmployers(vector<Employer>* admemployers)
{
	try
	{
		ofstream file;
		file.open(pathEmployers, ios_base::out | ios_base::trunc);
		if (file.is_open())
		{
			for (int i = 0; i < (*admemployers).size(); i++)
			{
				file << "Login:" << (*admemployers)[i].getLogin() << endl;
				file << "Password:" << (*admemployers)[i].getPassword() << endl;
				file << "Status:" << (*admemployers)[i].getStatus() << endl;
				file << "*" << endl;
			}

		}
	}
	catch (exception & ex)
	{
		showErrorMessage(ex.what());
	}
}
void Administrator::DeleteAbonent(vector<Abonent>* abonents)
{
	if (abonents->size() == 0)
	{
		showErrorMessage("Please fill file with abonents and try again");
	}
	else
	{
		bool isExit = false;
		while (isExit == false)
		{
			int switcher_second=0;
			cout << "Make a choice:" << endl;
			cout << "0. Exit" << endl;
			cout << "1. Delete abonent by phone." << endl;
			cout << "2. Delete abonent by surname." << endl;
			switcher_second = CorrectInput(switcher_second);
			switch (switcher_second)
			{
			case 0:
				isExit = true;
				break;
			case 1:
				deleteAbonentByPhone();
				rewriteAbonents(abonents);
				break;
			case 2:
				deleteAbonentBySurname();
				rewriteAbonents(abonents);
				break;
			default:
				showErrorMessage("Incorrect input");
			}
		}
	}
}
string Administrator::getPathAbonents()
{
	return this->pathAbonents;
}
void Administrator::setPathAbonents()
{
	string path;
	cout << "Input new path:" << ends;
	cin >> path;
	if (path != "")
		this->pathAbonents = path;
}
void Administrator::setPathAbonents(string path)
{

	if (path != "")
		this->pathAbonents = path;
}
string Administrator::getPathEmployers()
{
	return this->pathEmployers;
}
void Administrator::setPathEmployers()
{
	string path;
	cout << "Input new path:" << ends;
	cin >> path;
	if (path != "")
		this->pathEmployers = path;
}
void Administrator::setPathEmployers(string path)
{
	if (path != "")
		this->pathEmployers = path;
}
void Administrator::getAbonents(vector<Abonent>* abonents, string path)
{
	Abonent* temp = new Abonent[getCountAbonents(path)];
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < getCountAbonents(path); i++)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						(*abonents).push_back(temp[i]);
						i++;

					}
					else if (line.find("Surname:") != std::string::npos)
					{
						temp[i].setSurname(line.substr(_countof("Surname:") - 1, line.capacity()));//делаем -1 т.к. не считывает первый символ фамилии

					}
					else if (line.find("Name:") != std::string::npos)
					{
						temp[i].setName(line.substr(_countof("Name:") - 1, line.capacity()));

					}
					else if (line.find("Midname:") != std::string::npos)
					{
						temp[i].setMidName(line.substr(_countof("Midname:") - 1, line.capacity()));

					}
					else if (line.find("Year:") != std::string::npos)
					{
						temp[i].setYear(std::stoi(line.substr(_countof("Year:") - 1, line.capacity())));

					}
					else if (line.find("Phone:") != std::string::npos)
					{
						temp[i].setPhone(line.substr(_countof("Phone:") - 1, line.capacity()));

					}
					else if (line.find("Plane:") != std::string::npos)
					{
						temp[i].setPlane(line.substr(_countof("Plane:") - 1, line.capacity()));
					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		showErrorMessage(ex.what());
	}
}

Administrator::~Administrator()
{
	(*abonents).clear();
	(*admemployers).clear();
}
#pragma endregion