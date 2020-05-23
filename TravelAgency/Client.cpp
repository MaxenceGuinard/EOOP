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
            travelAgency->addBooking(client_id, _travel_id);
        }

            void Client::printBooking(TravelAgency* travelAgency)
            {   
                travelAgency->printBooking(client_id); 
            }
            
            // Plane functions
            void Client::addPlane(TravelAgency* travelAgency, int _bookind_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                travelAgency->addPlane(client_id, _bookind_id, _flight_id, _date, _a_to_b, _ad_time, _price);
            }

                void Client::updatePlane(TravelAgency* travelAgency, int _bookind_id, int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    travelAgency->updatePlane(client_id, _bookind_id, _plane_id, _flight_id, _date, _a_to_b, _ad_time, _price);
                }

            void Client::deletePlane(TravelAgency* travelAgency, int _booking_id, int _plane_id)
            {
                travelAgency->deletePlane(client_id, _booking_id, _plane_id);
            }

            // Train functions
            void Client::addTrain(TravelAgency* travelAgency, int _bookind_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                travelAgency->addTrain(client_id, _bookind_id, _train_number_id, _date, _a_to_b, _ad_time, _price);
            }

                void Client::updateTrain(TravelAgency* travelAgency, int _bookind_id, int _train_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    travelAgency->updateTrain(client_id, _bookind_id, _train_id, _train_number_id, _date, _a_to_b, _ad_time, _price);
                }

            void Client::deleteTrain(TravelAgency* travelAgency, int _booking_id, int _train_id)
            {
                travelAgency->deleteTrain(client_id, _booking_id, _train_id);
            }

        void Client::deleteBooking(TravelAgency* travelAgency, int _booking_id)
        {
            travelAgency->deleteBooking(client_id, _booking_id);
        }
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

    int Client::getBookingNumber()
    {
        return booking_number;
    }

//

// Setter

    void Client::setID(int id)
    {
        client_id = id;
    }

    void Client::setBookingNumberU()
    {
        booking_number++;
    }

    void Client::setBookingNumberL()
    {
        booking_number--;
    }
//