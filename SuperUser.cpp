#include "SuperUser.h"

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


// Setter

    void SuperUser::setSUID(int id)
    {
    superUser_id = id;
    }

//