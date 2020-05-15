#include "User.h"

#include <iostream>
#include <unistd.h> // sleep
#include <termios.h>// secret password

User::User()
{
    //user_id = 0; Do it automatic with vectors
}

User::~User()
{
    //dtor
}

void User::updateAccount()
{
    int interrupt_flag = 0;
    int answer_id = 0;

    string first_entry_email, second_entry_email;
    string entry_username;
    string first_entry_password, second_entry_password;
    string entry_name;
    int entry_name_size;
    string entry_surname;
    int entry_surname_size;
    string entry_address;


    while(interrupt_flag == 0){

        system("clear");
        cout << "Which field do you want to update ?" << endl;
        cout << "1: Email\n2: Username\n3: Password\n4: Name\n5: Surname\n6: Address\n7: Quit" << endl;
        cin >> answer_id;

        switch(answer_id){

            // email
            case 1:
                        if(checkIdentity())
                        {
                            system("clear");
                            cout << "Updating email. Please write your new email:" << endl;
                            cin >> first_entry_email;
                            system("clear");
                            cout << "Confirm your email:" << endl;
                            cin >> second_entry_email;

                            if(first_entry_email == second_entry_email)
                            {
                                email = first_entry_email;
                                system("clear");
                                cout << "Email succesfully modified, your new email is : " << email << endl;
                            }
                            else
                            {
                                system("clear");
                                cout << "Invalid email." << endl;
                            }

                            cout << "\n\nPress enter to continue" << endl;
                            cin.ignore();
                            cin.get();
                        }
                        break;
            // username
            case 2:
                        system("clear");
                        cout << "Updating username. Please write your new username:" << endl;
                        cin >> entry_username;
                        //Check username list
                        /*
                        if(test)
                        {
                            cout << "Username succesfully modified, your new usename is :" << username << "\n" << endl;
                        }
                        else
                        {
                            cout << "Unfortunately " << username << " is already registered in our system.\n"
                        }
                        */

                        username = entry_username;
                        system("clear");
                        cout << "Username succesfully modified, your new usename is : " << username << endl;

                        cout << "\n\nPress enter to continue" << endl;
                        cin.ignore();
                        cin.get();
                        break;
            // password
            case 3:
                        if(checkIdentity())
                        {
                            system("clear");
                            cout << "Updating password. Please write your new password:" << endl;
                            secretTextOn();
                            cin >> first_entry_password;
                            system("clear");
                            cout << "Confirm your password:" << endl;
                            cin >> second_entry_password;
                            secretTextOff();

                            if(first_entry_password == second_entry_password)
                            {
                                password = first_entry_password;
                                system("clear");
                                cout << "Password succesfully modified." << endl;
                            }
                            else
                            {
                                system("clear");
                                cout << "Invalid password." << endl;
                            }
                            cout << "\n\nPress enter to continue" << endl;
                            cin.ignore();
                            cin.get();
                        }
                        break;
            // name
            case 4:
                        system("clear");
                        cout << "Updating name. Please write your name." << endl;
                        cin.ignore();
                        getline (cin, entry_name);
                        entry_name_size = entry_name.size();

                        for (int i = 0; i < entry_name_size; i++)
                        {
                            entry_name[i] = tolower(entry_name[i]);
                        }

                        entry_name[0] = toupper(entry_name[0]);

                        for (int j = 0; j < entry_name_size; j++)
                        {
                            if(entry_name[j] == ' ')
                            {
                                entry_name[j + 1] = toupper(entry_name[j + 1]);
                            }
                        }
                        name = entry_name;
                        system("clear");
                        cout << "Name succesfully modified, your registered name is now: " << name << endl;

                        cout << "\n\nPress enter to continue" << endl;
                        cin.get();
                        break;
            // surname
            case 5:
                        system("clear");
                        cout << "Updating surname. Please write your surname." << endl;
                        cin.ignore();
                        getline (cin, entry_surname);
                        entry_surname_size = entry_surname.size();

                        for (int i = 0; i < entry_surname_size; i++)
                        {
                            entry_surname[i] = tolower(entry_surname[i]);
                        }

                        entry_surname[0] = toupper(entry_surname[0]);

                        for (int j = 0; j < entry_surname_size; j++)
                        {
                            if(entry_surname[j] == ' ')
                            {
                                entry_surname[j + 1] = toupper(entry_surname[j + 1]);
                            }
                        }
                        surname = entry_surname;
                        system("clear");
                        cout << "Surname succesfully modified, your registered surname is now: " << surname << endl;

                        cout << "\n\nPress enter to continue" << endl;
                        cin.get();
                        break;
            // address
            case 6:
                        system("clear");
                        cout << "Updating address. Please write your address." << endl;
                        cin.ignore();
                        getline (cin, entry_address);
                        address = entry_address;
                        system("clear");
                        cout << "Surname succesfully modified, your registered surname is now: " << address << endl;

                        cout << "\n\nPress enter to continue" << endl;
                        cin.get();
                        break;
            // quit
            case 7:
                        system("clear");
                        cout << "Return to previous menu.." << endl;
                        interrupt_flag = 1;
                        sleep(1);
                        break;

            default:
                        system("clear");
                        cout << "Incorrect Entry.\n" << endl;

                        cout << "\n\nPress enter to continue" << endl;
                        cin.ignore();
                        cin.get();
                        break;

        }
    }
}

bool User::checkIdentity()
{
    system("clear");
    string _password;
    cout << "Please type your actif password:" << endl;
    cin.ignore();
    secretTextOn();
    getline (cin, _password);
    secretTextOff();
    system("clear");
    if(_password == password)
    {
        cout << "Successful authentication..." << endl;
        sleep(1);
        return true;
    }
    else
    {
        cout << "Failed authentication..." << endl;
        sleep(1);
        cout << "\n\nPress enter to continue" << endl;
        cin.get();
        return false;
    }
}

void User::secretTextOn()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void User::secretTextOff()
{
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
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
