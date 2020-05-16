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

void Client::createClient(int initializer_client_id, string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    client_id = initializer_client_id;
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

int Client::getID()
{
    return client_id;
}