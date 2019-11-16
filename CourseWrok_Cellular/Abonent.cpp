#include <iostream>
#include "Headers.h"
#include <regex>
using namespace std;
Abonent::Abonent() {};
Abonent::Abonent(string parsurname, string parname, string parmidname, string parphone, unsigned short int paryear, string parplane)
{
	setSurname(parsurname);
	setName(parname);
	setMidName(parmidname);
	setPhone(parphone);
	setYear(paryear);
	setPlane(parplane);
}
#pragma region Getters_and_Setters
const string Abonent::getSurname()
{
	return currentFIO.surname;
}
const string Abonent::getName()
{
	return currentFIO.name;
}
const string Abonent::getMidName()
{
	return currentFIO.midname;
}
const unsigned short int Abonent::getYear()
{
	return this->year;
}
const string Abonent::getPhone()
{
	return this->phone;
}
const string Abonent::getPlane()
{
	return this->current_plane;
}
bool Abonent::setSurname(string surname)
{
	if (checkValidSurname(surname,"^[A-Za-zà-ÿÀ-ß]\*\$",20))
	{
		this->currentFIO.surname = surname;
		return true;
	}
	else
	{
		showErrorMessage("Please input correct surname plane 20 character max");
		return false;
	}
}
bool Abonent::setName(string name)
{
	if (checkValidName(name,"^[A-Za-zà-ÿÀ-ß]\*\$",30))
	{
		this->currentFIO.name = name;
		return true;
	}
	else
	{
		showErrorMessage("Please input correct name plane 30 character max");
		return false;
	}
}
bool Abonent::setMidName(string midName)
{
	if (checkValidMidName(midName,"^[A-Za-zà-ÿÀ-ß]\*\$",30))
	{
		this->currentFIO.midname = midName;
		return true;
	}
	else
	{
		showErrorMessage("Please input correct middle name plane 30 character max");
		return false;
	}
}
bool Abonent::setYear(unsigned short int year)
{
	if (checkValidYear(year, "[0-9]{4}"))
	{
		this->year = year;
		return true;
	}
	else
	{
		showErrorMessage("Please input correct value in the range 0 before 9999 and try again");
		return false;
	}
}

bool Abonent::setPhone(string phone)
{
	if (checkValidPhoneNumber(phone, "[0-9]{3}\\([0-9]{2}\\)[0-9]{3}\-[0-9]{2}\-[0-9]{2}")||checkValidPhoneNumber(phone,"\\+[0-9]{3}\\([0-9]{2}\\)[0-9]{3}-[0-9]{2}-[0-9]{2}"))
	{
		this->phone = phone;
		return true;
	}
	else
	{
		showErrorMessage("Please input correct phone in format: 000(00)000-00-00 or +000(00)000-00-00, where 0 is number from 0 to 9");
		return false;
	}
	
}
bool Abonent::setPlane(string plane)
{
	if (checkValidPlane(plane, "^[A-Za-zà-ÿÀ-ß0-9 ]\*\$", 20))
	{
		this->current_plane = plane;
		return true;
	}
	else
	{
		showErrorMessage("Please input correct plane 20 character max");
		return false;
	}
}
bool Abonent::checkFieldsObject(Abonent abonent,string surname, string name, string midname, string phone, unsigned short int year, string plane)
{
	bool isState = false;
	bool fiedsObject[6]{abonent.setSurname(surname),abonent.setName(name),abonent.setMidName(midname),abonent.setPhone(phone),abonent.setYear(year),abonent.setPlane(plane)};
	for (int i = 0; i < 6; i++)
	{
		if (fiedsObject[i] == false)
			return false;
	}
	return true;
}
bool Abonent::isNullObject(Abonent abonent)
{
	if (abonent.getMidName() == "")
	{
		return true;
	}
	else if (abonent.getName() == "")
	{ 
		return true;
	}
	else if (abonent.getSurname() == "")
	{ 
		return true;
	}
	else if (abonent.getPhone() == "")
	{ 
		return true;
	}
	else if (abonent.getPlane() == "")
	{ 
		return true;
	}
	else if (abonent.getYear() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion