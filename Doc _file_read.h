#pragma once
#pragma once
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
#include "Functions.h"
#include "Patients.h"
#include "Payment.h"
#include "User.h"
#include "Pat_file_read.h"
//#include "Doc _file_read.h"

// --------------------------------------------------------FILE HANDLING------------------------------------------------
void insertObject(string fileName, Doctors object) {
	ofstream myFile(fileName, ios::binary | ios::app);
	myFile.write((char*)&object, sizeof(object));
	myFile.close();
}

void retrieveObject(string fileName, int rollNumber) {
	Doctors temp;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.getRollNumber() == rollNumber) {
			temp.display();
			myFile.close();
		}
	}
}
void retrieveAll(string fileName) {
	Doctors temp;
	ifstream myFile(fileName, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		temp.display();
	}
	myFile.close();
}
void updateObject(string fileName, int rollNumber, string studentName) {
	Doctors temp;
	fstream myFile(fileName, ios::in | ios::out | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.getRollNumber() == rollNumber)
		{
			strcpy(temp.getStudentName(), studentName.c_str());
			int current = myFile.tellg(); //tell g tells position of the pointer
			int oneblock = sizeof(temp);
			myFile.seekg(current - oneblock); // seekg moves the pointer
			myFile.write((char*)&temp, sizeof(temp));
			myFile.close();
		}
	}
}
void deleteObject(const char* fileName, int rollNumber) {
	Doctors temp;
	fstream myFile(fileName, ios::in | ios::out | ios::binary);//does both  
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);// ofstream writes
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.getRollNumber() != rollNumber) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove(fileName);
	rename("temp.bin", fileName);
}