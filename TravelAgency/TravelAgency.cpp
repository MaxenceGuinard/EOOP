#include "TravelAgency.h"

#include <iostream>

TravelAgency::TravelAgency(string initializer_name, string initializer_address)
{
    name = initializer_name;
	address = initializer_address;
	employee_number = 0;
	client_number = 0;
}

TravelAgency::~TravelAgency()
{
    //dtor
}

void TravelAgency::showAgencyDetails()
{
    system("clear");

    cout << "Travel Agency informations:\n" << endl;
    cout << "Name: ------------------- " << name << endl;
    cout << "Address: ---------------- " << address << endl;
    cout << "Number of employee: ----- " << employee_number << endl;
    cout << "Number of client: ------- " << client_number << endl;

    cout << "\n\nPress enter to continue" << endl;
    cin.ignore();
    cin.get();
}

/*void TravelAgency::addEmployee(Employee myEmployee)
{
    tab_employee.push_back(myEmployee);
}*/

void TravelAgency::addEmployee(int initializer_employee_id, string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    Employee employee;
    employee.createEmployee(initializer_employee_id, initializer_email, initializer_username, initializer_password, initializer_name, initializer_surname, initializer_address);
    tab_employee.push_back(employee);
}

void TravelAgency::printEmployee()
{
    int nbrEmployee = tab_employee.size();
    for (int i = 0; i < nbrEmployee; i++)
    {
        tab_employee[i].print();
    }
    
}

void TravelAgency::addClient(){}

void TravelAgency::addSuperUser(){}

void TravelAgency::bankrupt(){}
