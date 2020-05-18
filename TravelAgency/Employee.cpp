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

void Employee::createEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
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

void Employee::setID(int id)
{
    employee_id = id;
}

int Employee::getID()
{
    return employee_id;
}