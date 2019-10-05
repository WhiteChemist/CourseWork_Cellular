#include <iostream>
#include "Headers.h"
using namespace std;

Abonent::Abonent()
{

}
Abonent::Abonent(string parsurname, string parname, string parmidname, string parphone, int paryear, string parplane)
{
	currentFIO.surname = parsurname;
	currentFIO.name = parname;
	currentFIO.midname = parmidname;
	phone = parphone;
	year = paryear;
	current_plane = parplane;
}
#pragma region Getters_and_Setters
string Abonent::GetSurname()
{
	return currentFIO.surname;
}
string Abonent::GetName()
{
	return currentFIO.name;
}
string Abonent::GetMidName()
{
	return currentFIO.midname;
}
int Abonent::GetYear()
{
	return this->year;
}
string Abonent::GetPhone()
{
	return this->phone;
}
string Abonent::GetPlane()
{
	return this->current_plane;
}
void Abonent::SetSurname(string surname)
{
	this->currentFIO.surname = surname;
}
void Abonent::SetName(string name)
{
	this->currentFIO.name = name;
}
void Abonent::SetMidName(string midName)
{
	this->currentFIO.midname = midName;
}
void Abonent::SetYear(int year)
{
	this->year = year;
}
void Abonent::SetPhone(string phone)
{
	this->phone = phone;
}
void Abonent::SetPlane(string plane)
{
	this->current_plane = plane;
}
#pragma endregion