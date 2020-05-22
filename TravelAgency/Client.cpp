#include "Client.h"

#include "TravelAgency.h"

#include <iostream>

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}

// Call by TravelAgency.cpp
void Client::createClient(string _email, string _username, string _password, string _name, string _surname, string _address)
{
    email = _email;
    username = _username;
    password = _password;
    name = _name;
    surname = _surname;
    address = _address; 
    is_login = false;
    booking_number = 0;
}

void Client::printClient()
{
    cout << client_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// Client functions (login need)

        void Client::deleteAccount(TravelAgency* travelAgency)
        {
            travelAgency->removeClient(client_id);
        }

        void Client::showTravel(TravelAgency* travelAgency)
        {
            travelAgency->printTravel();
        }

        // Booking functions
        void Client::addBooking(TravelAgency* travelAgency, int _travel_id)
        {
            Booking booking(_travel_id);
            travelAgency->addedBook(_travel_id);
            booking.setTitle(travelAgency->returnBooking(_travel_id).getTitle());
            booking.setTotalDue(travelAgency->returnBooking(_travel_id).getPrice());
            booking.setID(booking_number);
            tab_booking.push_back(booking);
            booking_number++;
        }
        
            void Client::updateBooking(){}

            // Plane functions
            void Client::addPlane(){}

                void Client::updatePlane(){}

            void Client::deletePlane(){}

            // Train functions
            void Client::addTrain(){}

                void Client::updateTrain(){}

            void Client::deleteTrain(){}

        void Client::deleteBooking(){}
//

// Getter

    int Client::getID()
    {
        return client_id;
    }

    string Client::getEmail()
    {
        return email;
    }

    string Client::getPassword()
    {
        return password;
    }

//

// Setter

    void Client::setID(int id)
    {
        client_id = id;
    }

//