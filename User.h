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
#include "Patients.h"
#include "Payment.h"
//#include "User.h"
#include "Return.h"

// -----------------------------------------  OLADOC  ----------------------------------------
class Oladoc
{
protected:
	User U;
	string name;
public:


};

//--------------------------------------------------------------------------------------------
// ------------------------------------------  USER  -----------------------------------------
// User is composed in Oladoc hospital
class User
{
protected:
	string user_name;
	string password;
	string  email;
	int cnic[13];
public:
	User(string username = "", string password = "") :user_name(username), password(password) {}
	User(const User&copy) 
	{
		this->user_name = copy.user_name;
		this->password = copy.password;
	}
	void login(string user_name, string password)
	{

	}
	void create_account()
	{

	}
	void regist()
	{
		cout << "Enter cnic";
		for (int i = 0; i < 13; i++) 
		{
			cin >> cnic[i];
		}
		cout << "Enter cnic." << endl;
		cin >> this->email;
		cout << "Enter a valid username." << endl;
		cin >> this->user_name;
		cout << "Enter password of 8 charachters with minimum one special upper case, lower case and a digit." << endl;
		cin >> this->password;
		// Verification for password 
		while ((this->password.size() < 8))
		{
			cout << "Enter 8 charachters for your password." << endl;
			cin >> this->password;
		}
		//calling the password function
		this->password = password_check(this->password);
	}

	string get_user_name() 
	{
		return this->user_name;
	}
	string get_password() 
	{
		return this->password;
	}
	int* get_cnic()
	{
		return cnic;
	}
	~User() {}
};