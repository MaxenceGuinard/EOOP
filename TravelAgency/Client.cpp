#include "Client.h"

#include <iostream>

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}

void Client::createClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    email = initializer_email;
    username = initializer_username;
    password = initializer_password;
    name = initializer_name;
    surname = initializer_surname;
    address = initializer_address; 
}

void Client::printClient()
{
    cout << client_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

void Client::setID(int id)
{
    client_id = id;
}

int Client::getID()
{
    return client_id;
}