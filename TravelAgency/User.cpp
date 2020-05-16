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

void User::updateAccount(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address)
{
    email = initializer_email;
    username = initializer_username;
    password = initializer_password;
    name = initializer_name;
    surname = initializer_surname;
    address = initializer_address; 
}

void User::showAccount()
{
    system("clear");

    cout << "Account informations:\n" << endl;
    cout << "Email: ------------------ " << email << endl;
    cout << "Username: --------------- " << username << endl;
    cout << "Name: ------------------- " << name << endl;
    cout << "Surname: ---------------- " << surname << endl;
    cout << "Address: ---------------- " << address << endl;

    cout << "\n\nPress enter to continue" << endl;
    cin.ignore();
    cin.get();
}

void User::deleteAccount(){}
