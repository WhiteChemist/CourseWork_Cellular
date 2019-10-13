#include "Headers.h"
#include <regex>

using namespace std;
bool checkValidSurname(string str, string templateRegex, int countCorrectSymbols)
{
	regex first_option(templateRegex);
	smatch matches;
	if (str != "" && str.size() <= countCorrectSymbols && (regex_search(str, matches, first_option)))
	{
		return true;
	}
	return false;
}
bool checkValidName(string str, string templateRegex, int countCorrectSymbols)
{
	regex first_option(templateRegex);
	smatch matches;
	if (str != "" && str.size() <= countCorrectSymbols && (regex_search(str, matches, first_option)))
	{
		return true;
	}
	return false;
}
bool checkValidMidName(string str, string templateRegex, int countCorrectSymbols)
{
	regex first_option(templateRegex);
	smatch matches;
	if (str != "" && str.size() <= countCorrectSymbols && (regex_search(str, matches, first_option)))
	{
		return true;
	}
	return false;
}
bool checkValidPhoneNumber(string phone, string templateRegex)
{
	regex first_option(templateRegex);
	smatch matches;
	if (phone != "" && (regex_search(phone, matches, first_option)))
	{
		return true;
	}
	return false;
}
bool checkValidPhoneNumber(string phone, string templateRegex, string templateRegexSecond)
{
	regex first_option(templateRegex);
	regex second_option(templateRegexSecond);
	smatch matches;
	string* sPhone;
	if (phone != "" && (phone.size() == 16 || phone.size() == 17) && (regex_search(phone, matches, first_option) || regex_search(phone, matches, second_option)))//делаем проверку на пустоту, на количество символов и проверку на формат
	{
		return true;
	}
	return false;
}
bool checkValidYear(unsigned short int year, string templateRegex)
{
	regex reg(templateRegex);
	smatch sm;
	string sYear = to_string(year);
	if (year >= 0 &&year<=9999&& regex_search(sYear, sm, reg))
	{
		return true;
	}
	return false;
}
bool checkValidPlane(string str, string templateRegex, int countCorrectSymbols)
{
	regex first_option(templateRegex);
	smatch matches;
	if (str != "" && str.size() <= countCorrectSymbols && (regex_search(str, matches, first_option)))
	{
		return true;
	}
	return false;
}