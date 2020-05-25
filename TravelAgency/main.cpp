#include <iostream>

#include "TravelAgency.h"
#include "User.h"
#include "Employee.h"
#include "Client.h"
#include "SuperUser.h"

#include <unistd.h>
#include <stdio.h>

int count = 1;

// function to wait for "Enter" entry + display the "actual page" during units tests
void wait()
{
    cin.get();
    system("clear");
    cout << count << ") ";
    count++;
    }

// function to wait without clearing the console 
void waitNoClear()
{
    cin.get();
}
    // For the different login we use tempUser to access the function easily
    Employee tempEmployee;
    Client tempClient;
    SuperUser tempSuperUser;   

int main()
{
    system("clear");cout << count << ") ";count++;
    
    //#1)    
    cout << "In this little introduction I will quickly explain you how does the program works.\n" << endl;
    cout << "This program is made to emulate one travel agency website." << endl;
    cout << "On this program users can connect themselves." << endl;
    cout << "The superUser can add/remove employee account and do the employee actions." << endl;
    cout << "Employees can add/remove client (case where a client wants to create account but have some problem), create/update/publish/unpublished/delete travel announce, add/update/delete hotel in travel announce (travel cannot be published without at least one hotel)." << endl;
    cout << "Client can create/update/applied/unapplied/delete/pay a booking and add/update/delete a plane/train (a client can pay if and only if the booking is applied).\n" << endl;
    cout << "The TravelAgency class is the main one. In the main we will create an instance of TravelAgency. This instance contains some vectors all names tab_(employee/client/superUser/travel/booking/payment)." << endl;
    cout << "tab_superUser is specific because there is only one superUser." << endl;
    cout << "For all the other tab, ids are handled by the program. When a deletion occurs,  the program put the id equal to the line identification (example: tab_example[i].getID() will return i)." << endl;
    cout << "This is true for all the tab except for tab_booking where ids are handled according to the client. It means that for each client the booking_id of their first booking will be 0. When a booking is deleted, re-attribution of ids are done according to what was previously written.\n" << endl;
    cout << "In each instance of Booking, there is a tab_(plane/train) and in each instance of Travel there is a tab_hotel which are working like the other vectors (about ids).\n" << endl;
    cout << "So, as you can understand, my UML diagram which was  in the Preliminary Project have been modified a little bit. Classes Train and Plane are no longer link to Travel but to Booking.\n" << endl;
    cout << "Concerning the login/logout functions: I create one tempUser of each type in the main (superUser, employee and client)." << endl;
    cout << "Then when one user is login, I copy the user type in the corresponding type tempUser. And when the login user logout, the tempUser is copying to the corresponding user.\n" << endl;
    
    cout << "UNITS TESTS\nPress Enter to continue (Valid during the whole operation of the program)\n" << endl;
    wait();
    
    //#2)
    cout << "Travel agency creation plus the default SuperUser:" << endl;
        
        TravelAgency* travelAgency = new TravelAgency("eTravel", "New York City");
        travelAgency->showAgencyDetails();
        travelAgency->printSuperUser();
    
    wait();

// Login/Logout AddUser/UpdateUser/RemoveUser _________________________________________________________________________________________________________________________________________________
    
    //#3)
    cout << "Try to connect to a wrong super user account:" << endl;

        travelAgency->superUserLogin("wrong", "wrong");
    
    wait();

    //#4)
    cout << "Login to the created SuperUser (email = superuser@etravel.com; password = password):" << endl;
        
        travelAgency->superUserLogin("superuser@etravel.com", "password");
        tempSuperUser = travelAgency->returnSuperUser();        
    
    wait();

    //#5)
    cout << "Creation of four employees:" << endl;
    
        tempSuperUser.addEmployee(travelAgency, "0@etravel.com", "0u", "password", "name0", "surname", "Address 0");
        tempSuperUser.addEmployee(travelAgency, "1@etravel.com", "1u", "password", "name1", "surname", "Address 1");
        tempSuperUser.addEmployee(travelAgency, "2@etravel.com", "2u", "password", "name2", "surname", "Address 2");
        tempSuperUser.addEmployee(travelAgency, "3@etravel.com", "3u", "password", "name3", "surname", "Address 3");
        travelAgency->printEmployee();
    
    waitNoClear();

    cout << "Deletion of an employee:" << endl;

        tempSuperUser.removeEmployee(travelAgency, 0);
        travelAgency->printEmployee();
    
    wait();

    //#6)
    cout << "SuperUser logout:" << endl;
            
        travelAgency->setSuperUser(tempSuperUser);
        tempSuperUser.logout();
    
    wait();

    //#7)
    cout << "Try to connect to a wrong employee account:" << endl;

        travelAgency->employeeLogin("wrong", "wrong");
    
    wait();

    //#8)
    cout << "Login to an employee (email = 1@etravel.com; password = password):" << endl;
        
        travelAgency->employeeLogin("1@etravel.com", "password");
        tempEmployee = travelAgency->returnEmployee();

    wait();

    //#9)
    cout << "Creation of four clients:" << endl;
    
        tempEmployee.addClient(travelAgency, "0@gmail.com", "0u", "password", "name0", "surname", "Address 0");
        tempEmployee.addClient(travelAgency, "1@gmail.com", "1u", "password", "name1", "surname", "Address 1");
        tempEmployee.addClient(travelAgency, "2@gmail.com", "2u", "password", "name2", "surname", "Address 2");
        tempEmployee.addClient(travelAgency, "3@gmail.com", "3u", "password", "name3", "surname", "Address 3");
        travelAgency->printClient();
    
    waitNoClear();

    cout << "Deletion of a client:" << endl;

        tempEmployee.removeClient(travelAgency, 0);
        travelAgency->printClient();
    
    wait();

    //#10)
    cout << "Clients can create their own account:" << endl;

        cout << "Before:" << endl;
        travelAgency->printClient();
        travelAgency->addClient("4@gmail.com", "4u", "password", "name4", "surname", "Address 4");
        cout << "After:" << endl;
        travelAgency->printClient();

    wait();

    //#11)
    cout << "Modification of the connected employee:" << endl;
        
        cout << "Before:" << endl;
        tempEmployee.printEmployee();
        tempEmployee.updateAccount("1@etravel.com", "1u", "password", "Felix", "surname", "Address 1");
        cout << "After:" <<endl;
        tempEmployee.printEmployee();

    wait();

    //#12)
    cout << "Employee logout:" << endl;
        travelAgency->setEmployee(tempEmployee);
        tempEmployee.logout();
    wait();

    //#13)
    cout << "Try to connect to a wrong client account:" << endl;

        travelAgency->clientLogin("wrong", "wrong");
    
    wait();

    //#14)
    cout << "Login to a client (email = 4@gmail.com; password = password):" << endl;
            
        travelAgency->clientLogin("4@gmail.com", "password");
        tempClient = travelAgency->returnClient();
    
    wait();

    //#15)
    cout << "Modification of the connected client:" << endl;

        cout << "Before:" << endl;
        tempClient.printClient();
        tempClient.updateAccount("4@gmail.com", "4u", "password", "Felix", "surname", "Address 4");
        cout << "After:" << endl;
        tempClient.printClient();
    
    wait();

    //#16)
    cout << "Client logout and then login again:" << endl;

        travelAgency->setClient(tempClient);
        tempClient.logout();

        travelAgency->clientLogin("4@gmail.com", "password");
        tempClient = travelAgency->returnClient();

    wait();

    //#17)
    cout << "Deletion of the client account by the client:" << endl;

        cout << "Before:" << endl;
        travelAgency->printClient();
        tempClient.deleteAccount(travelAgency);
        cout << "After:" << endl;
        travelAgency->printClient();

    wait();

//________________________________________________________________________________________________________________________________________________________________________________________

// create/update/delete travel/hotel______________________________________________________________________________________________________________________________________________________

    //#18)
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

    //#19)
    cout << "Try to publish a travel without any hotel:" << endl;

            tempEmployee.publishTravel(travelAgency, 2);
    wait();
    
    //#20)
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

    //#21)
    cout << "Publish the travel to Paris:" << endl;

            tempEmployee.publishTravel(travelAgency, 2);
    wait();

    //#22)
    cout << "Add one hotel in each travel to publish them and then employee logout:" << endl;

        tempEmployee.addHotel(travelAgency, 0, 6, "Seoul", "Hotel SEO", 70);
        tempEmployee.addHotel(travelAgency, 1, 6, "Tokyo", "Hotel TOK", 110);
        tempEmployee.addHotel(travelAgency, 3, 4, "Delhi", "Hotel DEL", 55);
        tempEmployee.publishTravel(travelAgency, 0);
        tempEmployee.publishTravel(travelAgency, 1);
        tempEmployee.publishTravel(travelAgency, 3);
        travelAgency->printTravel();

        cout << "Seoul_price=70x6=420" << endl;
        cout << "Tokyo_price=110x6=660" << endl;
        cout << "Paris_price=120+72+48=240" << endl;
        cout << "Delhi_price=55x4=220" << endl;

        travelAgency->setEmployee(tempEmployee);
        tempEmployee.logout();

    wait();

//_____________________________________________________________________________________________________________________________________________________________________________________

// create/update/delete booking add/update/delelte plane/train_________________________________________________________________________________________________________________________

    //#23)
    cout << "Login to a client to book four travel (with one not available):\n(first number is the travel_id; last number is the Boolean variable 'is_payed')\n" << endl;
            
        travelAgency->clientLogin("3@gmail.com", "password");
        tempClient = travelAgency->returnClient();
            
        tempClient.addBooking(travelAgency, 0);
        tempClient.addBooking(travelAgency, 1);
        tempClient.addBooking(travelAgency, 2);
        tempClient.addBooking(travelAgency, 3);
        tempClient.printBooking(travelAgency);

        cout << "\nAs you can see when there is not more place for a travel you can't book it." << endl;

    waitNoClear();

    cout << "Deletion of a booking:" << endl;

        tempClient.deleteBooking(travelAgency, 0);
        tempClient.printBooking(travelAgency);
    
    wait();

    //#24)
    cout << "Add three planes to a booking:" << endl;

        tempClient.addPlane(travelAgency, 1,"AS1146", "19.08.2020", "WAW-CDG", "9:10-12:00", 140);
        tempClient.addPlane(travelAgency, 1,"AF1146", "19.08.2020", "WAW-CDG", "9:10-12:00", 150);
        tempClient.addPlane(travelAgency, 1,"AF1146", "23.08.2020", "CDG-WAW", "18:30-21:20", 130);
        tempClient.printBooking(travelAgency);

        cout << "Paris_price=240+140+150+130=660" << endl;

    waitNoClear();

    cout << "Modify the plane (id = 0):" << endl;

        tempClient.updatePlane(travelAgency, 1, 0, "AS1146", "20.08.2020", "WAW-CDG", "9:10-12:00", 150);
        tempClient.printBooking(travelAgency);

        cout << "Paris_price=240+150+150+130=670" << endl;

    waitNoClear();

    cout << "Deletion of a plane:" << endl;

        tempClient.deletePlane(travelAgency, 1, 0);
        tempClient.printBooking(travelAgency);

        cout << "Paris_price=670-150=520" << endl;

    wait();

    //#25)
    cout << "Add three trains to a booking:" << endl;

        tempClient.addTrain(travelAgency, 1,"RGB-5288", "19.08.2020", "CDG-ANGERS", "13:00-15:30", 50);
        tempClient.addTrain(travelAgency, 1,"HST-5288", "20.08.2020", "CDG-ANGERS", "13:00-15:30", 50);
        tempClient.addTrain(travelAgency, 1,"HST-5467", "23.08.2020", "ANGERS-CDG", "15:00-17:20", 45);
        tempClient.printBooking(travelAgency);

        cout << "Paris_price=520+50+50+45=665" << endl;

    waitNoClear();

    cout << "Modify the train (id = 0):" << endl;

        tempClient.updateTrain(travelAgency, 1, 0, "RGB-5288", "20.08.2020", "CDG-ANGERS", "13:00-15:30", 60);
        tempClient.printBooking(travelAgency);

        cout << "Paris_price=520+60+50+45=675" << endl;

    waitNoClear();

    cout << "Deletion of a train:" << endl;

        tempClient.deleteTrain(travelAgency, 1, 0);
        tempClient.printBooking(travelAgency);
    
        cout << "Paris_price=675-60=615" << endl;

    wait();

//_______________________________________________________________________________________________________________________________________________________________________________________________

//applied/unapplied booking______________________________________________________________________________________________________________________________________________________________________

    //#26)
    cout << "Client try to pay the Paris booking which is not applied" << endl;

        tempClient.pay(travelAgency, 1);

    wait();

    //#27)
    cout << "Client applied the booking to Paris and show applied booking:" << endl;

        tempClient.applied(travelAgency, 1);
        tempClient.printAppliedBooking(travelAgency);
        
        cout << "\nThe last '0' is because the booking is not paid." << endl; 

    wait();

    //#28)
    cout << "Client try to modify the applied booking" << endl;

        tempClient.updatePlane(travelAgency, 1, 0, "", "", "", "", 0);
        tempClient.updateTrain(travelAgency, 1, 0, "", "", "", "", 0);
        
    wait();

    //#29)
    cout << "Client pay the Paris booking:" << endl;

        tempClient.pay(travelAgency, 1);
        tempClient.printAppliedBooking(travelAgency);
        tempClient.printPayment(travelAgency);

        cout <<  "\nNow we can see can that the booking is paid, last value is now '1'." << endl;
    
    waitNoClear();

    cout << "Client try to pay a paid booking:" << endl;

        tempClient.pay(travelAgency, 1);
        tempClient.printAppliedBooking(travelAgency);
    
    waitNoClear();

    cout << "Client unapplied the Paris booking:" << endl;

        tempClient.unapplied(travelAgency, 1);
        tempClient.printBooking(travelAgency);

        cout << "We can see that the booking is no longer paid with the value '0'." << endl;

    wait();

    //#30)
    cout << "Client reapplied the travel to Paris and try to pay it:" << endl;

        tempClient.applied(travelAgency, 1);
        tempClient.pay(travelAgency, 1);
        tempClient.printAppliedBooking(travelAgency);
        tempClient.printPayment(travelAgency);
    
    wait();

    //#31)
    cout << "Client unapplied and reapplied again but he deleted a plane (price = 150) and try to pay it:" << endl;

        tempClient.unapplied(travelAgency, 1);
        tempClient.deletePlane(travelAgency, 1, 0);
        tempClient.applied(travelAgency, 1);
        tempClient.pay(travelAgency, 1);
        tempClient.printPayment(travelAgency);
    
    wait();

    //#32)
    cout << "Client unapplied and reapplied again but he modified a plane (price: 130 to 150) and try to pay it:" << endl; 

        tempClient.unapplied(travelAgency, 1);
        tempClient.updatePlane(travelAgency, 1, 0,"AF1146", "23.08.2020", "CDG-WAW", "18:30-21:20", 150);
        tempClient.applied(travelAgency, 1);
        tempClient.pay(travelAgency, 1);
        tempClient.printPayment(travelAgency);
        
    wait();

    //#33)
    cout << "Client delete the booking for the Paris trip:" << endl;

        tempClient.deleteBooking(travelAgency, 1);
        tempClient.printPayment(travelAgency);

    wait();

    //#34)
    cout << "Client logout:" << endl;

        travelAgency->setClient(tempClient);
        tempClient.logout();

    wait();

    //#35)
    cout << "Deletion of the travel agency:" << endl;
        travelAgency->bankrupt();

    wait();


    system("clear");
    return 0;
}
