#include <iostream>

#include "TravelAgency.h"
#include "User.h"
#include "Employee.h"
#include "Client.h"

#include <unistd.h> // sleep
#include <stdio.h>


int main()
{
    system("clear");
    //TravelAgency* ptr_TravelAgency = new TravelAgency("eTravel", "New York City");

    cout << "This program is made to emulate one travel agency website.\n" << endl;
    cout << "UNITS TESTS\nPress Enter to continue (Valid during the whole operation of the program)\n" << endl;
        cin.get();
        system("clear");
    
    cout << "Travel agency creation:" << endl;
        TravelAgency* travelAgency = new TravelAgency("eTravel", "New York City");
        travelAgency->showAgencyDetails();
        cin.get();
        system("clear");

    cout << "Creation of four employee including the SuperUser:" << endl;
        travelAgency->addEmployee("0@e.com", "0e", "password", "name0", "surname", "Address 0");
        travelAgency->addEmployee("1@e.com", "1e", "password", "name1", "surname", "Address 1");
        travelAgency->addEmployee("2@e.com", "2e", "password", "name2", "surname", "Address 2");
        travelAgency->addEmployee("3@e.com", "3e", "password", "name3", "surname", "Address 3");
        travelAgency->printEmployee();
        cin.get();
        system("clear");

    cout << "Creation of two clients:" << endl;
        travelAgency->addClient("0@e.com", "0e", "password", "name0", "surname", "Address 0");
        travelAgency->addClient("1@e.com", "1e", "password", "name1", "surname", "Address 1");
        travelAgency->addClient("2@e.com", "2e", "password", "name2", "surname", "Address 2");
        travelAgency->addClient("3@e.com", "3e", "password", "name3", "surname", "Address 3");
        travelAgency->printClient();
        cin.get();
        system("clear");
    
    cout << "Deletion of an employee and a client:" << endl;
        cout << "\nBEFORE:" << endl;
            cout << "Employee:" << endl;
            travelAgency->printEmployee();
            cout << "Client:" << endl;
            travelAgency->printClient();
        
    travelAgency->removeEmployee(1);
    travelAgency->removeClient(0);

        cout << "\nAFTER:" << endl;
            cout << "Employee:" << endl;
            travelAgency->printEmployee();
            cout << "Client:" << endl;
            travelAgency->printClient();
    cin.get();
    system("clear");

    cout << "Deletion of the travel agency" << endl;
        travelAgency->bankrupt();

    cin.get();
    system("clear");


    system("clear");
    return 0;
}
