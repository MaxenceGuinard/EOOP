#include "User.h"

#include <iostream>
#include <unistd.h> // sleep
#include <termios.h>// secret password

User::User()
{

}

User::~User()
{
    //dtor
}

// Account functions (login need)
void User::login()
{
    cout << "Successfully connected to " << email << " account." << endl;
    is_login = true;
}

    // Client help functions
    void User::updateAccount(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
    {
        email = initializer_email;
        username = initializer_username;
        password = initializer_password;
        name = initializer_name;
        surname = initializer_surname;
        address = initializer_address; 
    }

void User::logout()
{
    cout << "Successfully disconnected." << endl;
    is_login = false;
}







bool User::isLogin()
{
    return is_login;
}