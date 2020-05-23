#include <iostream>

#include "TravelAgency.h"
#include "User.h"
#include "Employee.h"
#include "Client.h"
#include "SuperUser.h"

#include <unistd.h> // sleep
#include <stdio.h>

int count = 1;
int sub_count = 1;
void wait()
{
    cin.get();
    system("clear");
    cout << count << ") ";
    count++;
    sub_count = 1;
    }

void waitNoClear()
{
    cin.get();
    cout << sub_count << ") ";
    sub_count++;
}

    Employee tempEmployee;
    Client tempClient;
    SuperUser tempSuperUser;   

int main()
{
    system("clear");

    cout << count << ") ";
    count++;
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
            tempClient.updateAccount("3@gmail.com", "username", "password", "name3", "surname", "Address 3");
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

    cout << "Login to an employee to create five travel:\n(d = day; p = place number; full right number = creator id)\n" << endl;
        travelAgency->employeeLogin("2@etravel.com", "password");
        
            tempEmployee = travelAgency->returnEmployee();
            tempEmployee.createTravel(travelAgency, "New York", 10, "22.05.2020", "28.05.2020", 6);
            tempEmployee.createTravel(travelAgency, "Alger", 35, "10.07.2020", "14.05.2020", 4);
            tempEmployee.createTravel(travelAgency, "Tokyo", 40, "10.07.2020", "16.07.2020", 6);
            tempEmployee.createTravel(travelAgency, "Paris", 40, "20.08.2020", "23.08.2020", 3);
            tempEmployee.createTravel(travelAgency, "Delhi", 0, "30.08.2020", "03.09.2020", 4);
            travelAgency->printTravel();
        waitNoClear();

        cout << "Modifying one travel (still connected with the same employee):" << endl;

            tempEmployee.updateTravel(travelAgency, 0, "Seoul", 15, "22.05.2020", "28.05.2020", 6);
            travelAgency->printTravel();
        waitNoClear();


        cout << "Deletion of one travel:" << endl;

            tempEmployee.deleteTravel(travelAgency, 1);
            travelAgency->printTravel();
    wait();

    cout << "Try to publish a travel without any hotel:" << endl;

            tempEmployee.publishTravel(travelAgency, 2);
    wait();
    
    cout << "Add four hotel in a travel (We are still connected with the employee):" << endl;

            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "5 étoiles", 120);
            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "4 étoiles", 96);
            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "3 étoiles", 72);
            tempEmployee.addHotel(travelAgency, 2, 1, "Paris", "2 étoiles", 48);
            travelAgency->printTravel();
        waitNoClear();

        cout << "Deletion of one Hotel:" << endl;

            tempEmployee.deleteHotel(travelAgency, 2, 1);
            travelAgency->printTravel();
    wait();

            tempEmployee.addHotel(travelAgency, 0, 6, "Seoul", "Hotel SEO", 70);
            tempEmployee.addHotel(travelAgency, 1, 6, "Tokyo", "Hotel TOK", 110);
            tempEmployee.addHotel(travelAgency, 3, 4, "Delhi", "Hotel DEL", 55);
            tempEmployee.publishTravel(travelAgency, 0);
            tempEmployee.publishTravel(travelAgency, 1);
            tempEmployee.publishTravel(travelAgency, 3);
            system("clear");

    cout << "Try to publish a the travel to Paris:" << endl;

            tempEmployee.publishTravel(travelAgency, 2);
            
            travelAgency->setEmployee(tempEmployee);
            tempEmployee.logout();
    wait();

    cout << "Login to a client to book four travel (with one not available):\n(first number is the travel_id; last number is the Boolean variable 'is_payed')\n" << endl;
        travelAgency->clientLogin("3@gmail.com", "password");

            tempClient = travelAgency->returnClient();
            tempClient.addBooking(travelAgency, 0);
            tempClient.addBooking(travelAgency, 1);
            tempClient.addBooking(travelAgency, 2);
            tempClient.addBooking(travelAgency, 3);
            tempClient.printBooking(travelAgency);
        waitNoClear();

        cout << "Deletion of a booking:" << endl;

            tempClient.deleteBooking(travelAgency, 0);
            tempClient.printBooking(travelAgency);
    wait();

    cout << "Add three planes to a booking:" << endl;

            tempClient.addPlane(travelAgency, 1,"AS1146", "19.08.2020", "WAW-CDG", "9:10-12:00", 140);
            tempClient.addPlane(travelAgency, 1,"AF1146", "19.08.2020", "WAW-CDG", "9:10-12:00", 150);
            tempClient.addPlane(travelAgency, 1,"AF1146", "23.08.2020", "CDG-WAW", "18:30-21:20", 130);
            tempClient.printBooking(travelAgency);
        waitNoClear();

        cout << "Modify the plane (id = 0):" << endl;

            tempClient.updatePlane(travelAgency, 1, 0, "AS1146", "20.08.2020", "WAW-CDG", "9:10-12:00", 150);
            tempClient.printBooking(travelAgency);
        waitNoClear();

        cout << "Deletion of a plane:" << endl;

            tempClient.deletePlane(travelAgency, 1, 0);
            tempClient.printBooking(travelAgency);
    wait();

    cout << "Add three trains to a booking:" << endl;

            tempClient.addTrain(travelAgency, 1,"RGB-5288", "19.08.2020", "CDG-ANGERS", "13:00-15:30", 50);
            tempClient.addTrain(travelAgency, 1,"HST-5288", "20.08.2020", "CDG-ANGERS", "13:00-15:30", 50);
            tempClient.addTrain(travelAgency, 1,"HST-5467", "23.08.2020", "ANGERS-CDG", "15:00-17:20", 45);
            tempClient.printBooking(travelAgency);
        waitNoClear();

        cout << "Modify the train (id = 0):" << endl;

            tempClient.updateTrain(travelAgency, 1, 0, "RGB-5288", "20.08.2020", "CDG-ANGERS", "13:00-15:30", 50);
            tempClient.printBooking(travelAgency);
        waitNoClear();

        cout << "Deletion of a train:" << endl;

            tempClient.deleteTrain(travelAgency, 1, 0);
            tempClient.printBooking(travelAgency);
    wait();

    cout << "Client applied the booking to Paris and show applied booking:" << endl;

            tempClient.applied(travelAgency, 1);
            tempClient.printAppliedBooking(travelAgency);
    wait();
    
    cout << "Client pay the Paris booking:" << endl;

            tempClient.pay(travelAgency, 1);
            tempClient.printAppliedBooking(travelAgency);
        waitNoClear();

            tempClient.pay(travelAgency, 1);
            tempClient.printAppliedBooking(travelAgency);
        waitNoClear();

            tempClient.unapplied(travelAgency, 1);
            tempClient.pay(travelAgency, 1);
            tempClient.printBooking(travelAgency);
            tempClient.printPayment(travelAgency);

    wait();

            tempClient.applied(travelAgency, 1);
            tempClient.pay(travelAgency, 1);
            tempClient.printAppliedBooking(travelAgency);
    wait();

            tempClient.unapplied(travelAgency, 1);
            tempClient.deletePlane(travelAgency, 1, 0);
            tempClient.applied(travelAgency, 1);
            tempClient.pay(travelAgency, 1);
    wait();

            tempClient.unapplied(travelAgency, 1);
            tempClient.updatePlane(travelAgency, 1, 0,"AF1146", "23.08.2020", "CDG-WAW", "18:30-21:20", 150);
            tempClient.applied(travelAgency, 1);
            tempClient.pay(travelAgency, 1);
            tempClient.printPayment(travelAgency);
    wait();



    cout << "Deletion of the travel agency:" << endl;
        travelAgency->bankrupt();

    wait();


    system("clear");
    return 0;
}
