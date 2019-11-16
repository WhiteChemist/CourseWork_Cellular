	#pragma once
	#include <string>
	#include <vector>
	using namespace std;
	#ifndef Headers
	#define Headers
	void checkInput(string path);
	#pragma region Output
	void showErrorMessage(string message);
	void showInfoMessage(string message);
	void showOutputMessage(string message);
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
		string phone;//Телефон
		unsigned short int year;//Год
		string current_plane;//Текущий тарифный план

	public:
		Abonent();
		Abonent(string parsurname, string parname, string parmidname, string parphone, unsigned short int paryear, string parplane);
	#pragma region Getters/Setters
		const string getSurname();//Получить фамилию
		bool setSurname(string surname);//Установить фамилию
		const string getName();//Получить имя
		bool setName(string name);//Установить имя
		const string getMidName();//Получить отчество
		bool setMidName(string midname);//Установить отчество
		const unsigned short int getYear();//Получить год
		bool setYear(unsigned short int year);//Установить год
		const string getPhone();//Получить телефон
		bool setPhone(string phone);//Установить телефон
		const string getPlane();//Получить план
		bool setPlane(string plane);//Установить план
		static bool checkFieldsObject(Abonent abonent,string surname,string name,string midname,string phone,unsigned short int year,string plnae);
		static bool isNullObject(Abonent abonent);
#pragma endregion
	};

	#pragma region RegularExpressions
	bool checkValidSurname(string str, string templateRegex, int countCorrectSymbols);//проверка фамилии на корректность
	bool checkValidName(string str, string templateRegex, int countCorrectSymbols);//проверка имени на корректность
	bool checkValidMidName(string str, string templateRegex, int countCorrectSymbols);//проверка отчества на корректность
	bool checkValidYear(unsigned short int year,string templateRegex);//проверка года рождения на корректность
	bool checkValidPhoneNumber(string phone, string templateRegex);//проверка мобильного телефона на корректность
	bool checkValidPhoneNumber(string phone, string templateRegex, string templateRegexSecond);//проверка мобильного телефона на корректность с двух форматов
	bool checkValidPlane(string str, string templateRegex, int countCorrectSymbols);//проверка плана абонента на корректность
	#pragma endregion
	struct IEmployer
	{
	private:
		string login;
		string password;
		string status;
	public:
		virtual void getAbonents(vector<Abonent> *abonents,string path);//Функция для загрузки списка абонентов
		virtual Abonent createAbonent();//Создание абонента
		virtual void showAllAbonents(vector<Abonent> *abonents);//Вывод всех абонентов
		virtual void sortSurname(vector<Abonent> *abonents);//Сортировка по Фамилии
		virtual void sortYear(vector<Abonent> *abonents);//Сортировка по году
		virtual void searchSurname(vector<Abonent> *abonents,string surname);//Поиск по Фамилии
		virtual void searchYear(vector<Abonent> *abonents, unsigned short int year);//Поиск по году
		virtual void searchPhone(vector<Abonent> *abonents,string phone);//Поиск по телефону
		virtual int getCountAbonents(string path);//Получить количество абонентов
		virtual void showInterface();//Интерфейс взаимодействия для работников
		virtual	void outputAllAbonentsByYear(vector<Abonent>* abonents,unsigned short int year);//вывести всех абонентов с определенного года
		string getLogin();
		string getPassword();
		void setLogin(string login);
		void setPassword(string password);
		string getStatus();//Получение статуса работника
		void setStatus(string status);//Установление статуса работника
		IEmployer();
		IEmployer(string login, string password,string status);
		~IEmployer();//Деструктор для возможности освобождения памяти при создании нового функционала с использованием глобальных указателей
	};

	struct Employer : public IEmployer 
	{
	public:
		void writeInFileAbonent(string path, Abonent abonent);//Запись в файл абонента
		void Write(string path);//Запись в файл
		bool formatMatching(Abonent abonent);//проверка абонента на соответствие правилам
		vector<Abonent> *abonents;
		string pathAbonents;
		Employer();
		Employer(string login, string password, string status);
		Employer(string login, string password, string status,bool isAbonent);
		~Employer();	//Деструктор для возможности освобождения памяти при создании нового функционала с использованием глобальных указателей
		void showInterface();
	};

	struct Administrator :IEmployer {
	private:
		IEmployer employer;
		string pathAbonents;//путь для файла с абонентами
		string pathEmployers;//путь для файла с работниками
	public:
		vector<Abonent> *abonents;
		vector<Employer> *admemployers;
		void getAbonents(vector<Abonent> *abonents, string path);//Функция для загрузки списка абонентов
		static unsigned short int getCountEmployers(string path);//Получить количество работников
		static void getEmployers(vector<Employer> *admemployers, string path);//Функция для загрузки списка работников
		void writeInFileEmployer(string path, Employer employer);
		void showInterface();//Вывод интерфейса
		//Запись в файл работника
		void writeInFileAbonent(string path,Abonent abonent);//Запись в файл абонента
		Employer createNewEmployer();//Создание нового работника
		void showEmployers(vector<Employer> *admemployers);//Вывод работников (логин и пароль)
		void deleteEmployer(vector<Employer> *admemployers);//Удаление работника по логину
		void deleteEmployer(vector<Employer> *admemployers,string login);//Удаление работника по логину
		void rewriteAbonents(vector<Abonent> *abonents);//Перезапись файла с абонентами при удалении абонентами.
		bool checkOnValidLogin(string login,string path);//Проверка логина на валидность (не должны быть одинаковые логины)
		void rewriteEmployers(vector<Employer> *admemployers);//Перезапись файла с работниками при удалении работника
		void DeleteAbonent(vector<Abonent>* abonents);//Интерфейс удаления абонентов
		void deleteAbonentByPhone();//Удаление абонента по номеру телефона
		void deleteAbonentBySurname();//Удаление абонента по фамилии
		void deleteAbonentByPhone(string phone);//Удаление абонента по номеру телефона
		void deleteAbonentBySurname(string surname);//Удаление абонента по фамилии
		string getPathAbonents();//Получение пути файла с абонентами
		void setPathAbonents();//Установление пути файла с абонентами
		void setPathAbonents(string path);//Установление пути файла с абонентами
		string getPathEmployers();//Получение пути файла с работниками
		void setPathEmployers();//Установление пути файла с работниками
		void setPathEmployers(string path);//Установление пути файла с работниками
		Administrator(string login, string password,string status);
		~Administrator();//Деструктор для возможности освобождения памяти при создании нового функционала с использованием глобальных указателей
	};

	#endif
	int CorrectInput(int variable);//проверка на корректность ввода типа int
