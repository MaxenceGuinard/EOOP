#include "Employee.h"

#include "TravelAgency.h"

#include <iostream>

// constructor not use to declare a Employee in the main without a lot of characteristic
Employee::Employee()
{
    //ctor
}

// destructor
Employee::~Employee()
{
    //dtor
}

// create employee with all the characteristic
void Employee::createEmployee(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    email = _email;
    username = _username;
    password = _password;
    name = _name;
    surname = _surname;
    address = _address; 
    is_login = false;
}

// print all the informations of the employee
void Employee::printEmployee()
{
    cout << employee_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// Employee functions (login need)

    // Client help functions
    // call the function addClient in TravelAgency
    void Employee::addClient(TravelAgency* travelAgency, string _email, string _username, string _password, string _name, string _surname, string _address)
    {
        travelAgency->addClient( _email, _username, _password, _name, _surname, _address);
    }

    // call the function removeClient in TravelAgency
    void Employee::removeClient(TravelAgency* travelAgency, int _client_id)
    {
        travelAgency->removeClient(_client_id);        
    }

    // Travel functions
    // call the function pbTravel in TravelAgency to push_back the new travel in the tab_Travel
    void Employee::createTravel(TravelAgency* travelAgency, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
    {
        Travel* travel = new Travel(employee_id, _destination, _place_available, _start_date,_end_date,_duration);
        travel->setID(travelAgency->getTravelNbr());
        travelAgency->pbTravel(travel);
    }

            // call the function publishTravel in TravelAgency
            void Employee::publishTravel(TravelAgency* travelAgency, int _travel_id)
            {
                travelAgency->publishTravel(_travel_id);
            }

            // call the function unPublishTravel in TravelAgency
            void Employee::unPublishTravel(TravelAgency* travelAgency, int _travel_id)
            {
                travelAgency->unPublishTravel(_travel_id);
            }

            // call the function updateTravel in TravelAgency
            void Employee::updateTravel(TravelAgency* travelAgency, int _travel_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
            {
                travelAgency->updateTravel(_travel_id, _destination, _place_available, _start_date, _end_date, _duration);
            }

            // Hotel functions
            // call the function addHotel in TravelAgency
            void Employee::addHotel(TravelAgency* travelAgency, int _travel_id, int _night_number, string _address, string _name, double _price)
            {
                travelAgency->addHotel(_travel_id, _night_number,  _address, _name, _price);
            }

                // call the function updateHotel in TravelAgency
                void Employee::updateHotel(TravelAgency* travelAgency, int _travel_id, int _hotel_id, int _night_number, string _address, string _name, double _price)
                {
                    travelAgency->updateHotel(_travel_id, _hotel_id, _night_number, _address, _name, _price);
                }

            // call the function deleteHotel in TravelAgency
            void Employee::deleteHotel(TravelAgency* travelAgency, int _travel_id, int _hotel_id)
            {
                travelAgency->deleteHotel(_travel_id, _hotel_id);
            }

    // call the function deleteTravel in TravelAgency
    void Employee::deleteTravel(TravelAgency* travelAgency, int _travel_id)
    {
        travelAgency->deleteTravel(_travel_id);
    }

    // call the function removeEmployee in TravelAgency
    void Employee::deleteAccount(TravelAgency* travelAgency)
    {
        travelAgency->removeEmployee(employee_id);
        cout << "test" << endl;
    }

//

// Getter
    int Employee::getID()
    {
        return employee_id;
    }

    string Employee::getEmail()
    {
        return email;
    }

    string Employee::getPassword()
    {
        return password;
    }
//

// Setter
    void Employee::setID(int id)
    {
        employee_id = id;
    }
//