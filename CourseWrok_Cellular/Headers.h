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
		string surname;//�������
		string name;//���
		string midname;//��������
	};
	FIO currentFIO;
	string phone = new char[15];//�������
	int year;//���
	string current_plane;//������� �������� ����

public:
	Abonent();
	Abonent(string parsurname, string parname, string parmidname, string parphone, int paryear, string parplane);
#pragma region Getters/Setters
	const string GetSurname();//�������� �������
	void SetSurname(string surname);//���������� �������
	const string GetName();//�������� ���
	void SetName(string name);//���������� ���
	const string GetMidName();//�������� ��������
	void SetMidName(string midname);//���������� ��������
	const int GetYear();//�������� ���
	void SetYear(int year);//���������� ���
	const string GetPhone();//�������� �������
	void SetPhone(string phone);//���������� �������
	const string GetPlane();//�������� ����
	void SetPlane(string plane);//���������� ����
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
	virtual void GetAbonents(vector<Abonent> *abonents,string path);//������� ��� �������� ������ ���������
	virtual Abonent CreateAbonent();//�������� ��������
	virtual void ShowAllAbonents(vector<Abonent> *abonents);//����� ���� ���������
	virtual void SortSurname(vector<Abonent> *abonents);//���������� �� �������
	virtual void SortYear(vector<Abonent> *abonents);//���������� �� ����
	virtual void SearchSurname(vector<Abonent> *abonents,string surname);//����� �� �������
	virtual void SearchYear(vector<Abonent> *abonents,int year);//����� �� ����
	virtual void SearchPhone(vector<Abonent> *abonents,string phone);//����� �� ��������
	virtual int GetCountAbonents(string path);//�������� ���������� ���������
	virtual void InteractionInterface();//��������� �������������� ��� ����������
	string GetLogin();
	string GetPassword();
	void SetLogin(string login);
	void SetPassword(string password);
	string GetStatus();//��������� ������� ���������
	void SetStatus(string status);//������������ ������� ���������
	IEmployer();
	IEmployer(string login, string password,string status);
	~IEmployer();//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
};

struct Employer : public IEmployer 
{
public:
	void WriteInFileAbonent(string path, Abonent abonent);//������ � ���� ��������
	vector<Abonent> *abonents;
	string pathAbonents;
	Employer();
	Employer(string login, string password,string status);
	~Employer();
	void InteractionInterface();
	//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
};

struct Administrator :IEmployer {
private:
	IEmployer employer;
	string pathAbonents;//���� ��� ����� � ����������
	string pathEmployers;//���� ��� ����� � �����������
public:
	vector<Abonent> *abonents;
	vector<Employer> *admemployers;
	void GetAbonents(vector<Abonent> *abonents, string path);//������� ��� �������� ������ ���������
	int GetCountEmployers(string path);//�������� ���������� ����������
	void GetEmployers(vector<Employer> *admemployers, string path);//������� ��� �������� ������ ����������
	void WriteInFileEmployer(string path, Employer employer);
	void InteractionInterface();
	//������ � ���� ���������
	void WriteInFileAbonent(string path,Abonent abonent);//������ � ���� ��������
	virtual Employer CreateNewEmployer();//�������� ������ ���������
	void ShowEmployers(vector<Employer> *admemployers);//����� ���������� (����� � ������)
	void DeleteEmployer(vector<Employer> *admemployers);//�������� ��������� �� ������
	void DeleteEmployer(vector<Employer> *admemployers,string login);//�������� ��������� �� ������
	void RewriteAbonents(vector<Abonent> *abonents);//���������� ����� � ���������� ��� �������� ����������.
	bool CheckOnValidLogin(string login,string path);//�������� ������ �� ���������� (�� ������ ���� ���������� ������)
	void RewriteEmployers(vector<Employer> *admemployers);//���������� ����� � ����������� ��� �������� ���������
	void DeleteAbonentByPhone();//�������� �������� �� ������ ��������
	void DeleteAbonentBySurname();//�������� �������� �� �������
	void DeleteAbonentByPhone(string phone);//�������� �������� �� ������ ��������
	void DeleteAbonentBySurname(string surname);//�������� �������� �� �������
	string GetPathAbonents();//��������� ���� ����� � ����������
	void SetPathAbonents();//������������ ���� ����� � ����������
	void SetPathAbonents(string path);//������������ ���� ����� � ����������
	string GetPathEmployers();//��������� ���� ����� � �����������
	void SetPathEmployers();//������������ ���� ����� � �����������
	void SetPathEmployers(string path);//������������ ���� ����� � �����������
	Administrator(string login, string password,string status);
	~Administrator();//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
};

#endif
