#include "TravelAgency.h"
#include "Employee.h"
#include "Client.h"
#include "SuperUser.h"

#include <iostream>

// Agency functions 
TravelAgency::TravelAgency(string _name, string _address)
{
    name = _name;
	address = _address;
	employee_number = 0;
	client_number = 0;
    superUser_number = 0;
    travel_number = 0;
    bankrupt_flag = 0;
    addSuperUser("superuser@etravel.com", "admin", "password", "name", "surname", "Address");
}

        void TravelAgency::showAgencyDetails()
        {
            cout << "Name: ------------------- " << name << endl;
            cout << "Address: ---------------- " << address << endl;    
            cout << "Number of employee: ----- " << employee_number << endl;
            cout << "Number of client: ------- " << client_number << endl;
            cout << "Number of SuperUser: ---- " << superUser_number << endl;
        }

        void TravelAgency::bankrupt()
        {
            bankrupt_flag = 1;
            int client_number_to_remove = client_number;
            int employee_number_to_remove = employee_number;

            for (int i = 0; i < client_number_to_remove; i++)
            {
                removeClient(client_number - 1);
            }
    
            for (int i = 0; i < employee_number_to_remove; i++)
            {
                removeEmployee(employee_number - 1);
            }

            this->~TravelAgency();
        }

TravelAgency::~TravelAgency()
{
    cout << "Travel agency succesfully deleted." << endl;
}

// SuperUser functions
void TravelAgency::addSuperUser(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    SuperUser superUser;
    superUser.createSuperUser(_email, _username, _password, _name, _surname, _address);
    superUser.setSUID(superUser_number);
    tab_superUser.push_back(superUser);
    superUser_number++;
}

        void TravelAgency::printSuperUser()
        {
            tab_superUser[0].printSuperUser();
        }

        void TravelAgency::superUserLogin(string email, string password)
        {
            bool find_someone = false;
            if (tab_superUser[0].getEmail() == email && tab_superUser[0].getPassword() == password)
            {
                tab_superUser[0].login();
                find_someone = true;        
            }        
        
            if (!find_someone)
            {
                cout << "Wrong combinaison email/password." << endl;
            }
        }

        SuperUser TravelAgency::returnSuperUser()
        {
            return tab_superUser[0];
        }
        
        void TravelAgency::setSuperUser(SuperUser tempSuperUser)
        {
            tab_superUser[0] = tempSuperUser;
        }
//

// Employee functions

void TravelAgency::addEmployee(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    Employee employee;
    employee.createEmployee(_email, _username, _password, _name, _surname, _address);
    employee.setID(employee_number);
    tab_employee.push_back(employee);
    employee_number++;
}

        void TravelAgency::printEmployee()
        {
            for (int i = 0; i < employee_number; i++)
            {
                tab_employee[i].printEmployee();
            }
        }

        void TravelAgency::employeeLogin(string email, string password)
        {
            bool find_someone = false;
            for (int i = 0; i < employee_number; i++)
            {
                if (tab_employee[i].getEmail() == email && tab_employee[i].getPassword() == password)
                {
                    tab_employee[i].login();
                    find_someone = true;        
                }        
            }
            if (!find_someone)
            {
                cout << "Wrong combinaison email/password." << endl;
            }
        }

        Employee TravelAgency::returnEmployee()
        {
            int a;
            for (int i = 0; i < employee_number; i++)
            {
                if (tab_employee[i].isLogin())
                {
                    a = i;
                }
            } 
            return tab_employee[a];
        }

        void TravelAgency::setEmployee(Employee tempEmployee)
        {
            for (int i = 0; i < employee_number; i++)
            {
                if (tab_employee[i].getID() == tempEmployee.getID() && tab_employee[i].isLogin())
                {
                    tab_employee[i] = tempEmployee;
                } 
            }
        }

        // Travel functions
        void TravelAgency::pbTravel(Travel travel)
        {
            tab_travel.push_back(travel);
            travel_number++;
        }

        void TravelAgency::printTravel()
        {
            for (int i = 0; i < travel_number; i++)
            {
                tab_travel[i].print();
            }
            
        }

        void TravelAgency::updateTravel(int _travel_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].updateTravel(_destination, _place_available, _start_date, _end_date, _duration);
                }    
            }
        }

        void TravelAgency::deleteTravel(int _travel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel.erase(tab_travel.begin() + i);
                }
            }
            travel_number--;

            for (int i = 0; i < travel_number; i++)
            {
                tab_travel[i].setID(i);
            }
            
        }

        // Hotel functions
        void TravelAgency::addHotel(int _travel_id, int _night_number, string _address, string _name, double _price)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].addHotel(_night_number, _address, _name, _price);
                }
            }
        }

                void TravelAgency::updateHotel(int _travel_id, int _hotel_id, int _night_number, string _address, string _name, double _price)
                {
                    for (int i = 0; i < travel_number; i++)
                    {
                        if (tab_travel[i].getID() == _travel_id)
                        {
                            tab_travel[i].updateHotel(_hotel_id, _night_number, _address, _name, _price);
                        }
                    }
                }

        void TravelAgency::deleteHotel(int _travel_id, int _hotel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].deleteHotel(_hotel_id);
                }
            }  
        }

