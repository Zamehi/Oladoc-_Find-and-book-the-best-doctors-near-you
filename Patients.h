#pragma once
#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
#include "Admin.h"
#include "Appointment.h"
#include "BankTransfer.h"
#include "DateTime.h"
#include "Doctors.h"
#include "E_transaction.h"
#include "Feedback.h"
#include "Functions.h"
//#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"
//---------------------------------------------------------------------------------------------
//--------------------------------------------  PATIENTS  -------------------------------------
class Patients : public User
{
protected:
	//a_Patients p[250];
	appointment* a;
//	string user_name;
	//string password;
	char f_name[20], m_name[20], l_name[20];
	//string cnic, email;
	char gender;
	char contact[12];
	int balance;

public:
	Patients(string a ="", string b="", string c ="", char d ='\0', string e ="", int balance =0, appointment *app= NULL)
	{
		strcpy(f_name, a.c_str());
		strcpy(m_name, b.c_str());
		strcpy(l_name, c.c_str());
		gender = d;
		strcpy(contact, e.c_str());
		this->balance = balance;
		this->a = app;
	}
	Patients(const Patients& copy) 
	{
		strcpy(f_name, copy.f_name);
		strcpy(m_name, copy.m_name);
		strcpy(l_name, copy.l_name);
		gender = copy.gender;
		strcpy(contact, copy.contact);
		this->balance = copy.balance;
		this->a = copy.a;
	}
	~Patients() {}


	void enter_details() 
	{
		//int slots;
		cout << "Enter first name." << endl;
		cin >> this->f_name;
		cout << "Enter the midddle name." << endl;
		cin >> m_name;
		cout << "Enter your last name." << endl;
		cin >> l_name;
		cout << "Enter m for male f for female." << endl;
		cin >> gender;
		while (gender != 'm' && gender != 'f')
		{
			cout << "Enter a valid character for gender." << endl;
			cin >> this->gender;
		}
	}
	void set_gender()
	{
		cout << "Enter m for male f for female." << endl;
		cin >> gender;
		while (gender != 'm' && gender != 'f')
		{
			cout << "Enter a valid character for gender." << endl;
			cin >> this->gender;
		}
	}
	void set_name()
	{
		cout << "Enter first name." << endl;
		cin >> this->f_name;
		cout << "Enter the midddle name." << endl;
		cin >> m_name;
		cout << "Enter your last name." << endl;
		cin >> l_name;
	}
	void set_balance(int x)
	{
		this->balance = 3500 +x;
	}
	void set_contact() 
	{
		cout << "Enter Contact." << endl;
		cin >> contact;
	}
	void set_appointment(appointment *app) 
	{
		this->a = app;
	}


	void display1()
	{
		// for selecting option.
		cout << "Welcome " << f_name << endl;
		patients_menu();

	}
	void display()
	{
		cout << "Name:     " << f_name << " " << m_name << " " << l_name << endl;
		cout << "Gender:   " << gender << endl;
		cout << "Contact:  " << contact << endl;
		cout << "Balance:  " << balance << endl;
	}

	string get_f_name() 
	{
		return f_name;
	}
	string get_m_name()
	{
		return m_name;
	}
	string get_l_name()
	{
		return l_name;
	}
	char get_gender() 
	{
		return gender;
	}
	appointment* get_appointment() 
	{
		return a;
	}


};

