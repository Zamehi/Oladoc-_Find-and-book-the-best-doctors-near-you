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
//#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Return.h"

// Function for verification of password
string password_check(string password) 
{
	int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if ((password[i] >= 32 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126))
		{
			// Special characters
			check1 = 0; break;
		}
		else
		{
			check1 = 1;
			
		}
	}
	for (int i = 0; i < password.size(); i++)
	{
		// 0-9
		if ((password[i] >= 48 && password[i] <= 57))
		{
			check2 = 0; break;
		}
		else
		{
			check2 = 1;
			
		}
	}
	for (int i = 0; i < password.size(); i++)
	{
		// A_Z
		if ((password[i] >= 65 && password[i] <= 90))
		{
			check3 = 0; break;
		}
		else
		{
			check3 = 1;
			
		}
	}
	for (int i = 0; i < password.size(); i++)
	{
		// a-z
		if ((password[i] >= 97 &&password[i] <= 122))
		{
			check4 = 0; break;
		}
		else
		{
			check4 = 1;
		}
	}
	while (check1 == 1 || check2 == 1 || check3 == 1 || check4 == 1)
	{
		cout << "Your password must contain uppercase, lowercase, numeric digits and specific characters. Please re-enter the password." << endl;
		cin >> password;
	}
	return password;
}

char** appoitment_timings(char**app,int slots) 
{
	//char app[4][6];
	for (int i = 0; i < slots; i++)
	{
		cout << "You are available from.";
		cin >> app[i][0] >> app[i][1];
		cout << "till ";
		cin >> app[i][2] >> app[i][3];
		cout << "Enter 1 for AM and 2 for PM.";
		int x;
		cin >> x;
		if (x == 1) 
		{
			app[i][4] = 'A';
			app[i][5] = 'M';
		}
		else
		{
			app[i][4] = 'P';
			app[i][5] = 'M';
		}
	
	}
	return app;
}

void patients_menu() 
{
	cout << "1. Reset Password." << endl << "2. Search doctors."  << endl <<"3. Manage appointments." << endl;
	cout << "4. Edit Profile." << endl << "5. View appointments." << endl <<"6. Recharge account." << endl;
}

void whats_up()
{
	cout << "***************************************************************************" << endl;
	cout << "|  /\\  |  |     __   |    ,  __               __       __|  __   __    __ " << endl;
	cout << "| /  \\ |  |___ |  |  |-     |__        |  |  |  |     |  | |  | |     | _|" << endl;
	cout << "|/    \\|  |  | |__|_ |__|    __|       |__|_ |__|     |__| |__| |__     | " << endl;
	cout << "                                              |                          o" << endl;
	cout << "***************************************************************************" << endl;
}

void get_well() 
{
	cout << " ___                                       ___                         " << endl;
	cout << "|      __  |       |  /\\  |  __  |  |    |     __   __  _ __       | " << endl;
	cout << "|  _  |__| |-      | /  \\ | |__| |  |     \\_  |  | |  |  |  |      | " << endl;
	cout << "|___| |___ |__|    |/    \\| |___ |  |    ___| |__| |__|  |  |      | " << endl;
	cout << "   _|                                                               o " << endl;
	cout << "                                  *********                           " << endl;
}

void doctors_menu() 
{
	cout << "1. View Profile." << endl << "2. Edit availability." << endl << "3. Edit Hourly Charge." << endl;
	cout << "4. View appointment data." << endl << "5. View specialization." << endl << "6. Edit appointment data." << endl;
	cout << "7. Edit Profile." << endl;
	
}

void admin_menu()
{
	cout << "1. Edit Doctors data." << endl << "2. View doctor's data." << endl << "3. View Patient's data." << endl;
	cout << "4. Schedule doctor's availability." << endl << "5. View Doctor's appoiuntment data." << endl;
	cout << "6. Update or cancel appointments." << endl << "7. Give Feedback." << endl;
}



// -----------------------------------  templating  -------------------------------------------

