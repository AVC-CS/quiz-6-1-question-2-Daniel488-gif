#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int writeFile() {
    ofstream outFile("employee.txt");
    int numEmployees;

    cout << "Enter number of employees: ";
    cin >> numEmployees;
    outFile << numEmployees << endl;

    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        cout << "Enter ID, Name, Department, Salary: ";
        cin >> id >> name >> department >> salary;
        outFile << id << " " << name << " " << department << " " << salary << endl;
    }

    outFile.close();
    return numEmployees;
}

int readFile() {
    ifstream inFile("employee.txt");
    int numEmployees;
    inFile >> numEmployees;

    int id;
    string name, department;
    double salary, totalSalary = 0;

    cout << left << setw(10) << "ID" 
         << setw(10) << "Name" 
         << setw(15) << "Department" 
         << setw(10) << "Salary" << endl;

    for (int i = 0; i < numEmployees; ++i) {
        inFile >> id >> name >> department >> salary;
        cout << left << setw(10) << id 
             << setw(10) << name 
             << setw(15) << department 
             << setw(10) << fixed << setprecision(2) << salary << endl;
        totalSalary += salary;
    }

    cout << "Total: " << totalSalary 
         << " Average: " << totalSalary / numEmployees << endl;

    inFile.close();
    return numEmployees;
}
