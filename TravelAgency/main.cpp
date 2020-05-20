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

    Employee tempEmployee;
    Client tempClient;
    SuperUser tempSuperUser;        

int main()
{
    system("clear");

    cout << "This program is made to emulate one travel agency website.\n" << endl;
    cout << "UNITS TESTS\nPress Enter to continue (Valid during the whole operation of the program)\n" << endl;
        wait();
    
    cout << "Travel agency creation plus the default SuperUser:" << endl;
        TravelAgency* travelAgency = new TravelAgency("eTravel", "New York City");
        travelAgency->showAgencyDetails();
        travelAgency->printSuperUser();
        wait();

    cout << "Creation of four employees:" << endl;
        travelAgency->addEmployee("0@etravel.com", "0u", "password", "name0", "surname", "Address 0");
        travelAgency->addEmployee("1@etravel.com", "1u", "password", "name1", "surname", "Address 1");
        travelAgency->addEmployee("2@etravel.com", "2u", "password", "name2", "surname", "Address 2");
        travelAgency->addEmployee("3@etravel.com", "3u", "password", "name3", "surname", "Address 3");
        travelAgency->printEmployee();
        wait();

    cout << "Creation of four clients:" << endl;
        travelAgency->addClient("0@gmail.com", "0u", "password", "name0", "surname", "Address 0");
        travelAgency->addClient("1@gmail.com", "1u", "password", "name1", "surname", "Address 1");
        travelAgency->addClient("2@gmail.com", "2u", "password", "name2", "surname", "Address 2");
        travelAgency->addClient("3@gmail.com", "3u", "password", "name3", "surname", "Address 3");
        travelAgency->printClient();
        wait();
    
    cout << "Deletion of an employee(id = 0) and a client(id = 0):" << endl;
        cout << "BEFORE:" << endl;
            cout << "Employee:" << endl;
            travelAgency->printEmployee();
            cout << "Client:" << endl;
            travelAgency->printClient();
        
    travelAgency->removeEmployee(0);
    travelAgency->removeClient(0);

        cout << "AFTER:" << endl;
            cout << "Employee:" << endl;
            travelAgency->printEmployee();
            cout << "Client:" << endl;
            travelAgency->printClient();
    wait();

    cout << "Login to an employee (email = 1@etravel.com; password = password):" << endl;
        travelAgency->employeeLogin("1@etravel.com", "password");
        
            tempEmployee = travelAgency->returnEmployee();
            tempEmployee.sayHello();
            travelAgency->setEmployee(tempEmployee);
    
        tempEmployee.logout();

        travelAgency->printEmployee();
    wait();

    cout << "Login to a client (email = 3@gmail.com; password = password):" << endl;
        travelAgency->clientLogin("3@gmail.com", "password");
            
            tempClient = travelAgency->returnClient();
            tempClient.updateAccount("3@gmail.com", "username", "password", "name3", "surname", "Address 3");
            travelAgency->setClient(tempClient);

        tempClient.logout();

        travelAgency->printClient();
    wait(); 

    cout << "Login to the SuperUser (email = superuser@etravel.com; password = password):" << endl;
        travelAgency->superUserLogin("superuser@etravel.com", "password");
        
            tempSuperUser = travelAgency->returnSuperUser();
            tempSuperUser.sayHello();
            travelAgency->setSuperUser(tempSuperUser);
    
        tempSuperUser.logout();

        travelAgency->printSuperUser();
    wait();

    cout << "Deletion of the travel agency:" << endl;
        travelAgency->bankrupt();

    wait();


    system("clear");
    return 0;
}
