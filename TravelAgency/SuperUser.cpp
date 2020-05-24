#include "SuperUser.h"

#include "TravelAgency.h"

#include <iostream>

SuperUser::SuperUser()
{
    //ctor
}

SuperUser::~SuperUser()
{
    //dtor
}

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

void SuperUser::printSuperUser()
{
    cout << superUser_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// SuperUser functions (login need)

    void SuperUser::addEmployee(TravelAgency* travelAgency, string _email, string _username, string _password, string _name, string _surname, string _address)
    {
        travelAgency->addEmployee(_email, _username,_password,_name, _surname, _address);
    }

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