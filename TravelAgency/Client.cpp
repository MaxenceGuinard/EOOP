#include "Client.h"

#include "TravelAgency.h"

#include <iostream>

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}

// Call by TravelAgency.cpp
void Client::createClient(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    email = _email;
    username = _username;
    password = _password;
    name = _name;
    surname = _surname;
    address = _address; 
    is_login = false;
}

void Client::printClient()
{
    cout << client_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// Client functions (login need)

    void Client::deleteAccount(TravelAgency* travelAgency)
    {
        travelAgency->removeClient(client_id);
    }

//

// Getter

    int Client::getID()
    {
        return client_id;
    }

    string Client::getEmail()
    {
        return email;
    }

    string Client::getPassword()
    {
        return password;
    }

//

// Setter

    void Client::setID(int id)
    {
        client_id = id;
    }

//