#include "SuperUser.h"

#include "TravelAgency.h"

#include <iostream>

// constructor not use to declare a SuperUser in the main without a lot of characteristic
SuperUser::SuperUser()
{
    //ctor
}

// destructor
SuperUser::~SuperUser()
{
    //dtor
}

// create SuperUser with all the characteristic
void SuperUser::createSuperUser(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    email = _email;
    username = _username;
    password = _password;
    name = _name;
    surname = _surname;
    address = _address; 
    is_login = false;
}

// print all the informations about the SuperUser
void SuperUser::printSuperUser()
{
    cout << superUser_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// SuperUser functions (login need)

    // call the function addEmployee in TravelAgency
    void SuperUser::addEmployee(TravelAgency* travelAgency, string _email, string _username, string _password, string _name, string _surname, string _address)
    {
        travelAgency->addEmployee(_email, _username,_password,_name, _surname, _address);
    }

    // call the function removeEmployee in TravelAgency
    void SuperUser::removeEmployee(TravelAgency* travelAgency, int _employee_id)
    {
        travelAgency->removeEmployee(_employee_id);
    }


// Setter

    void SuperUser::setSUID(int id)
    {
        superUser_id = id;
    }

//