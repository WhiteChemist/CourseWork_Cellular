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
			string surname;//�������
			string name;//���
			string midname;//��������
		};
		FIO currentFIO;
		string phone;//�������
		unsigned short int year;//���
		string current_plane;//������� �������� ����

	public:
		Abonent();
		Abonent(string parsurname, string parname, string parmidname, string parphone, unsigned short int paryear, string parplane);
	#pragma region Getters/Setters
		const string getSurname();//�������� �������
		bool setSurname(string surname);//���������� �������
		const string getName();//�������� ���
		bool setName(string name);//���������� ���
		const string getMidName();//�������� ��������
		bool setMidName(string midname);//���������� ��������
		const unsigned short int getYear();//�������� ���
		bool setYear(unsigned short int year);//���������� ���
		const string getPhone();//�������� �������
		bool setPhone(string phone);//���������� �������
		const string getPlane();//�������� ����
		bool setPlane(string plane);//���������� ����
		static bool checkFieldsObject(Abonent abonent,string surname,string name,string midname,string phone,unsigned short int year,string plnae);
		static bool isNullObject(Abonent abonent);
#pragma endregion
	};

	#pragma region RegularExpressions
	bool checkValidSurname(string str, string templateRegex, int countCorrectSymbols);//�������� ������� �� ������������
	bool checkValidName(string str, string templateRegex, int countCorrectSymbols);//�������� ����� �� ������������
	bool checkValidMidName(string str, string templateRegex, int countCorrectSymbols);//�������� �������� �� ������������
	bool checkValidYear(unsigned short int year,string templateRegex);//�������� ���� �������� �� ������������
	bool checkValidPhoneNumber(string phone, string templateRegex);//�������� ���������� �������� �� ������������
	bool checkValidPhoneNumber(string phone, string templateRegex, string templateRegexSecond);//�������� ���������� �������� �� ������������ � ���� ��������
	bool checkValidPlane(string str, string templateRegex, int countCorrectSymbols);//�������� ����� �������� �� ������������
	#pragma endregion
	struct IEmployer
	{
	private:
		string login;
		string password;
		string status;
	public:
		virtual void getAbonents(vector<Abonent> *abonents,string path);//������� ��� �������� ������ ���������
		virtual Abonent createAbonent();//�������� ��������
		virtual void showAllAbonents(vector<Abonent> *abonents);//����� ���� ���������
		virtual void sortSurname(vector<Abonent> *abonents);//���������� �� �������
		virtual void sortYear(vector<Abonent> *abonents);//���������� �� ����
		virtual void searchSurname(vector<Abonent> *abonents,string surname);//����� �� �������
		virtual void searchYear(vector<Abonent> *abonents, unsigned short int year);//����� �� ����
		virtual void searchPhone(vector<Abonent> *abonents,string phone);//����� �� ��������
		virtual int getCountAbonents(string path);//�������� ���������� ���������
		virtual void showInterface();//��������� �������������� ��� ����������
		virtual	void outputAllAbonentsByYear(vector<Abonent>* abonents,unsigned short int year);//������� ���� ��������� � ������������� ����
		string getLogin();
		string getPassword();
		void setLogin(string login);
		void setPassword(string password);
		string getStatus();//��������� ������� ���������
		void setStatus(string status);//������������ ������� ���������
		IEmployer();
		IEmployer(string login, string password,string status);
		~IEmployer();//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
	};

	struct Employer : public IEmployer 
	{
	public:
		void writeInFileAbonent(string path, Abonent abonent);//������ � ���� ��������
		void Write(string path);//������ � ����
		bool formatMatching(Abonent abonent);//�������� �������� �� ������������ ��������
		vector<Abonent> *abonents;
		string pathAbonents;
		Employer();
		Employer(string login, string password, string status);
		Employer(string login, string password, string status,bool isAbonent);
		~Employer();	//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
		void showInterface();
	};

	struct Administrator :IEmployer {
	private:
		IEmployer employer;
		string pathAbonents;//���� ��� ����� � ����������
		string pathEmployers;//���� ��� ����� � �����������
	public:
		vector<Abonent> *abonents;
		vector<Employer> *admemployers;
		void getAbonents(vector<Abonent> *abonents, string path);//������� ��� �������� ������ ���������
		static unsigned short int getCountEmployers(string path);//�������� ���������� ����������
		static void getEmployers(vector<Employer> *admemployers, string path);//������� ��� �������� ������ ����������
		void writeInFileEmployer(string path, Employer employer);
		void showInterface();//����� ����������
		//������ � ���� ���������
		void writeInFileAbonent(string path,Abonent abonent);//������ � ���� ��������
		Employer createNewEmployer();//�������� ������ ���������
		void showEmployers(vector<Employer> *admemployers);//����� ���������� (����� � ������)
		void deleteEmployer(vector<Employer> *admemployers);//�������� ��������� �� ������
		void deleteEmployer(vector<Employer> *admemployers,string login);//�������� ��������� �� ������
		void rewriteAbonents(vector<Abonent> *abonents);//���������� ����� � ���������� ��� �������� ����������.
		bool checkOnValidLogin(string login,string path);//�������� ������ �� ���������� (�� ������ ���� ���������� ������)
		void rewriteEmployers(vector<Employer> *admemployers);//���������� ����� � ����������� ��� �������� ���������
		void DeleteAbonent(vector<Abonent>* abonents);//��������� �������� ���������
		void deleteAbonentByPhone();//�������� �������� �� ������ ��������
		void deleteAbonentBySurname();//�������� �������� �� �������
		void deleteAbonentByPhone(string phone);//�������� �������� �� ������ ��������
		void deleteAbonentBySurname(string surname);//�������� �������� �� �������
		string getPathAbonents();//��������� ���� ����� � ����������
		void setPathAbonents();//������������ ���� ����� � ����������
		void setPathAbonents(string path);//������������ ���� ����� � ����������
		string getPathEmployers();//��������� ���� ����� � �����������
		void setPathEmployers();//������������ ���� ����� � �����������
		void setPathEmployers(string path);//������������ ���� ����� � �����������
		Administrator(string login, string password,string status);
		~Administrator();//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
	};

	#endif
	int CorrectInput(int variable);//�������� �� ������������ ����� ���� int
