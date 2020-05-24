#include "Employee.h"

#include "TravelAgency.h"

#include <iostream>

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

// Call by TravelAgency.cpp
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

void Employee::printEmployee()
{
    cout << employee_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// Employee functions (login need)

    // Client help functions
    void Employee::addClient(TravelAgency* travelAgency, string _email, string _username, string _password, string _name, string _surname, string _address)
    {
        travelAgency->addClient( _email, _username, _password, _name, _surname, _address);
    }

    void Employee::removeClient(TravelAgency* travelAgency, int _client_id)
    {
        travelAgency->removeClient(_client_id);        
    }

    // Travel functions
    void Employee::createTravel(TravelAgency* travelAgency, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
    {
        Travel travel(employee_id, _destination, _place_available, _start_date,_end_date,_duration);
        travel.setID(travelAgency->getTravelNbr());
        travelAgency->pbTravel(travel);
    }

            void Employee::publishTravel(TravelAgency* travelAgency, int _travel_id)
            {
                travelAgency->publishTravel(_travel_id);
            }

            void Employee::unPublishTravel(TravelAgency* travelAgency, int _travel_id)
            {
                travelAgency->unPublishTravel(_travel_id);
            }

            void Employee::updateTravel(TravelAgency* travelAgency, int _travel_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
            {
                travelAgency->updateTravel(_travel_id, _destination, _place_available, _start_date, _end_date, _duration);
            }

            // Hotel functions
            void Employee::addHotel(TravelAgency* travelAgency, int _travel_id, int _night_number, string _address, string _name, double _price)
            {
                travelAgency->addHotel(_travel_id, _night_number,  _address, _name, _price);
            }

                void Employee::updateHotel(TravelAgency* travelAgency, int _travel_id, int _hotel_id, int _night_number, string _address, string _name, double _price)
                {
                    travelAgency->updateHotel(_travel_id, _hotel_id, _night_number, _address, _name, _price);
                }

            void Employee::deleteHotel(TravelAgency* travelAgency, int _travel_id, int _hotel_id)
            {
                travelAgency->deleteHotel(_travel_id, _hotel_id);
            }

    void Employee::deleteTravel(TravelAgency* travelAgency, int _travel_id)
    {
        travelAgency->deleteTravel(_travel_id);
    }

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