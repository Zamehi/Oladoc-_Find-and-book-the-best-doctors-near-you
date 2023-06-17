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
//#include "Feedback.h"
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"
//------------------------------------------------------------------------------------------------
// ----------------------------------------------  FEEDBACK  -------------------------------------

class feedback
{
protected:
	//Aggregation
	Patients* p;
	Doctors* d;
	DateTime* t;
	char remarks[200];

public:
	feedback(Patients *p=NULL, Doctors *d=NULL, DateTime *t=NULL, char *remarks=NULL):p (p), d(d), t(t)
	{
		strcpy(this->remarks, remarks);
	}
	feedback(const feedback& copy) 
	{
		p = copy.p;
		d = copy.d;
		t = copy.t;
		strcpy(this->remarks, copy.remarks);
	}
	~feedback() {}

};
