#pragma once
#include <string>
#include <vector>
using namespace std;
#ifndef Headers
#define Headers
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
	string GetSurname();//�������� �������
	void SetSurname(string surname);//���������� �������
	string GetName();//�������� ���
	void SetName(string name);//���������� ���
	string GetMidName();//�������� ��������
	void SetMidName(string midname);//���������� ��������
	int GetYear();//�������� ���
	void SetYear(int year);//���������� ���
	string GetPhone();//�������� �������
	void SetPhone(string phone);//���������� �������
	string GetPlane();//�������� ����
	void SetPlane(string plane);//���������� ����
#pragma endregion

};
struct IEmployer
{
private:
	string login;
	string password;
public:
	virtual void GetAbonents(vector<Abonent> abonents,string path);//������� ��� �������� ������ ���������
	virtual Abonent CreateAbonent();//�������� ��������
	virtual void ShowAllAbonents(vector<Abonent> abonents);//����� ���� ���������
	virtual void SortSurname(vector<Abonent> abonents);//���������� �� �������
	virtual void SortYear(vector<Abonent> abonents);//���������� �� ����
	virtual void SearchSurname(vector<Abonent> abonents,string surname);//����� �� �������
	virtual void SearchYear(vector<Abonent> abonents,int year);//����� �� ����
	virtual void SearchPhone(vector<Abonent> abonents,string phone);//����� �� ��������
	virtual int GetCountAbonents(string path);//�������� ���������� ���������
	virtual void InteractionInterface();//��������� �������������� ��� ����������
	string GetLogin();
	string GetPassword();
	void SetLogin(string login);
	void SetPassword(string password);
	IEmployer();
	IEmployer(string login, string password);
	~IEmployer();//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
};

struct Employer : public IEmployer 
{
public:
	vector<Abonent> abonents;
	Employer();
	Employer(string login, string password);
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
	vector<Abonent> abonents;
	vector<Employer> employers;
	int GetCountEmployers(string path);//�������� ���������� ����������
	void GetEmployers(vector<Employer> employers, string path);//������� ��� �������� ������ ����������
	void WriteInFileEmployer(string path, Employer employer);
	void InteractionInterface();
	//������ � ���� ���������
	void WriteInFileAbonent(string path,Abonent abonent);//������ � ���� ��������
	virtual Employer CreateNewEmployer();//�������� ������ ���������
	void ShowEmployers(vector<Employer> employers);//����� ���������� (����� � ������)
	void DeleteEmployer(vector<Employer> employers);//�������� ��������� �� ������
	void DeleteEmployer(vector<Employer> employers,string login);//�������� ��������� �� ������
	void RewriteAbonents(vector<Abonent> abonents);//���������� ����� � ���������� ��� �������� ����������.
	bool CheckOnValidLogin(string login,string path);//�������� ������ �� ���������� (�� ������ ���� ���������� ������)
	void RewriteEmployers(vector<Employer> employers);//���������� ����� � ����������� ��� �������� ���������
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
	Administrator(string login, string password);
	~Administrator();//���������� ��� ����������� ������������ ������ ��� �������� ������ ����������� � �������������� ���������� ����������
};

#endif