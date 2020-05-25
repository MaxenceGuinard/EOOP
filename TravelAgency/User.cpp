#include "User.h"

#include <iostream>
#include <unistd.h> // sleep
#include <termios.h>// secret password

// constructor
User::User()
{

}

// destructor
User::~User()
{
    //dtor
}

// Account functions (login need)
// set the status is_login
void User::login()
{
    cout << "Successfully connected to " << email << " account." << endl;
    is_login = true;
}

    // update all the information of the account
    void User::updateAccount(string _email, string _username, string _password, string _name, string _surname, string _address)
    {
        email = _email;
        username = _username;
        password = _password;
        name = _name;
        surname = _surname;
        address = _address; 
    }

// set the status is not login
void User::logout()
{
    cout << "Successfully disconnected." << endl;
    is_login = false;
}

bool User::isLogin()
{
    return is_login;
}