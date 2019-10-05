#include "Headers.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#pragma region IEmployer
Abonent IEmployer::CreateAbonent()
{
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
	cout << "Input year:";
	int year;
	cin >> year;
	cout << "Input plane:";
	string plane;
	cin >> plane;
	Abonent abonent = Abonent::Abonent(surname, name, midname, phone, year, plane);
	return abonent;
}
void IEmployer::SearchPhone(vector<Abonent> abonents, string phone)
{
	if (phone != "")
	{
		for (int i = 0; i < abonents.size(); i++)
		{
			if (abonents[i].GetPhone() == phone)
				cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
				ends << abonents[i].GetYear() <<
				ends << abonents[i].GetPhone() <<
				ends << abonents[i].GetPlane() << endl;
		}
	}
	else
	{
		cout << "Input phone:" << endl;
		cin >> phone;
		for (int i = 0; i < abonents.size(); i++)
		{
			if (abonents[i].GetPhone() == phone)
				cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
				ends << abonents[i].GetYear() <<
				ends << abonents[i].GetPhone() <<
				ends << abonents[i].GetPlane() << endl;
		}
	}

}
void IEmployer::SearchSurname(vector<Abonent> abonents, string surname)
{
	if (surname != "")
		for (int i = 0; i < abonents.size(); i++)
		{
			if (abonents[i].GetSurname() == surname)
				cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
				ends << abonents[i].GetYear() <<
				ends << abonents[i].GetPhone() <<
				ends << abonents[i].GetPlane() << endl;
		}
	else
	{
		cout << "Input surname:" << endl;
		cin >> surname;
		for (int i = 0; i < abonents.size(); i++)
		{
			if (abonents[i].GetSurname() == surname)
				cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
				ends << abonents[i].GetYear() <<
				ends << abonents[i].GetPhone() <<
				ends << abonents[i].GetPlane() << endl;
		}
	}
}
void IEmployer::SearchYear(vector<Abonent> abonents, int year)
{
	if (year > 0)
	{
		for (int i = 0; i < abonents.size(); i++)
		{
			if (abonents[i].GetYear() == year)
				cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
				ends << abonents[i].GetYear() <<
				ends << abonents[i].GetPhone() <<
				ends << abonents[i].GetPlane() << endl;
		}
	}
	else
	{
		cout << "Input year:" << endl;
		cin >> year;
		for (int i = 0; i < abonents.size(); i++)
		{
			if (abonents[i].GetYear() == year)
				cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
				ends << abonents[i].GetYear() <<
				ends << abonents[i].GetPhone() <<
				ends << abonents[i].GetPlane() << endl;
		}
	}
}
void IEmployer::ShowAllAbonents(vector<Abonent> abonents)
{
	for (int i = 0; i < abonents.size(); i++)
	{
		cout << abonents[i].GetSurname() << ends << abonents[i].GetName() << ends << abonents[i].GetMidName() <<
			ends << abonents[i].GetYear() <<
			ends << abonents[i].GetPhone() <<
			ends << abonents[i].GetPlane() << endl;
	}
}
void IEmployer::SortSurname(vector<Abonent> abonents)
{
	for (int i = 0; i < abonents.size(); i++)
	{
		for (int j = 1; j < abonents.size(); j++)
		{
			auto str1 = abonents[i].GetSurname()[0];
			auto str2 = abonents[j].GetSurname()[0];
			if (str1 > str2)
			{
				auto temp = abonents[i];
				abonents[i] = abonents[j];
				abonents[j] = temp;
			}
		}
	}
	ShowAllAbonents(abonents);
}
void IEmployer::SortYear(vector<Abonent> abonents)
{
	auto sortedvector = abonents;
	for (int i = 0; i < sortedvector.size(); i++)
	{
		for (int j = 0; i < sortedvector.size(); j++)
		{
			if (sortedvector[i].GetYear() > sortedvector[j].GetYear())
			{
				auto temp = sortedvector[i];
				sortedvector[i] = sortedvector[j];
				sortedvector[j] = temp;
			}
		}
	}
	sortedvector.clear();
}
void IEmployer::GetAbonents(vector<Abonent> abonents, string path)
{
	auto temp = new Abonent[GetCountAbonents(path)];
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < GetCountAbonents(path); i++)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						abonents.push_back(temp[i]);
						i++;

					}
					else if (line.find("Surname:") != std::string::npos)
					{
						temp[i].SetSurname(line.substr(_countof("Surname:") - 1, line.capacity()));//делаем -1 т.к. не считывает первый символ фамилии

					}
					else if (line.find("Name:") != std::string::npos)
					{
						temp[i].SetName(line.substr(_countof("Name:") - 1, line.capacity()));

					}
					else if (line.find("MidName:") != std::string::npos)
					{
						temp[i].SetMidName(line.substr(_countof("MidName:") - 1, line.capacity()));

					}
					else if (line.find("Year:") != std::string::npos)
					{
						temp[i].SetYear(std::stoi(line.substr(_countof("Year:") - 1, line.capacity())));

					}
					else if (line.find("Phone:") != std::string::npos)
					{
						temp[i].SetPhone(line.substr(_countof("Phone:") - 1, line.capacity()));

					}
					else if (line.find("Plane:") != std::string::npos)
					{
						temp[i].SetPlane(line.substr(_countof("Plane:") - 1, line.capacity()));
					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
string IEmployer::GetLogin()
{
	return this->login;
}
string IEmployer::GetPassword()
{
	return this->password;
}
void IEmployer::SetLogin(string login)
{
	this->login = login;
}
void IEmployer::SetPassword(string password)
{
	this->password = password;
}
IEmployer::IEmployer() {}
IEmployer::IEmployer(string login, string password)
{
	this->login = login;
	this->password = password;
}
int IEmployer::GetCountAbonents(string path)
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
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
IEmployer::~IEmployer()
{

}
void IEmployer::InteractionInterface() {}
#pragma endregion
#pragma region Employer
Employer::Employer() {}
Employer::Employer(string login, string password) :IEmployer(login, password) {};
Employer::~Employer()
{

}
void Employer::InteractionInterface()
{
	bool isExit = false;
	int switcher;
	while (isExit == false)
	{
		cout << "Please make a choice:" << endl;
		cout << "0.Exit." << endl;
		cout << "1.Create new abonent." << endl;
		cout << "2.Sort by surname." << endl;
		cout << "3.Sort by year." << endl;
		cout << "4.Search by surname." << endl;
		cout << "5.Search by phone." << endl;
		cout << "6.Search by year." << endl;
		cin >> switcher;
		switch (switcher)
		{
		case 0:
			isExit = true;
			break;
		case 1:
			abonents.push_back(CreateAbonent());
			break;
		case 2:
			SortSurname(abonents);
			break;
		case 3:
			SortYear(abonents);
			break;
		case 4:
			SearchSurname(abonents, "");
				break;
		case 5:
			SearchPhone(abonents, "");
			break;
		case 6:
			SearchYear(abonents, 0);
			break;
		default:
			cout << "Please input correct value" << endl;
			break;
		}
	}
}
#pragma endregion
#pragma region Administrator
Employer Administrator::CreateNewEmployer()
{
	Employer employer;
	string login;
	string password;
	cout << "Input Login:";
	cin >> login;
	employer.SetLogin(login);
	cout << endl << "Input Password:";
	cin >> password;
	employer.SetPassword(password);
	return employer;
}
void Administrator::ShowEmployers(vector<Employer> employers)
{
	if (employers.size() != 0)
	{
		for (int i = 0; i < employers.size(); i++)
		{
			cout << "Login:" << employers[i].GetLogin() << ends << "Password:" << employers[i].GetPassword() << endl;
		}
	}
	else
	{
		cout << "Please fill employers from file and repeat again" << endl;
	}

}
void Administrator::DeleteEmployer(vector<Employer> employers)
{
	string login;
	cout << "Input login:" << ends;
	if (employers.size() != 0)
	{
		for (int i = 0; i < employers.size(); i++)
		{
			if (employers[i].GetLogin() == login)
			{
				employers.erase(employers.begin() + i);
				RewriteEmployers(employers);
				cout << "Employer has been deleted" << endl;
			}
		}
	}
	else
	{
		cout << "Please fill vector with employers and will try again" << endl;
	}

}
void Administrator::DeleteEmployer(vector<Employer> employers, string login)
{
	if (employers.size() != 0)
	{
		for (int i = 0; i < employers.size(); i++)
		{
			if (employers[i].GetLogin() == login)
			{
				employers.erase(employers.begin() + i);
				RewriteEmployers(employers);
			}
		}
	}
	else
	{
		cout << "Please fill vector with employers and will try again" << endl;
	}

}
void Administrator::GetEmployers(vector<Employer> employers, string path)
{
	auto temp = new Employer[GetCountEmployers(path)];
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < GetCountEmployers(path); i++)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						employers.push_back(temp[i]);
						i++;

					}
					else if (line.find("Login") != string::npos)
					{
						temp[i].SetLogin(line.substr(_countof("Login:") - 1, line.capacity()));//делаем -1 т.к. не считывает первый символ фамилии
					}
					else if (line.find("Password:") != string::npos)
					{
						temp[i].SetPassword(line.substr(_countof("Password:") - 1, line.capacity()));
					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
int Administrator::GetCountEmployers(string path)
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
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return count;
}
Administrator::Administrator(string login, string password) :IEmployer(login, password)
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
	GetAbonents(abonents, pathAbonents);
	GetEmployers(employers, pathEmployers);
}
void Administrator::WriteInFileAbonent(string path, Abonent abonent)
{
	try
	{
		ofstream file;
		file.open(path);
		if (file.is_open())
		{
			file << "Surname:" << abonent.GetSurname() << endl;
			file << "Name:" << abonent.GetName() << endl;
			file << "MidName:" << abonent.GetMidName() << endl;
			file << "Phone:" << abonent.GetPhone() << endl;
			file << "Year:" << abonent.GetYear() << endl;
			file << "Current Plane:" << abonent.GetPlane() << endl;
			file << "*" << endl;
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void Administrator::WriteInFileEmployer(string path, Employer employer)
{
	try
	{
		ofstream file;
		file.open(path);
		if (file.is_open())
		{
			file << "Login:" << employer.GetLogin() << endl;
			file << "Password:" << employer.GetPassword() << endl;
			file << "*" << endl;
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void Administrator::InteractionInterface()
{
	bool isExit = false;
	while (isExit == false)
	{
		int switcher;
		cout << "Please make a choice:" << endl;
		cout << "0. Exit." << endl;
		cout << "1.Create new employer." << endl;
		cout << "2. Create new abonents." << endl;
		cout << "3.Show all abonents." << endl;
		cout << "4. Show all employers." << endl;
		cout << "5.Delete employer." << endl;
		cout << "6. Delete abonent." << endl;
		cout << "7. Override path to file with abonents." << endl;
		cout << "8. Override path to file with employers." << endl;
		cin >> switcher;
		switch (switcher)
		{
		case 0:
			isExit = true;
			break;
		case 1:
			employers.push_back(CreateNewEmployer());
			break;
		case 2:
			abonents.push_back(CreateAbonent());
			break;
		case 3:
			ShowAllAbonents(abonents);
			break;
		case 4:
			ShowEmployers(employers);
			break;
		case 5:
			DeleteEmployer(employers);
			RewriteEmployers(employers);
			break;
		case 6:
			int switcher_second;
			cout << "Make a choice:" << endl;
			cout << "1. Delete abonent by phone." << endl;
			cout << "2. Delete abonent by surname." << endl;
			switch (switcher_second)
			{
			case 1:
				DeleteAbonentByPhone();
				RewriteAbonents(abonents);
				break;
			case 2:
				DeleteAbonentBySurname();
				RewriteAbonents(abonents);
				break;
			default:
				cout << "Incorrect input!" << endl;
				break;
			}
			break;
		case 7:
			SetPathAbonents();
			break;
		case 8:
			SetPathEmployers();
			break;
		default:
			cout << "Please input correct value" << endl;
			break;
		}
	}
}
bool Administrator::CheckOnValidLogin(string login, string path)
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
					break;
					return true;

				}
			}
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return false;
}
void Administrator::DeleteAbonentByPhone()
{
	string phone;
	cout << "Input phone:" << ends;
	cin >> phone;
	for (int i = 0; i < this->abonents.size(); i++)
	{
		if (abonents[i].GetPhone() == phone)
		{
			abonents.erase(abonents.begin() + i);
			RewriteAbonents(abonents);
		}
	}
}
void Administrator::DeleteAbonentByPhone(string phone)
{
	for (int i = 0; i < this->abonents.size(); i++)
	{
		if (abonents[i].GetPhone() == phone)
		{
			abonents.erase(abonents.begin() + i);
			RewriteAbonents(abonents);
		}
	}
}
void Administrator::DeleteAbonentBySurname()
{
	string surname;
	cout << "Input surname abonent:" << ends;
	cin >> surname;
	for (int i = 0; i < this->abonents.size(); i++)
	{
		if (abonents[i].GetSurname() == surname)
		{
			abonents.erase(abonents.begin() + i);
			RewriteAbonents(abonents);
		}

	}
}
void Administrator::DeleteAbonentBySurname(string surname)
{
	for (int i = 0; i < this->abonents.size(); i++)
	{
		if (abonents[i].GetSurname() == surname)
		{
			abonents.erase(abonents.begin() + i);
			RewriteAbonents(abonents);
		}

	}
}
void Administrator::RewriteAbonents(vector<Abonent> abonents)
{
	try
	{
		ofstream file;
		file.open(pathAbonents);
		if (file.is_open())
		{
			for (int i = 0; i < abonents.size(); i++)
			{
				file << "Surname:" << abonents[i].GetSurname() << endl;
				file << "Name:" << abonents[i].GetName() << endl;
				file << "MidName:" << abonents[i].GetMidName() << endl;
				file << "Phone:" << abonents[i].GetPhone() << endl;
				file << "Year:" << abonents[i].GetYear() << endl;
				file << "Current Plane:" << abonents[i].GetPlane() << endl;
				file << "*" << endl;
			}
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void Administrator::RewriteEmployers(vector<Employer> employers)
{
	try
	{
		ofstream file;
		file.open(pathEmployers, ios_base::out | ios_base::trunc);
		if (file.is_open())
		{
			for (int i = 0; i < employers.size(); i++)
			{
				file << "Login:" << employers[i].GetLogin() << endl;
				file << "Password:" << employers[i].GetPassword() << endl;
				file << "*" << endl;
			}

		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
string Administrator::GetPathAbonents()
{
	return this->pathAbonents;
}
void Administrator::SetPathAbonents()
{
	string path;
	cout << "Input new path:" << ends;
	cin >> path;
	if (path != "")
		this->pathAbonents = path;
}
void Administrator::SetPathAbonents(string path)
{

	if (path != "")
		this->pathAbonents = path;
}
string Administrator::GetPathEmployers()
{
	return this->pathEmployers;
}
void Administrator::SetPathEmployers()
{
	string path;
	cout << "Input new path:" << ends;
	cin >> path;
	if (path != "")
		this->pathEmployers = path;
}
void Administrator::SetPathEmployers(string path)
{
	if (path != "")
		this->pathEmployers = path;
}
Administrator::~Administrator()
{
	abonents.clear();
	employers.clear();
}
#pragma endregion