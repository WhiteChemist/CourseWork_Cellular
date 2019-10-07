#pragma once
#include <string>
#include <vector>
using namespace std;
#ifndef Headers
#define Headers
void CheckInput(string path);
#pragma region Output
void ErrorMessage(string message);
void InfoMessage(string message);
void OutputMessage(string message);
#pragma endregion

struct Abonent {

private:
	struct FIO
	{
		string surname;//фамилия
		string name;//имя
		string midname;//отчество
	};
	FIO currentFIO;
	string phone = new char[15];//Телефон
	int year;//Год
	string current_plane;//Текущий тарифный план

public:
	Abonent();
	Abonent(string parsurname, string parname, string parmidname, string parphone, int paryear, string parplane);
#pragma region Getters/Setters
	const string GetSurname();//Получить фамилию
	void SetSurname(string surname);//Установить фамилию
	const string GetName();//Получить имя
	void SetName(string name);//Установить имя
	const string GetMidName();//Получить отчество
	void SetMidName(string midname);//Установить отчество
	const int GetYear();//Получить год
	void SetYear(int year);//Установить год
	const string GetPhone();//Получить телефон
	void SetPhone(string phone);//Установить телефон
	const string GetPlane();//Получить план
	void SetPlane(string plane);//Установить план
#pragma endregion
	friend const bool operator<(Abonent& a1, Abonent& a2)
	{
		return a1.GetYear() > a2.GetYear();
	}
};


struct IEmployer
{
private:
	string login;
	string password;
	string status;
public:
	virtual void GetAbonents(vector<Abonent> *abonents,string path);//Функция для загрузки списка абонентов
	virtual Abonent CreateAbonent();//Создание абонента
	virtual void ShowAllAbonents(vector<Abonent> *abonents);//Вывод всех абонентов
	virtual void SortSurname(vector<Abonent> *abonents);//Сортировка по Фамилии
	virtual void SortYear(vector<Abonent> *abonents);//Сортировка по году
	virtual void SearchSurname(vector<Abonent> *abonents,string surname);//Поиск по Фамилии
	virtual void SearchYear(vector<Abonent> *abonents,int year);//Поиск по году
	virtual void SearchPhone(vector<Abonent> *abonents,string phone);//Поиск по телефону
	virtual int GetCountAbonents(string path);//Получить количество абонентов
	virtual void InteractionInterface();//Интерфейс взаимодействия для работников
	string GetLogin();
	string GetPassword();
	void SetLogin(string login);
	void SetPassword(string password);
	string GetStatus();//Получение статуса работника
	void SetStatus(string status);//Установление статуса работника
	IEmployer();
	IEmployer(string login, string password,string status);
	~IEmployer();//Деструктор для возможности освобождения памяти при создании нового функционала с использованием глобальных указателей
};

struct Employer : public IEmployer 
{
public:
	void WriteInFileAbonent(string path, Abonent abonent);//Запись в файл абонента
	vector<Abonent> *abonents;
	string pathAbonents;
	Employer();
	Employer(string login, string password,string status);
	~Employer();
	void InteractionInterface();
	//Деструктор для возможности освобождения памяти при создании нового функционала с использованием глобальных указателей
};

struct Administrator :IEmployer {
private:
	IEmployer employer;
	string pathAbonents;//путь для файла с абонентами
	string pathEmployers;//путь для файла с работниками
public:
	vector<Abonent> *abonents;
	vector<Employer> *admemployers;
	void GetAbonents(vector<Abonent> *abonents, string path);//Функция для загрузки списка абонентов
	int GetCountEmployers(string path);//Получить количество работников
	void GetEmployers(vector<Employer> *admemployers, string path);//Функция для загрузки списка работников
	void WriteInFileEmployer(string path, Employer employer);
	void InteractionInterface();
	//Запись в файл работника
	void WriteInFileAbonent(string path,Abonent abonent);//Запись в файл абонента
	virtual Employer CreateNewEmployer();//Создание нового работника
	void ShowEmployers(vector<Employer> *admemployers);//Вывод работников (логин и пароль)
	void DeleteEmployer(vector<Employer> *admemployers);//Удаление работника по логину
	void DeleteEmployer(vector<Employer> *admemployers,string login);//Удаление работника по логину
	void RewriteAbonents(vector<Abonent> *abonents);//Перезапись файла с абонентами при удалении абонентами.
	bool CheckOnValidLogin(string login,string path);//Проверка логина на валидность (не должны быть одинаковые логины)
	void RewriteEmployers(vector<Employer> *admemployers);//Перезапись файла с работниками при удалении работника
	void DeleteAbonentByPhone();//Удаление абонента по номеру телефона
	void DeleteAbonentBySurname();//Удаление абонента по фамилии
	void DeleteAbonentByPhone(string phone);//Удаление абонента по номеру телефона
	void DeleteAbonentBySurname(string surname);//Удаление абонента по фамилии
	string GetPathAbonents();//Получение пути файла с абонентами
	void SetPathAbonents();//Установление пути файла с абонентами
	void SetPathAbonents(string path);//Установление пути файла с абонентами
	string GetPathEmployers();//Получение пути файла с работниками
	void SetPathEmployers();//Установление пути файла с работниками
	void SetPathEmployers(string path);//Установление пути файла с работниками
	Administrator(string login, string password,string status);
	~Administrator();//Деструктор для возможности освобождения памяти при создании нового функционала с использованием глобальных указателей
};

#endif
