#include <iostream>
#pragma warning(disable:4996)
#include <cstring>
#include <fstream>
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
#include "User.h"
#include "Return.h"
void function() 
{

}
int main()
{
	const char* doc = "Doctors.bin";
	const char* pat = "Patients.bin";
	const char* app = "Appointment.bin";
	int patient_index = 0, doctor_index = 0;
	int x;
	long int key;
	appointment* a = new appointment();

	cout << "Login or create account." << endl;
	cout << "Enter 1 to login and 2 to create account." << endl;
	cin >> x;
	if (x == 1)
	{  // LOGIN
		string user_name;
		string password;
		cout << "Enter username for your account." << endl;
		cin >> user_name;// check if no one else has a username like that.
		cout << "Enter the password of your account." << endl;
		cin >> password;

		if ((user_name == "admin") && password == "hellodoc")
		{
			int x;
			admin_menu();
			cout << "Welcome Admin." << endl;
			cout << "Press 1 for Doctor's Data and 2 for Patients's data.";
			cin >> x;


		}
		else // for doctor and user login
		{

			static int check = 0;
			retrieve_d_Object(doc, user_name, password, check);
			retrieve_p_Object(pat, user_name, password, check);

			// check which is the account of doctor or patient.
			if (check == 1)
			{
				//Doctors

			}
			else if (check == 2)
			{
				// Patients
			}

		}


	}
	else if (x == 2)
	{// create ACCOUNT
		int x;
		cout << "Join as a doctor or a patient." << endl << "Press 1 for patient and 2 for doctor." << endl;
		cin >> x;
		if (x == 1)
		{
			// Create account for patient.(register)
			Patients* patient = new Patients();
			patient->regist();
			patient->enter_details();
			insertObject(pat, patient);
			patients_menu();
		}
		else if (x == 2)
		{
			//Create account for doctor.(register)
			Doctors* doctor = new Doctors();
			doctor->regist();
			doctor->enter_details();
			insertObject(doc, doctor);
			doctors_menu();
		}
	}
}

	/*
	cout << "Join as a patient or a doctor." << endl << "Enter 1 for patient and 2 for doctor." << endl;
	cin >> key;
	if (key == 031313131313)
	{
		cout << "Welcome Admin." << endl;

	}
	else if (key == 1) 
	{
		// PATIENT
		int v = 0;
		cout << "Do you want to register or login?" << endl << "Enter 1 to register and 2 to login." << endl;
		cin >> v;
		if (v == 1) 
		{
			string user_name;
			string password;
			string f_name, m_name, l_name;
			char gender;
			string contact;
			cout << "Enter user name." << endl;
			cin >> user_name;
			cout << "Enter Password." << endl;
			cin >> password;
			while (password.size() < 8) 
			{
				cout << "Please enter a password with 8 characters." << endl;
				cin >> password;
			}
			cout << "Enter your first name." << endl;
			cin >> f_name;
			cout << "Enter your middle name." << endl;
			cin >> m_name;
			cout << "Enter your last name" << endl;
			cin >> l_name;
			cout << "Enter gender f , m , c." << endl;
			cin >> gender;
			while (gender != 'f' && gender != 'm' && gender != 'c') 
			{
				cout << "Please enter a valid character." << endl;
			}
		}

	}
	else if (key == 2) 
	{
		// DOCTOR
		cout << "Do you want to register or login?" << endl;
	}


}
*/