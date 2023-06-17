#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;
#include "Admin.h"
#include "Appointment.h"
#include "BankTransfer.h"
#include "DateTime.h"
//#include "Doctors.h"
#include "E_transaction.h"
#include "Feedback.h"
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include <fstream>
#include "Return.h"
//-----------------------------------------------------------------------------------------------
// -------------------------------------------  DOCTORS  ----------------------------------------

class Doctors :public User
{
protected:

	appointment* a;
	char f_name[20], m_name[20], l_name[20];
	//string cnic, email;
	char gender;
	char contact[20];
	int** availability_hours;
	//char availability_hours[4][6];
	int hourly_charge;
	int experience;
	char specialization[20];
	char hospital[20];
	char city[20];
	int slots;
	int rating;
public:
	//----------------------------------------- Constructors -------------------------------------|||||||
	Doctors(string a = "", string b = "", string c = "", char d = '\0', string e = "", int **f=NULL, int g = 0, int h = 0, string i = "", string j = "", string k = "", string user_name = "", string password = "", int slots, char* cnic = {'\0'}, string email = "", appointment *app= NULL, int rating =0) :User(user_name, password),a (app)
	{
		strcpy(f_name, a.c_str());
		m_name = b, l_name = c;
		 for (int i = 0; i < 13; i++) 
		 {
			 this->cnic[i] = cnic[i];

		 }
			 this-> email = email;
		 gender = d;
		 contact =  e; 
		// availability_hours[4][6] = f[4][6];
		 availability_hours = new  int* [slots];
		 for (int i = 0; i < slots; i++)
		 {
			 availability_hours[i] = new int[3];
		 }
		 availability_hours = f;
		 hourly_charge = g;
		 experience = h;
		 specialization = i;
		 hospital =j;
		 city = k;
		 this->slots = slots;
		 this->rating = rating;
	}

	
	Doctors(const Doctors& copy) 
	{
		f_name = copy.f_name, m_name = copy.m_name, l_name = copy.l_name;
		 this->email = copy.email;
		 for (int i = 0; i < 13; i++) 
		 {
			 this->cnic[i] = copy.cnic[i];
		 }
		gender = copy.gender;

		contact = copy.contact;
		availability_hours[4][6] = copy.availability_hours[4][6];
		hourly_charge = copy.hourly_charge;
		experience = copy.experience;
		specialization = copy.specialization;
		hospital = copy.hospital;
		city = copy.city;
		this->user_name = copy.user_name;
		this->password = copy.password;
	}
	~Doctors() {}





	// ---------------------------------------- Functions ----------------------------------------|||||||
	
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
		cout << "Enter your years of experience." << endl;
		cin >> this->experience;
		cout << "Enter specialization area." << endl;
		cin >> this->specialization;
		cout << "Enter the hospital you are working in." << endl;
		cin >> this->hospital;
		cout << "Enter availability hours." << endl;
		int slots = 0;

		cout << "How many slots of yours are free out of 4." << endl;
		cin >> slots;
		availability_hours = new  int* [slots];
		for (int i = 0; i < slots; i++)
		{
			availability_hours[i] = new int[3];
		}
		for (int i = 0; i < slots; i++)
		{
			cout << "You are available on time.";
			for (int i = 0; i < slots; i++)
			{
				cout << "for " << i + 1 << " slot" << endl;
				cin >> this->availability_hours[i][0];
			}
			cout << "You are available on day.";
			for (int i = 0; i < slots; i++)
			{
				cout << "for " << i + 1 << " slot" << endl;
				cin >> this->availability_hours[i][1];
			}
			cout << "You are available on month.";
			for (int i = 0; i < slots; i++)
			{
				cout << "for " << i + 1 << " slot" << endl;
				cin >> this->availability_hours[i][2];
			}


		}
	
