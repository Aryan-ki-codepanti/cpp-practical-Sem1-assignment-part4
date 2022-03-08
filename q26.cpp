#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
    int roll, year;
    float total_marks;
    char name[30];
    char class_name[30];

public:
    Student()
    {
        roll = 0;
        year = 0;
        total_marks = 0;
        strcpy(name, "no name");
        strcpy(class_name, "no class");
    }

    void inputStudent()
    {
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter total marks: ";
        cin >> total_marks;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 29);
        cout << "Enter class: ";
        cin.ignore();
        cin.getline(class_name, 29);
    }

    void outputStudent()
    {
        cout << roll << " " << name << " " << total_marks << endl;
    }

    void storeInFile()
    {
        ofstream out("student.dat", ios::app | ios::binary);
        out.write((char *)this, sizeof(*this));
        out.close();
    }

    void getStudents()
    {
        ifstream inp("student.dat", ios::binary);

        inp.read((char *)this, sizeof(*this));
        while (!inp.eof())
        {
            outputStudent();
            inp.read((char *)this, sizeof(*this));
        }

        inp.close();
    }
};


int main()
{
    Student s;
    cout << "10 Students retrieved" << endl;
    s.getStudents();
    return 0;
}