template <class T>
void insertObject(string fileName, T object) {
	ofstream myFile(fileName, ios::binary | ios::app);
	myFile.write((char*)&object, sizeof(object));
	myFile.close();
}
//------------------------------------

void retrieve_d_Object (string fileName,string user_name, string password, int check) 
{
	Doctors d;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&d, sizeof(d))) 
	{
		// get username and get password are in user class.
		if ((d.get_user_name() == user_name) && (d.get_password() == password))
		{	
			int x;
			//check = 1;
			whats_up();
			d.display1();
			cin >> x;
			int y = 1;
			while (y == 1) 
			{
				while (x < 1 && x>7)
				{
					cout << "Please enter a valid number from 1 -7." << endl;
					cin >> x;
				}
				if (x == 1)
				{
					// View profile.
					d.display();

					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1) 
					{
						d.display1();
						continue;
					}
					else 
					{
						break;
					}
				}
				else if (x == 2)
				{
					// Edit availability.
					cout << "Availability Hours: " << endl;
					int slots = d.get_slots();
					for (int i = 0; i < slots; i++)
					{
						for (int j = 0; j < 6; i++)
						{
							cout << d.get_hours()[i][j];
							if (j == 1 || j == 3)
							{
								cout << ":";
							}
							cout << endl;
						}
					}
					d.set_availability_hours();
					Doctors temp;
					fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
					while (myFile.read((char*)&temp, sizeof(temp)))
					{
						if (temp.get_cnic() == d.get_cnic())
						{
							temp.set_availability_hours(d.get_hours());
							//(d.get_hourly_charge());
							//strcpy(temp.get_name(), d.get_name());
							int current = myFile.tellg(); //tell g tells position of the pointer
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock); // seekg moves the pointer
							myFile.write((char*)&temp, sizeof(temp));
							myFile.close();
						}
					}
				

					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						d.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 3)
				{
					//Edit hourly charge.
					int charge = d.get_hourly_charge();
					cout << "Hourly Charge: Rs." << charge;
					d.set_hourly_charge();
					cout << "Hourly Charge: Rs." << d.get_hourly_charge();
					Doctors temp;
					fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
					while (myFile.read((char*)&temp, sizeof(temp)))
					{
						if (temp.get_cnic() == d.get_cnic())
						{
							temp.set_hourly_charge(d.get_hourly_charge());
							strcpy(temp.get_name(), d.get_name());
							int current = myFile.tellg(); //tell g tells position of the pointer
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock); // seekg moves the pointer
							myFile.write((char*)&temp, sizeof(temp));
							myFile.close();
						}
					}
					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						d.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 4)
				{
					// View appointment data.
					int slots = d.get_slots();
					appointment* a = new appointment[slots];
					// Pointing a pointer to an array of appointment objects on heap.
					appointment* ap = a;
					d.set_appointment(ap);
					for (int i = 0; i < slots; i++)
					{
						// Set doctor's cnic
						(ap + i)->set_d_cnic(d.get_cnic());
						//Set doctor's name of appoinment.
						(ap + i)->set_d_name(d.get_name());
						for (int j = 0; j < 3; j++)
						{
							// Set datetime of the appointment according to the availability hours of doctor.
							(ap + i)->set_date_time(d.get_hours()[j][0], d.get_hours()[j][1], d.get_hours()[j][2]);
						}
					}
					// Insering appoinment object
					ofstream myFile("Appoinment.bin", ios::binary | ios::app);
					for (int i = 0; i < slots; i++) 
					{
						myFile.write((char*)&a+i, sizeof(a));
						myFile.close();
					}
					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\////////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						d.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 5)
				{
					//View Specialization.
					Doctors temp;
					ifstream myFile(fileName, ios::binary);
					while (myFile.read((char*)&temp, sizeof(temp))) {
						if (temp.get_cnic() ==d.get_cnic()) {
							cout << "Specialization: "<< temp.get_specialization();
							myFile.close();
						}
					}

					//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////\\\\\\\\\\\\\\\\\\\\\//
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						d.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 6)
				{
					//Edit appointment data .
					int slots = d.get_slots();
					appointment* a = new appointment[slots];
					// Pointing a pointer to an array of appointment objects on heap.
					appointment* ap = a;
					d.set_appointment(ap);
					for (int i = 0; i < slots; i++)
					{
						// Set doctor's cnic
						(ap + i)->set_d_cnic(d.get_cnic());
						//Set doctor's name of appoinment.
						(ap + i)->set_d_name(d.get_name());
						for (int j = 0; j < 3; j++)
						{
							// Set datetime of the appointment according to the availability hours of doctor.
							(ap + i)->set_date_time(d.get_hours()[j][0], d.get_hours()[j][1], d.get_hours()[j][2]);
						}
					}
					// Insering appoinment object
					ofstream myFile("Appoinment.bin", ios::binary | ios::app);
					for (int i = 0; i < slots; i++)
					{
						myFile.write((char*)&a + i, sizeof(a));
						myFile.close();
					}

					//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////\\\\\\\\\\\\\\\\\\\\\/
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						d.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 7)
				{
					//Edit Profile
					
					d.display();
					int v;
					cout << "1-> edit Name." << endl << "2-> Edit Gender." << endl << "3-> Edit Contact." << endl;
					cout << "4-> Edit specification." << endl << "5-> Edit hospital." << endl << "6-> Edit City." << endl;
					cin >> v;
					if (v == 1) 
					{
						d.set_name();
						Doctors temp;
						fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
						while (myFile.read((char*)&temp, sizeof(temp))) 
						{
							if (temp.get_cnic() == d.get_cnic())
							{
								strcpy(temp.get_name(), d.get_name());
								int current = myFile.tellg(); //tell g tells position of the pointer
								int oneblock = sizeof(temp);
								myFile.seekg(current - oneblock); // seekg moves the pointer
								myFile.write((char*)&temp, sizeof(temp));
								myFile.close();
							}
						}
					}
					else if (v == 2) 
					{
						d.set_gender();
						Doctors temp;
						fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
						while (myFile.read((char*)&temp, sizeof(temp)))
						{
							if (temp.get_cnic() == d.get_cnic())
							{
								temp.set_gender(d.get_gender());
								int current = myFile.tellg(); //tell g tells position of the pointer
								int oneblock = sizeof(temp);
								myFile.seekg(current - oneblock); // seekg moves the pointer
								myFile.write((char*)&temp, sizeof(temp));
								myFile.close();
							}
						}
					}
					else if (v == 3) 
					{
						d.set_contact();
						Doctors temp;
						fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
						while (myFile.read((char*)&temp, sizeof(temp)))
						{
							if (temp.get_cnic() == d.get_cnic())
							{
								strcpy(temp.get_contact(), d.get_contact());
								int current = myFile.tellg(); //tell g tells position of the pointer
								int oneblock = sizeof(temp);
								myFile.seekg(current - oneblock); // seekg moves the pointer
								myFile.write((char*)&temp, sizeof(temp));
								myFile.close();
							}
						}
					}
					else if (v == 4) 
					{
						d.set_specialization();
						Doctors temp;
						fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
						while (myFile.read((char*)&temp, sizeof(temp)))
						{
							if (temp.get_cnic() == d.get_cnic())
							{
								strcpy(temp.get_specialization(), d.get_specialization());
								int current = myFile.tellg(); //tell g tells position of the pointer
								int oneblock = sizeof(temp);
								myFile.seekg(current - oneblock); // seekg moves the pointer
								myFile.write((char*)&temp, sizeof(temp));
								myFile.close();
							}
						}
					}
					else if (v == 5) 
					{
						d.set_hospital();
						Doctors temp;
						fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
						while (myFile.read((char*)&temp, sizeof(temp)))
						{
							if (temp.get_cnic() == d.get_cnic())
							{
								strcpy(temp.get_hospital(), d.get_hospital());
								int current = myFile.tellg(); //tell g tells position of the pointer
								int oneblock = sizeof(temp);
								myFile.seekg(current - oneblock); // seekg moves the pointer
								myFile.write((char*)&temp, sizeof(temp));
								myFile.close();
							}
						}


					}
					else if (v == 6) 
					{
						d.set_city();
						Doctors temp;
						fstream myFile("Doctors.bin", ios::in | ios::out | ios::binary);
						while (myFile.read((char*)&temp, sizeof(temp)))
						{
							if (temp.get_cnic() == d.get_cnic())
							{
								strcpy(temp.get_city(), d.get_city());
								int current = myFile.tellg(); //tell g tells position of the pointer
								int oneblock = sizeof(temp);
								myFile.seekg(current - oneblock); // seekg moves the pointer
								myFile.write((char*)&temp, sizeof(temp));
								myFile.close();
							}
						}
						
					}
					// Updating object in file

					


					//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////\\\\\\\\\\\\\\\\\\\\\/
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						d.display1();
						continue;
					}
					else
					{
						break;
					}
				}
			}
			
			myFile.close();
			//return d;
		}
	}
	//return d;

}
void retrieve_p_Object(string fileName, string user_name, string password, int check ) {
	//Doctors d;
	Patients p;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&p, sizeof(p))) {
		if ((p.get_user_name() == user_name) && (p.get_password() == password))
		{
			int x;
			check = 2;
			p.display1();
			cin >> x;
			int y = 1;
			while (y == 1) 
			{
				while (x < 1 && x>7)
				{
					cout << "Please enter a valid number from 1 -7." << endl;
					cin >> x;
				}
				if (x == 1) 
				{
					// Reset password


					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 2) 
				{
					// Search doctors.
					string specialization;


					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x ==3)
				{
					// Manage appointments.

					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 4) 
				{
					// Edit profile

					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 5) 
				{
					// View appointmentss

					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 6) 
				{
					// Recharge account.


					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
				else if (x == 7)
				{
					// Make appointment.
					char x;
					cout << "Do you want to set a) inperson appointment or b) video appointment?" << endl;
					cin >> x;
					while (x != 'a' && x != 'b') 
					{
						cout << "Enter a or b to choose ther type of appointment." << endl;
						cin >> x;
					}
					if (x == 'a') 
					{
						//appointment* app = new appointment();
						//int 
						char status, choice;
						cout << "Enter the status of appoinment.a) booked ,b) cancelled, c) pending " << endl;
						cin >> status;
						cout << "Do you want to search for doctors through" << endl << "a)Specialization" << endl << "b) City" << endl;
						cin >> choice;
						while (choice != 'a' && choice != 'b') 
						{
							cout << "Enter a or b." << endl;
							cin >> choice;
						}
						if (choice == 'a') 
						{
							cout << "Enter Specialization." << endl;
							string specs;
							cin >> specs;
							
							Doctors temp;
							ifstream myFile("Doctors.bin", ios::binary);
							while (myFile.read((char*)&temp, sizeof(temp))) 
							{
								if (temp.get_specialization() == specs) 
								{
									temp.display();
									//myFile.close();
									cout << "Do you wish to a) see another doctor or b) do you want to book?" << endl;
									char choice1;
									cin >> choice1;
									if (choice1 == 'a')
									{
										int current = myFile.tellg(); //tell g tells position of the pointer
										int oneblock = sizeof(temp);
										myFile.seekg(current - oneblock); // seekg moves the pointer
										//myFile.read((char*)&temp, sizeof(temp));
										continue;
									}
									else if (choice1 == 'b')
									{
										
									}
								}
							}
						}
						else if (choice == 'b') 
						{

						}
						
						in_person(p.get_cnic(), p.get_cnic(), status,);
					}
					else if (x =='b') 
					{

					}



					//\\\\\\\\\\\\\\\\\\\\//////////////////////////\\\\\\\\\\\\\\\\\\\\\//////////
					cout << "Please enter 1 to return to main menu and 0 to escape and end." << endl;
					if (y == 1)
					{
						p.display1();
						continue;
					}
					else
					{
						break;
					}
				}
			}
			//myFile.close();
			//return p;
		}
	}
	//return p;
}