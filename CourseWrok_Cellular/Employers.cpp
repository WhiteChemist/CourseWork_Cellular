#include "Headers.h"
#include <iostream>
#include <vector>
#include <Windows.h>
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
void IEmployer::SearchPhone(vector<Abonent>* abonents, string phone)
{
	if (phone != "")
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].GetPhone() == phone)
				OutputMessage(("Surname: " + (*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	}
	else
	{
		cout << "Input phone:" << endl;
		cin >> phone;
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].GetPhone() == phone)
				OutputMessage(("Surname: " + (*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	}

}
void IEmployer::SearchSurname(vector<Abonent>* abonents, string surname)
{
	if (surname != "")
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].GetSurname() == surname)
				OutputMessage(("Surname: " + (*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	else
	{
		cout << "Input surname:" << endl;
		cin >> surname;
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].GetSurname() == surname)
				OutputMessage(("Surname: "+(*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	}
}
void IEmployer::SearchYear(vector<Abonent>* abonents, int year)
{
	if (year > 0)
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].GetYear() == year)
				OutputMessage(("Surname: "+(*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	}
	else
	{
		cout << "Input year:" << endl;
		cin >> year;
		for (int i = 0; i < (*abonents).size(); i++)
		{
			if ((*abonents)[i].GetYear() == year)
				OutputMessage(("Surname: "+(*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	}
}
void IEmployer::ShowAllAbonents(vector<Abonent>* abonents)
{
	setlocale(LC_ALL, "Russian");
	if ((*abonents).size() == 0)
	{
		ErrorMessage("Список абонентов пустой!");
	}
	else
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			OutputMessage(("Surname: " + (*abonents)[i].GetSurname() + " Name: " + (*abonents)[i].GetName() + " MidName: " + (*abonents)[i].GetMidName() + " Year: ") + ((*abonents)[i].GetYear() + " Phone: " + (*abonents)[i].GetPhone() + " Plane: ") + (*abonents)[i].GetPlane());
		}
	}
}
void IEmployer::SortSurname(vector<Abonent>* abonents)
{
	for (int i = 0; i < (*abonents).size(); i++)
	{
		for (int j = 0; j < (*abonents).size(); j++)
		{
			if ((*abonents)[i].GetSurname()<(*abonents)[j].GetSurname())
			{
				swap((*abonents)[i], (*abonents)[j]);
			}
		}
	}
}
void IEmployer::SortYear(vector<Abonent>* abonents)
{
	try
	{
		for (int i = 0; i < (*abonents).size(); i++)
		{
			for (int j = 0; j < (*abonents).size(); j++)
			{
				if ((*abonents)[i].GetYear() < (*abonents)[j].GetYear())
				{
					swap((*abonents)[i], (*abonents)[j]);
				}
			}
		}
	}
	catch (exception& ex)
	{
		ErrorMessage(ex.what());
	}
}
void IEmployer::GetAbonents(vector<Abonent>* abonents, string path)
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
						(*abonents).push_back(temp[i]);
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
		ErrorMessage(ex.what());
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
void IEmployer::SetStatus(string status)
{
	this->status = status;
}
string IEmployer::GetStatus()
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
	return count;
}
IEmployer::~IEmployer()
{

}
void IEmployer::InteractionInterface() {}
#pragma endregion
#pragma region Employer
Employer::Employer() {}
Employer::Employer(string login, string password, string status) :IEmployer(login, password, status)
{
	string path;
	cout << "Input path abonents:";
	cin >> path;
	this->pathAbonents = path;
	abonents = new vector<Abonent>();
	GetAbonents(abonents, pathAbonents);
}
Employer::~Employer()
{

}
void Employer::WriteInFileAbonent(string path, Abonent abonent)
{
	try
	{
		ofstream file;
		file.open(path, ios::app);
		if (file.is_open())
		{
			file << "Surname:" << abonent.GetSurname() << endl;
			file << "Name:" << abonent.GetName() << endl;
			file << "MidName:" << abonent.GetMidName() << endl;
			file << "Phone:" << abonent.GetPhone() << endl;
			file << "Year:" << abonent.GetYear() << endl;
			file << "Plane:" << abonent.GetPlane() << endl;
			file << "*" << endl;
		}
		file.close();
	}
	catch (exception& ex)
	{
		ErrorMessage(ex.what());
	}
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
		cout << "7.Show all abonents." << endl;
		cin >> switcher;
		switch (switcher)
		{
		case 0:
			isExit = true;

		case 1:
			WriteInFileAbonent(pathAbonents, CreateAbonent());
			GetAbonents(abonents, pathAbonents);
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
		case 7:
			ShowAllAbonents(abonents);
			break;
		default:
			ErrorMessage("Please input correct value");
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
	string status;
	cout << "Input Status:" << endl;
	cin >> status;
	employer.SetStatus(status);
	return employer;
}
void Administrator::ShowEmployers(vector<Employer>* admemployers)
{
	if ((*admemployers).size() != 0)
	{
		for (int i = 0; i < (*admemployers).size(); i++)
		{
			OutputMessage(("Login: " + (*admemployers)[i].GetLogin() + " ") + ("Password: " + (*admemployers)[i].GetPassword() + " ") + ("Status: " + (*admemployers)[i].GetStatus()));
		}
		
	}
	else
	{
		ErrorMessage("Please fill employers from file and repeat again");
	}

}
void Administrator::DeleteEmployer(vector<Employer>* admemployers)
{
	string login;
	cout << "Input login:" << ends;
	if ((*admemployers).size() != 0)
	{
		for (int i = 0; i < (*admemployers).size(); i++)
		{
			if ((*admemployers)[i].GetLogin() == login)
			{
				(*admemployers).erase((*admemployers).begin() + i);
				RewriteEmployers(admemployers);
				InfoMessage("Employer has been deleted");
			}
		}
	}
	else
	{
		ErrorMessage("Please fill vector with employers and will try again");
	}

}
void Administrator::DeleteEmployer(vector<Employer>* admemployers, string login)
{
	if ((*admemployers).size() != 0)
	{
		for (int i = 0; i < (*admemployers).size(); i++)
		{
			if ((*admemployers)[i].GetLogin() == login)
			{
				(*admemployers).erase((*admemployers).begin() + i);
				RewriteEmployers(admemployers);
			}
		}
	}
	else
	{
		ErrorMessage("Please fill vector with employers and will try again");
	}

}
void Administrator::GetEmployers(vector<Employer>(*admemployers), string path)
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
						(*admemployers).push_back(temp[i]);
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
					else if (line.find("Status:") != string::npos)
					{
						temp[i].SetStatus(line.substr(_countof("Status:") - 1, line.capacity()));
					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		ErrorMessage(ex.what());
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
		ErrorMessage(ex.what());
	}
	return count;
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
		GetAbonents(abonents, pathAbonents);
		GetEmployers(admemployers, pathEmployers);
	}
	catch (exception& ex)
	{
		ErrorMessage(ex.what());
	}

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
		ErrorMessage(ex.what());
	}
}
void Administrator::WriteInFileEmployer(string path, Employer employer)
{
	try
	{
		ofstream file;
		file.open(path, ios::app);
		if (file.is_open())
		{
			file << "Login:" << employer.GetLogin() << endl;
			file << "Password:" << employer.GetPassword() << endl;
			file << "Status:" << employer.GetStatus() << endl;
			file << "*" << endl;
		}
	}
	catch (exception& ex)
	{
		ErrorMessage(ex.what());
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
		cin >> switcher;
		switch (switcher)
		{
		case 0:
			isExit = true;
			break;
		case 1:
			WriteInFileEmployer(pathEmployers, CreateNewEmployer());
			GetEmployers(admemployers, pathEmployers);
			break;
		case 2:
			WriteInFileAbonent(pathAbonents, CreateAbonent());
			GetAbonents(abonents, pathAbonents);
			break;
		case 3:
			ShowAllAbonents(abonents);
			break;
		case 4:
			ShowEmployers(admemployers);
			break;
		case 5:
			DeleteEmployer(admemployers);
			RewriteEmployers(admemployers);
			break;
		case 6:
			int switcher_second;
			cout << "Make a choice:" << endl;
			cout << "1. Delete abonent by phone." << endl;
			cout << "2. Delete abonent by surname." << endl;
			cin >> switcher_second;
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
		case 9:
			SortSurname(abonents);
			break;
		case 10:
			SortYear(abonents);
			break;
		case 11:
			SearchSurname(abonents,"");//можем передавать пустую строку чтобы в последствии ее внести
			break;
		case 12:
			SearchPhone(abonents,"");
			break;
		case 13:
			SearchYear(abonents, 0);//можем передавать 0 чтобы в последствии его ввести
			break;
		default:
			ErrorMessage("Please input correct value");
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
		ErrorMessage(ex.what());
	}
	return false;
}
void Administrator::DeleteAbonentByPhone()
{
	string phone;
	cout << "Input phone:" << ends;
	cin >> phone;
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].GetPhone() == phone)
		{
			(*abonents).erase((*abonents).begin() + i);
			RewriteAbonents(abonents);
		}
	}
}
void Administrator::DeleteAbonentByPhone(string phone)
{
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].GetPhone() == phone)
		{
			(*abonents).erase((*abonents).begin() + i);
			RewriteAbonents(abonents);
		}
	}
}
void Administrator::DeleteAbonentBySurname()
{
	string surname;
	cout << "Input surname abonent:" << ends;
	cin >> surname;
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].GetSurname() == surname)
		{
			(*abonents).erase((*abonents).begin() + i);
			RewriteAbonents(abonents);
		}

	}
}
void Administrator::DeleteAbonentBySurname(string surname)
{
	for (int i = 0; i < (*abonents).size(); i++)
	{
		if ((*abonents)[i].GetSurname() == surname)
		{
			(*abonents).erase((*abonents).begin() + i);
			RewriteAbonents(abonents);
		}

	}
}
void Administrator::RewriteAbonents(vector<Abonent>* abonents)
{
	try
	{
		ofstream file;
		file.open(pathAbonents);
		if (file.is_open())
		{
			for (int i = 0; i < (*abonents).size(); i++)
			{
				file << "Surname:" << (*abonents)[i].GetSurname() << endl;
				file << "Name:" << (*abonents)[i].GetName() << endl;
				file << "MidName:" << (*abonents)[i].GetMidName() << endl;
				file << "Phone:" << (*abonents)[i].GetPhone() << endl;
				file << "Year:" << (*abonents)[i].GetYear() << endl;
				file << "Current Plane:" << (*abonents)[i].GetPlane() << endl;
				file << "*" << endl;
			}
		}
	}
	catch (exception& ex)
	{
		ErrorMessage(ex.what());
	}
}
void Administrator::RewriteEmployers(vector<Employer>* admemployers)
{
	try
	{
		ofstream file;
		file.open(pathEmployers, ios_base::out | ios_base::trunc);
		if (file.is_open())
		{
			for (int i = 0; i < (*admemployers).size(); i++)
			{
				file << "Login:" << (*admemployers)[i].GetLogin() << endl;
				file << "Password:" << (*admemployers)[i].GetPassword() << endl;
				file << "Status:" << (*admemployers)[i].GetStatus() << endl;
				file << "*" << endl;
			}

		}
	}
	catch (exception& ex)
	{
		ErrorMessage(ex.what());
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
void Administrator::GetAbonents(vector<Abonent>* abonents, string path)
{
	Abonent* temp = new Abonent[GetCountAbonents(path)];
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
						(*abonents).push_back(temp[i]);
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
		ErrorMessage(ex.what());
	}
}
Administrator::~Administrator()
{
	(*abonents).clear();
	(*admemployers).clear();
}
#pragma endregion