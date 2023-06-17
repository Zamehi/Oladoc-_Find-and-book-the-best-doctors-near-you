#pragma once
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
//#include "Return.h"
//------------------------------------------------------------------------------------------------
// -------------------------------------------  PAYMENT  -----------------------------------------

class Return
{
protected:
	int refund;

public:

	Return(int pay = 0)
	{
		this->refund = pay;
		//this->fine = fine;
	}
	Return(const Return& copy)
	{
		this->refund = copy.refund;
		//this->fine = copy.fine;
	}
	~Return() {}
};


