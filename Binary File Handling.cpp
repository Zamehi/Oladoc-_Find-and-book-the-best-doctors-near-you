#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    private:
        int rollNumber;
        char studentName[100];
    public:
        Student(int rollNumber=0, string studentName=""){
            this->rollNumber = rollNumber;
            strcpy(this->studentName, studentName.c_str()); //Copying in CStyle string-char[]
        }
        void display()
        {
            cout << "Roll Number:  " << rollNumber << endl;
            cout << "Student Name: " << studentName << endl << endl;
        }
        int& getRollNumber(){
            return rollNumber; 
        }
        char* getStudentName()
        {
            return studentName;
        }
};
void insertObject(string fileName, Student object){
    ofstream myFile(fileName, ios::binary | ios::app);
    myFile.write((char *)&object, sizeof(object));
    myFile.close();
}
void retrieveObject(string fileName, int rollNumber){
    Student temp;
    ifstream myFile(fileName, ios::binary);
    while(myFile.read((char *)&temp, sizeof(temp))){
        if(temp.getRollNumber() == rollNumber){
            temp.display();
            myFile.close();
        }
    }
}
void retrieveAll(string fileName){
    Student temp;
    ifstream myFile(fileName, ios::binary);
    while(myFile.read((char *)&temp, sizeof(temp)))
    {
        temp.display();
    }
    myFile.close();
}
void updateObject(string fileName, int rollNumber, string studentName){
    Student temp;
    fstream myFile(fileName, ios::in | ios::out | ios::binary);
    while(myFile.read((char *)&temp, sizeof(temp))){
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
void deleteObject(const char *fileName,int rollNumber){
    Student temp;
    fstream myFile(fileName, ios::in | ios::out | ios::binary);//does both  
    ofstream myFile_temp("temp.bin", ios::app | ios::binary);// ofstream writes
    while(myFile.read((char *)&temp, sizeof(temp))){
        if(temp.getRollNumber() != rollNumber){
            myFile_temp.write((char*)&temp, sizeof(temp));
        }
    }
    myFile.close();
    myFile_temp.close();
    remove(fileName);
    rename("temp.bin", fileName);
}
int main(){
    const char *fileName="Binaries.bin";

    //Run this one time to create data and store it in the 'Binaries.bin' file
    //After running, comment this following block of code to avoid any unwanted errors
    /*
    Student std1(1, "Bilal Ahmad");
    Student std2(2, "Hamza Khalid");
    Student std3(3, "Rayyan Zia");
    Student std4(4, "Moeez Muslim");
    insertObject(fileName, std1);
    insertObject(fileName, std2);
    insertObject(fileName, std3);
    insertObject(fileName, std4);
    cout<<"Data Insertion Success"<<endl;
    */

    //Run the following line to retrieve all the objects saved in the file
    //retrieveAll(fileName);

    //Make changes to object 4's name
    //updateObject(fileName, 4, "Rahat Usama");

    //Retrieve only one object
    //retrieveObject(fileName, 4);

    //Deletes a particular object present at the passed roll number's location
    //deleteObject(fileName, 4);

    //Retrieves all the object present in the file after updation and deletion
    //retrieveAll(fileName);
}