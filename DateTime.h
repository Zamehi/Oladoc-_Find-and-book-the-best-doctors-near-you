#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;
#include "Admin.h"
#include "Appointment.h"
#include "BankTransfer.h"
//#include "DateTime.h"
#include "Doctors.h"
#include "E_transaction.h"
#include "Feedback.h"
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"
//---------------------------------------------------------------------------------------------------
// -------------------------------------------  DateTime  -------------------------------------------

class DateTime
{
protected:
	int hour;
	int day;
	// day[3];
	int month;
	
public:                                                      
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ Constructor
	DateTime(int hr=1,int day = 1, int m = 1)
	{
		while (day >= 1 && day <= 12)
		{
			this->hour = hr;
			break;
		}
		while (day > 1 && day < 31) 
		{
			this->day = day;
			break;
		}
		while (m > 1 && day < 12)
		{
			this->month = m;
			break;
		}
	}
	DateTime(const DateTime& copy) 
	{
		this->hour = copy.hour;
		this->day = copy.day;
		this->month = copy.month;
	}
	~DateTime() {}

	void set_hour(int hour) 
	{
		 this->hour = hour;
	}
	void set_day(int day)
	{
	     this->day= day;
	}
	void set_month(int month)
	{
		 this->month= month;
	}

};

