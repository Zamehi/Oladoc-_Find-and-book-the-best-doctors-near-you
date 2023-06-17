#pragma once
#pragma warning(disable:4996)
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
//#include "Payment.h"
#include "User.h"
#include "Return.h"
//------------------------------------------------------------------------------------------------
// -------------------------------------------  PAYMENT  -----------------------------------------

class payment
{
protected:
	int pay;
	int fine;

public:

	payment(int pay=0, int fine=0) 
	{
		this->pay = pay;
		this->fine = fine;
	}
	payment(const payment &copy) 
	{
		this->pay = copy.pay;
		this->fine = copy.fine;
	}
	~payment() {}
};


