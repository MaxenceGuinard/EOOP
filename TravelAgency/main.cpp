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

void waitNoClear()
{
    cin.get();
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
            travelAgency->setEmployee(tempEmployee);

        tempEmployee.logout();
        travelAgency->printEmployee();
    wait();

    cout << "Login to a client (email = 3@gmail.com; password = password):" << endl;
        travelAgency->clientLogin("3@gmail.com", "password");
            
            tempClient = travelAgency->returnClient();
            //tempClient.updateAccount("3@gmail.com", "username", "password", "name3", "surname", "Address 3");
            travelAgency->setClient(tempClient);

        tempClient.logout();

        travelAgency->printClient();
    wait(); 

    cout << "Login to the SuperUser (email = superuser@etravel.com; password = password):" << endl;
        travelAgency->superUserLogin("superuser@etravel.com", "password");
        
            tempSuperUser = travelAgency->returnSuperUser();
            //
            travelAgency->setSuperUser(tempSuperUser);
    
        tempSuperUser.logout();

        travelAgency->printSuperUser();
    wait();

    cout << "Login to an employee to create four travel:" << endl;
        travelAgency->employeeLogin("2@etravel.com", "password");
        
            tempEmployee = travelAgency->returnEmployee();
            tempEmployee.createTravel(travelAgency, "New York",10, "22.05.2020", "28.05.2020", 6);
            tempEmployee.createTravel(travelAgency, "Warsaw", 35, "10.07.2020", "14.05.2020", 4);
            tempEmployee.createTravel(travelAgency, "Punta Cana",40, "10.07.2020", "16.07.2020", 6);
            tempEmployee.createTravel(travelAgency, "Paris", 40, "20.08.2020", "23.08.2020", 3);
            travelAgency->printTravel();
        waitNoClear();

        cout << "Modifying one travel (still connected with the same employee):" << endl;

            tempEmployee.updateTravel(travelAgency, 0, "Monaco", 15, "22.05.2020", "28.05.2020", 96);
            travelAgency->printTravel();
        waitNoClear();


        cout << "Deletion of one travel:" << endl;

            tempEmployee.deleteTravel(travelAgency, 1);
            travelAgency->printTravel();
    wait();
    
    cout << "Add four hotel in a travel (We are still connected with the employee):" << endl;

            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "Cinq étoiles", 120);
            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "Quatre étoiles", 96);
            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "Trois étoiles", 72);
            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "Deux étoiles", 48);
            travelAgency->printTravel();
        waitNoClear();

        cout << "Deletion of one Hotel:" << endl;

            tempEmployee.deleteHotel(travelAgency, 2, 1);
            travelAgency->printTravel();
    wait();

    cout << "Login to a client to book three travel:" << endl;
        travelAgency->clientLogin("3@gmail.com", "password");

            tempClient = travelAgency->returnClient();
            tempClient.addBooking(travelAgency, 1);
            tempClient.addBooking(travelAgency, 2);
            tempClient.addBooking(travelAgency, 3);
            tempClient.printBooking();
        waitNoClear();

        cout << "Deletion of a booking:" << endl;

            tempClient.deleteBooking(0);
            tempClient.printBooking();
    wait();

    cout << "Add three planes to a booking:" << endl;

            tempClient.addPlane(0,"AS1146", "19.08.2020", "WAW-CDG", "9:10-12:00", 150);
            tempClient.addPlane(0,"AF1146", "19.08.2020", "WAW-CDG", "9:10-12:00", 150);
            tempClient.addPlane(0,"AF1146", "23.08.2020", "CDG-WAW", "18:30-21:20", 130);
            tempClient.printBooking();
        waitNoClear();

        cout << "Modify the plane (id = 0):" << endl;

            tempClient.updatePlane(0, 0, "AS1146", "20.08.2020", "WAW-CDG", "9:10-12:00", 150);
            tempClient.printBooking();
        waitNoClear();

        cout << "Deletion of a plane:" << endl;

            tempClient.deletePlane(0, 0);
            tempClient.printBooking();
    wait();

    cout << "Add three trains to a booking:" << endl;

            tempClient.addTrain(0,"RGB-5288", "19.08.2020", "ANGERS-CDG", "5:00-7:30", 50);
            tempClient.addTrain(0,"TGV-5288", "20.08.2020", "ANGERS-CDG", "5:00-7:30", 50);
            tempClient.addTrain(0,"TGV-5467", "23.08.2020", "CDG-ANGERS", "22:00-00:20", 45);
            tempClient.printBooking();
        waitNoClear();

        cout << "Modify the train (id = 0):" << endl;

            tempClient.updateTrain(0, 0, "RGB-5288", "20.08.2020", "ANGERS-CDG", "5:00-7:30", 50);
            tempClient.printBooking();
        waitNoClear();

        cout << "Deletion of a train:" << endl;

            tempClient.deleteTrain(0, 0);
            tempClient.printBooking();
    wait();


    cout << "Deletion of the travel agency:" << endl;
        travelAgency->bankrupt();

    wait();


    system("clear");
    return 0;
}
