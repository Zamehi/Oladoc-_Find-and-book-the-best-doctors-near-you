#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;
#include "Admin.h"
//#include "Appointment.h"
#include "BankTransfer.h"
#include "DateTime.h"
#include "Doctors.h"
#include "E_transaction.h"
#include "Feedback.h"
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"
//------------------------------------------------------------------------------------------------
// ------------------------------------------  APPOINTMENT  --------------------------------------

class appointment
{
protected:
	//Composition
	char d_cnic[13];
	char p_cnic[13];

	// char array for name
	char d_f_name[20];
	char p_f_name[20];
	DateTime d;
	payment p;
	char status;

public:
	appointment(string d_cnic="", string p_cnic="", char status='\0', string d_f_name="", string p_f_name="", int hr=0, int day=0, int mth=0, int pay=0, int fine=0) :d(hr, day, mth), p(pay, fine)
	{
		strcpy(this->d_cnic, d_cnic.c_str());
		strcpy(this->p_cnic, p_cnic.c_str());
		this->status = status;
		strcpy(this->d_f_name, d_f_name.c_str());
		strcpy(this->p_f_name, p_f_name.c_str());
	}
	appointment(const appointment& copy) 
	{
		strcpy(this->d_cnic, copy.d_cnic);
		strcpy(this->p_cnic,copy.p_cnic);
		this->status = status;
		strcpy(this->d_f_name, copy.d_f_name);
		strcpy(this->p_f_name, copy.p_f_name);
		this->d = copy.d;
		this->p = copy.p;
	}
	~appointment() {}

	//---------------------------------------------------------------------------------------------

	void set_d_cnic(int *cnic) 
	{
		cout << "Enter doctor's cnic." << endl;
		string str;
		for (int i = 0; i < 13; i++) 
		{
			d_cnic[i]= cnic[i];
		}
	}
	void set_p_cnic(string cnic)
	{
		cout << "Enter patients's cnic." << endl;
		for (int i = 0; i < 13; i++)
		{
			p_cnic[i]=cnic[i];
		}
	}
	void set_d_name(string str) 
	{
		string str;
		//cin >> str;
		strcpy(d_f_name, str.c_str());	
	}
	void set_p_name(string str)
	{
		//string str;
		//cin >> str;
		strcpy(p_f_name, str.c_str());
	}
	void cancel_appointment()
	{
		this->status = 'c';
	}
	void set_date_time(int hour, int day, int month) 
	{
		d.set_hour(hour);
		d.set_day(day);
		d.set_month(month);
	}
	void set_payment() 
	{

	}
};

// -----------------------------------------  in Person --------------------------------------------
class in_person :public virtual appointment
{
protected:
	int inperson_charge;
public:
	in_person(int charge = 0, string d_cnic = "", string p_cnic = "", char status = '\0', string d_f_name = "", string p_f_name = "", int hr = 0, int day = 0, int mth = 0, int pay = 0, int fine = 0) :appointment (d_cnic, p_cnic, status,d_f_name, p_f_name,hr, day, mth, pay, fine)
	{
		this->inperson_charge = charge;
	}
	in_person(const in_person& copy)
	{
		this->inperson_charge = copy.inperson_charge;
	}
	~in_person() {}
	// Constructor for only setting appointment
	in_person(string d_cnic, string p_cnic , char status, string d_f_name, string p_f_name, int hr , int day, int mth, int pay, int fine ) :appointment(d_cnic, p_cnic, status, d_f_name, p_f_name, hr, day, mth, pay, fine)
	{
		
	}
};

//--------------------------------------------  video_consultation  --------------------------------

class video_consultation :public virtual appointment
{
protected:
	int video_charge;

public:

	video_consultation(int charge = 0, string d_cnic = "", string p_cnic = "", char status = '\0', string d_f_name = "", string p_f_name = "", int hr = 0, int day = 0, int mth = 0, int pay = 0, int fine = 0) :appointment(d_cnic, p_cnic, status, d_f_name, p_f_name, hr, day, mth, pay, fine)
	{
		this->video_charge = charge *(0.7);
	}
	video_consultation(const video_consultation& copy) 
	{
		this->video_charge = copy.video_charge;
	}
	~video_consultation() 
	{

	}

};
