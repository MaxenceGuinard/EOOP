#include "Employee.h"

#include <iostream>
#include <vector>

vector<Employee> MyEmployees;

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

void Employee::createEmployee(int initializer_employee_id, string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    //Employee myEmployee;
    //myEmployee.
    employee_id = initializer_employee_id;
    //myEmployee.
    email = initializer_email;
    //myEmployee.
    username = initializer_username;
    //myEmployee.
    password = initializer_password;
    //myEmployee.
    name = initializer_name;
    //myEmployee.
    surname = initializer_surname;
    //myEmployee.
    address = initializer_address;
    //MyEmployees.push_back(myEmployee);    
}

void Employee::printEmployee()
{
    int MyEmployees_size = MyEmployees.size();
    for (int i = 0; i < MyEmployees_size; i++)
    {
        MyEmployees[i].print();
    }
    
}

void Employee::print()
{
    cout << email << username << name << surname << address << "ddf" <<  endl;
}

void Employee::addClient(){}
void Employee::updateClient(){}
void Employee::removeClient(){}
void Employee::createTravel(){}
void Employee::updateTravel(){}
void Employee::deleteTravel(){}