		cout << "Enter city for appointment." << endl;
		cin >> this->city;
		cout << "Enter hourly Charge." << endl;
		cin >> hourly_charge;
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
	void set_hospital() 
	{
		cout << "Enter Hospital." << endl;
		cin >> hospital;
	}
	void set_specialization() 
	{
		cout << "Enter specialization area." << endl;
		cin >> this->specialization;
	}
	void set_years_of_experience() 
	{
		cout << "Enter your years of experience." << endl;
		cin >> this->experience;
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
	void set_gender(char gender) 
	{
		this->gender = gender;
	}
	void set_city() 
	{
		cout << "Enter city for appointment." << endl;
		cin >> this->city;
	}
	void set_availability_hours() 
	{
		
		int slots = 0;

		cout << "How many slots of yours are free out of 4." << endl;
		cin >> slots;
		availability_hours = new  int*[slots];
		for (int i = 0; i < slots; i++) 
		{
			availability_hours[i] = new int[3];
		}
		for (int i = 0; i < slots; i++)
		{
			cout << "You are available on time.";
			for (int i = 0; i < slots; i++) 
			{
				cout << "for " << i + 1 << " slot" << endl;
				cin >> this->availability_hours[i][0];
			}
			cout << "You are available on day.";
			for (int i = 0; i < slots; i++)
			{
				cout << "for " << i + 1 << " slot" << endl;
				cin >> this->availability_hours[i][1];
			}
			cout << "You are available on month.";
			for (int i = 0; i < slots; i++)
			{
				cout << "for " << i + 1 << " slot" << endl;
				cin >> this->availability_hours[i][2];
			}


		}
	}
	void set_availability_hours(int ** h)
	{
		availability_hours = new  int* [slots];
		for (int i = 0; i < slots; i++)
		{
			availability_hours[i] = new int[3];
		}
		for (int i = 0; i < this->slots; i++) 
		{
			for (int j = 0; j < 3; j++) 
			{
				availability_hours[i][j] = h[i][j];
			}
		}
		
	}
	void set_hourly_charge() 
	{
		cout << "Enter hourly charge." << endl;
		cin >> hourly_charge;
	}
	void set_hourly_charge(int h) 
	{
		this->hourly_charge = h;
	}
	void set_contact() 
	{
		cout << "Enter your contact." << endl;
		for (int i = 0; i < 12; i++) 
		{
			cin >> contact[i];
		}
	}
	void set_appointment(appointment* a) 
	{

	}

	// ------------------------------------------  Getters  -----------------------------------------|||||||
	int ** get_hours() 
	{
		/*cout << "Availability Hours: " << endl;
		for (int i = 0; i < slots; i++)
		{
			for (int j = 0; j < 6; i++)
			{
				cout << availability_hours[i][j];
				if (j == 1 || j == 3)
				{
					cout << ":";
				}
				cout << endl;
			}
		}*/
	
		return availability_hours;
	}
	int get_slots() 
	{
		return this->slots;
	}
	int get_hourly_charge() 
	{
		return hourly_charge;
	}
	char* get_specialization() 
	{
		return this->specialization;
	}
	char* get_name() 
	{
		return this->f_name;
	}
	char* get_city() 
	{
		return this->city;
	}
	char get_gender() 
	{
		return this->gender;
	}
	char* get_contact() 
	{
		return this->contact;
	}
	char* get_hospital() 
	{
		return this->hospital;
	}
	//int **get_ava


	// ---------------------------------------- FIle Handling -------------------------------------|||||||
	
	void display1() 
	{
		// for selecting option.
		cout << "Welcome " << f_name << endl;
		doctors_menu();

	}
	void display() 
	{
		cout << "Name:               " << f_name << " " << m_name << " " << l_name << endl;
		cout << "Gender:             " << gender << endl;
		cout << "Contact:            " << contact << endl;
		cout << "Availability Hours: " << endl;
		for (int i = 0; i < slots; i++) 
		{
			for (int j = 0; j < 6; i++) 
			{
				cout << availability_hours[i][j];
				if (j == 1 || j == 3) 
				{
					cout << ":";
				}
				cout << endl;
			}
		}
		cout << "Hourly Charge:      " << hourly_charge << endl;
		cout << "Specification:      " << specialization << endl;
		cout << "Hospital:           " << hospital << endl;
		cout << "City:               " << city << endl;

	}
	


};

//------------------------------------------------------------------------------------------------
// -----------------------------------------  SPECIFICATION  -------------------------------------

class gynecologist:public Doctors
{
protected:

public:

};
// ------------------
class dermatologist :public Doctors
{
protected:

public:


};
// ------------------
class oncologist :public Doctors
{
protected:


public:


};
// ------------------
class orthopedic :public Doctors
{
protected:

public:

};


