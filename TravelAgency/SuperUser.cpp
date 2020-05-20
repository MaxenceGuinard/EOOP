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

void SuperUser::createSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    email = initializer_email;
    username = initializer_username;
    password = initializer_password;
    name = initializer_name;
    surname = initializer_surname;
    address = initializer_address; 
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