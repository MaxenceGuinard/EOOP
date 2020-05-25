#include "Client.h"

#include "TravelAgency.h"

#include <iostream>


// constructor not use to declare a Client in the main without a lot of characteristic
Client::Client()
{
    //ctor
}

// destructor 
Client::~Client()
{
    //dtor
}

// create client with all the characteristic
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
    payment_number = 0;
}

// print all the client informations
void Client::printClient()
{
    cout << client_id << "; " << email << "; " << username << "; " << name<< "; "  << surname << "; " << address <<  endl;
}

// Client functions (login need)

        // call the function removeClient in TravelAgency
        void Client::deleteAccount(TravelAgency* travelAgency)
        {
            travelAgency->removeClient(client_id);
        }

        //  call the function printTravel in TravelAgency
        void Client::showTravel(TravelAgency* travelAgency)
        {
            travelAgency->printTravel();
        }

        // Booking functions
        // call the function addBooking in TravelAgency
        void Client::addBooking(TravelAgency* travelAgency, int _travel_id)
        {           
            travelAgency->addBooking(client_id, _travel_id);
        }
            // call the function printBooking in TravelAgency
            void Client::printBooking(TravelAgency* travelAgency)
            {   
                travelAgency->printBooking(client_id); 
            }
            
            // call the function printAppliedBooking in TravelAgency
            void Client::printAppliedBooking(TravelAgency* travelAgency)
            {
                travelAgency->printAppliedBooking(client_id);
            }

            // call the function applied in TravelAgency
            void Client::applied(TravelAgency* travelAgency, int _booking_id)
            {
                travelAgency->applied(client_id, _booking_id);
            }

            // call the function unapplied in TravelAgency
            void Client::unapplied(TravelAgency* travelAgency, int _booking_id)
            {
                travelAgency->unapplied(client_id, _booking_id);
            }
            
            // Plane functions
            // call the function addPlane in TravelAgency
            void Client::addPlane(TravelAgency* travelAgency, int _bookind_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                travelAgency->addPlane(client_id, _bookind_id, _flight_id, _date, _a_to_b, _ad_time, _price);
            }
                // call the function updatePlane in TravelAgency
                void Client::updatePlane(TravelAgency* travelAgency, int _bookind_id, int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    travelAgency->updatePlane(client_id, _bookind_id, _plane_id, _flight_id, _date, _a_to_b, _ad_time, _price);
                }

            // call the function deletePlane in TravelAgency
            void Client::deletePlane(TravelAgency* travelAgency, int _booking_id, int _plane_id)
            {
                travelAgency->deletePlane(client_id, _booking_id, _plane_id);
            }

            // Train functions
            // call the function addTrain in TravelAgency
            void Client::addTrain(TravelAgency* travelAgency, int _bookind_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                travelAgency->addTrain(client_id, _bookind_id, _train_number_id, _date, _a_to_b, _ad_time, _price);
            }

                // call the function updateTrain in TravelAgency
                void Client::updateTrain(TravelAgency* travelAgency, int _bookind_id, int _train_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    travelAgency->updateTrain(client_id, _bookind_id, _train_id, _train_number_id, _date, _a_to_b, _ad_time, _price);
                }

            // call the function deleteTrain in TravelAgency
            void Client::deleteTrain(TravelAgency* travelAgency, int _booking_id, int _train_id)
            {
                travelAgency->deleteTrain(client_id, _booking_id, _train_id);
            }

            // Payment functions
            // call the function createPayment in TravelAgency if the booking is applied
            void Client::pay(TravelAgency* travelAgency, int _booking_id)
            {
                if (travelAgency->checkIfIsApplied(client_id, _booking_id))
                {
                    travelAgency->createPayment(client_id, _booking_id);
                }
                else
                {
                    cout << "Your booking is not applied.." << endl;
                }
            }

            // call the function printPayment in TravelAgency
            void Client::printPayment(TravelAgency* travelAgency)
            {
                travelAgency->printPayment(client_id);
            }

        // call the function deleteBooking in TravelAgency
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

    int Client::getPaymentNumber()
    {
        return payment_number;
    }

//

// Setter

    void Client::setID(int id)
    {
        client_id = id;
    }

    void Client::setBookingNumber(int _booking_number)
    {        
        booking_number += _booking_number;
    }

    void Client::setPaymentNumber(int _payment_number)
    {
        payment_number += _payment_number;
    }
//