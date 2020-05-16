#include "Employee.h"

#include <iostream>

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
    employee_id = initializer_employee_id;
    email = initializer_email;
    username = initializer_username;
    password = initializer_password;
    name = initializer_name;
    surname = initializer_surname;
    address = initializer_address; 
}

void Employee::printEmployee()
{
    cout << employee_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

void Employee::addClient(){}
void Employee::updateClient(){}
void Employee::removeClient(){}

void Employee::createTravel(){}
void Employee::updateTravel(){}
void Employee::deleteTravel(){}

int Employee::getID()
{
    return employee_id;
}