#include <iostream>

#include "TravelAgency.h"
#include "User.h"
#include "Employee.h"
#include "Client.h"

#include <unistd.h> // sleep
#include <stdio.h>

void wait()
{
    cin.get();
    system("clear");
}

int main()
{
    system("clear");

    cout << "This program is made to emulate one travel agency website.\n" << endl;
    cout << "UNITS TESTS\nPress Enter to continue (Valid during the whole operation of the program)\n" << endl;
        wait();
    
    cout << "Travel agency creation:" << endl;
        TravelAgency* travelAgency = new TravelAgency("eTravel", "New York City");
        travelAgency->showAgencyDetails();
        wait();

    cout << "Creation of four employee including the SuperUser:" << endl;
        travelAgency->addEmployee("0@e.com", "0e", "password", "name0", "surname", "Address 0");
        travelAgency->addEmployee("1@e.com", "1e", "password", "name1", "surname", "Address 1");
        travelAgency->addEmployee("2@e.com", "2e", "password", "name2", "surname", "Address 2");
        travelAgency->addEmployee("3@e.com", "3e", "password", "name3", "surname", "Address 3");
        travelAgency->printEmployee();
        wait();

    cout << "Creation of two clients:" << endl;
        travelAgency->addClient("0@e.com", "0e", "password", "name0", "surname", "Address 0");
        travelAgency->addClient("1@e.com", "1e", "password", "name1", "surname", "Address 1");
        travelAgency->addClient("2@e.com", "2e", "password", "name2", "surname", "Address 2");
        travelAgency->addClient("3@e.com", "3e", "password", "name3", "surname", "Address 3");
        travelAgency->printClient();
        wait();
    
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
    wait();

    cout << "Login to an employee" << endl;
        travelAgency->employeeLogin("1@e.com", "password");
        Employee tempEmployee;
        tempEmployee = travelAgency->returnEmployee();
        tempEmployee.sayHello();
        travelAgency->setEmployee(tempEmployee);
        tempEmployee.logOut();
        travelAgency->printEmployee();
    wait();

    cout << "Deletion of the travel agency" << endl;
        travelAgency->bankrupt();

    wait();


    system("clear");
    return 0;
}
