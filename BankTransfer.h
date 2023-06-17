#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;
#include "Admin.h"
#include "Appointment.h"
//#include "BankTransfer.h"
#include "DateTime.h"
#include "Doctors.h"
#include "E_transaction.h"
#include "Feedback.h"
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"
//--------------------------------------------------------------------------------------------------
// -------------------------------------------- Bank Transfer  -------------------------------------

class bank_transfer :public virtual payment
{
protected:

public:


};

// --------------------------------------------  PayPak -------------------------------------------

class paypak :public virtual bank_transfer
{
protected:

public:


};
// --------------------------------------------  Union Pak  ----------------------------------------

class Union_pay :public virtual bank_transfer
{
protected:

public:

};