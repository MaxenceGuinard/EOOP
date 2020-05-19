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
    is_login = false;
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


void Employee::logIn()
{
    cout << "Successfully connected to " << email << " account." << endl;
    is_login = true;
}

void Employee::logOut()
{
    cout << "Successfully disconnected." << endl;
    is_login = false;
}

void Employee::setID(int id)
{
    employee_id = id;
}

int Employee::getID()
{
    return employee_id;
}

string Employee::getEmail()
{
    return email;
}

string Employee::getPassword()
{
    return password;
}

void Employee::sayHello()
{
    cout << "Hello I'm " << name << endl;
    name = "Maxence";
    cout << "Hello I'm " << name << endl;
}