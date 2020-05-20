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

// Call by TravelAgency.cpp
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

// Employee functions (login need)

    // Client help functions
    void Employee::addClient(){}
    void Employee::updateClient(){}
    void Employee::removeClient(){}

    // Travel functions
    void Employee::createTravel(){}
    void Employee::updateTravel(){}
    void Employee::deleteTravel(){}

//

// Getter
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
//

// Setter
    void Employee::setID(int id)
    {
        employee_id = id;
    }
//




void Employee::sayHello()
{
    cout << "Hello I'm " << name << endl;
    name = "Maxence";
    cout << "Hello I'm " << name << endl;
}