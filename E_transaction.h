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
//#include "E_transaction.h"
#include "Feedback.h"
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"
//-------------------------------------------------------------------------------------------------
// -------------------------------------------- E- Transaction  -----------------------------------

class e_transaction :public virtual payment
{
protected:

public:
	e_transaction() 
	{

	}
	e_transaction(const e_transaction& copy) 
	{

	}
	~e_transaction() 
	{

	}

};

//--------------------------------------------- Jazz cash  ----------------------------------------

class jazzcash :public virtual e_transaction
{
protected:

public:


};

//---------------------------------------------  Easy Paisa  --------------------------------------

class easypaisa :public virtual e_transaction
{
protected:

public:
};