void TravelAgency::removeEmployee(int id)
{
    for (int i = 0; i < employee_number; i++)
    {
        if(tab_employee[i].getID() == id)
        {
            tab_employee.erase(tab_employee.begin() + i);
        }
    }
    employee_number--;    
    
    for (int i = id; i < employee_number; i++)
    {
        tab_employee[i].setID(i);
    }
}


// Client functions
void TravelAgency::addClient(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    Client client;
    client.createClient(_email, _username, _password, _name, _surname, _address);
    client.setID(client_number);
    tab_client.push_back(client);
    client_number++;
}

        void TravelAgency::printClient()
        {   
            for (int i = 0; i < client_number; i++)
            {
            tab_client[i].printClient();
            }
        }

        void TravelAgency::clientLogin(string email, string password)
        {
            bool find_someone = false;
            for (int i = 0; i < client_number; i++)
            {
                if (tab_client[i].getEmail() == email && tab_client[i].getPassword() == password)
                {
                    tab_client[i].login();
                    find_someone = true;
                }
            }
            if (!find_someone)
            {
                cout << "Wrong combinaison email/password." << endl;
            }
        }

        Client TravelAgency::returnClient()
        {
            int a;
            for (int i = 0; i < client_number; i++)
            {
                if (tab_client[i].isLogin())
                {
                    a = i;
                }
            }
            return tab_client[a];
        }

        void TravelAgency::setClient(Client tempClient)
        {
            for (int i = 0; i < client_number; i++)
            {
                if (tab_client[i].getID() == tempClient.getID())
                {
                    tab_client[i] = tempClient;
                }
            }
        }

        // Booking functions

        bool TravelAgency::checkAvaibilityToBook(int _travel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    if (tab_travel[i].getPlaceAvailable() != 0)
                    {
                        return true;
                    }
                }       
            } 
            return false;
        }

        Travel TravelAgency::returnBooking(int _travel_id)
        {
            int a = 0;
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    a = i;
                }
            } 
            return tab_travel[a];
        }

        void TravelAgency::addedBook(int _travel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].addedBook();
                }
            } 
        }

        void TravelAgency::deletedBook(int _travel_id)
        {
            for (int i = 0; i < travel_number; i++)
            {
                if (tab_travel[i].getID() == _travel_id)
                {
                    tab_travel[i].deletedBook();
                }
            }
        }
        

void TravelAgency::removeClient(int id)
{

    for (int i = 0; i < client_number; i++)
    {
        if(tab_client[i].getID() == id)
        {
            tab_client.erase(tab_client.begin() + i);
        }
    } 
    client_number--;

    for (int i = id; i < client_number; i++)
    {
        tab_client[i].setID(i);
    }
}

// Getter

    int TravelAgency::getTravelNbr()
    {
        return travel_number;
    }

//

// Setter

    void TravelAgency::setTravelNbr(int _travel_number)
    {
        travel_number = _travel_number;
    }

//








