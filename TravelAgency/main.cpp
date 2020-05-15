#include <iostream>

#include "TravelAgency.h"
#include "User.h"
#include "Employee.h"
#include "Client.h"

#include <unistd.h> //sleep
#include <stdio.h>

int menu_selection;
int interrupt_flag = 0;

int main()
{
    //TravelAgency* ptr_TravelAgency = new TravelAgency("eTravel", "New York City");

    TravelAgency travelAgency("eTravel", "New York City");

    travelAgency.addEmployee(0, "0@e.com", "0e", "password", "name0", "surname", "Address 0");
    travelAgency.addEmployee(1, "1@e.com", "1e", "password", "name1", "surname", "Address 1");
    travelAgency.addEmployee(2, "2@e.com", "2e", "password", "name2", "surname", "Address 2");
    travelAgency.addEmployee(3, "3@e.com", "3e", "password", "name3", "surname", "Address 3");

    while(interrupt_flag == 0)
    {
        system("clear");
        cout << "Welcome to our Website. Select your menu according to the choises.\n(Type 10 to launch Unit tests.)\n" << endl;
        cout << "1. Log in" << endl;
        cout << "2. Sign in" << endl;
        cout << "3. test update" << endl;
        cout << "4. test show" << endl;
        cout << "5. " << endl;
        cout << "6." << endl;
        cout << "7. " << endl;
        cout << "8. About us" << endl;
        cout << "9. Quit" << endl;
        cin >> menu_selection;

        switch(menu_selection)
        {
            case 0:     travelAgency.printEmployee();
                        sleep(3);
                        break;

            case 1:
                        break;

            case 2:
                        break;

            case 3:     //ptr_Employee->updateAccount();
                        Employee().updateAccount();
                        break;

            case 4:     //ptr_Employee->showAccount();
                        Employee().showAccount();
                        break;

            case 5:
                        break;

            case 6:
                        break;

            case 7:
                        break;

            case 8:     //ptr_TravelAgency->showAgencyDetails();
                        travelAgency.showAgencyDetails();
                        break;

            case 9:     system("clear");
                        cout << "Thank you for your visit.\nQuitting..." << endl;
                        sleep(1);
                        break;
            
            case 10:    cout << "Unit tests right here !!" << endl;
                        //need unit tests
                        break;

            default:    cout << "Incorrect selection." << endl;
                        break;
        }

        if(menu_selection == 9)
        {
            interrupt_flag = 1;
        }
    }
    system("clear");
    return 0;
}
