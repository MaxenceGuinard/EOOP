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
            if (travelAgency->checkAvaibilityToBook(_travel_id))
            {
                Booking booking(_travel_id);
                travelAgency->addedBook(_travel_id);
                booking.setTitle(travelAgency->returnBooking(_travel_id).getTitle());
                booking.setTravelPrice(travelAgency->returnBooking(_travel_id).getPrice());
                booking.setID(booking_number);
                tab_booking.push_back(booking);
                booking_number++;
            }
            else
            {
                cout << "No more places available for the travel to " << travelAgency->returnBooking(_travel_id).getTitle() << endl;
            }
        }

            void Client::printBooking()
            {   
                for (int i = 0; i < booking_number; i++)
                {
                    tab_booking[i].print();
                }
            }
            
            // Plane functions
            void Client::addPlane(int _bookind_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                for (int i = 0; i < booking_number; i++)
                {
                    if (tab_booking[i].getID() == _bookind_id)
                    {
                        tab_booking[i].addPlane(_flight_id, _date, _a_to_b, _ad_time, _price);
                    }
                }
            }

                void Client::updatePlane(int _bookind_id, int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getID() == _bookind_id)
                        {
                            tab_booking[i].updatePlane(_plane_id, _flight_id, _date, _a_to_b, _ad_time, _price);
                        }  
                    }
                }

            void Client::deletePlane(int _booking_id, int _plane_id)
            {
                for (int i = 0; i < booking_number; i++)
                {
                    if (tab_booking[i].getID() == _booking_id)
                    {
                        tab_booking[i].deletePlane(_plane_id);
                    }
                }
            }

            // Train functions
            void Client::addTrain(int _bookind_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                for (int i = 0; i < booking_number; i++)
                {
                    if (tab_booking[i].getID() == _bookind_id)
                    {
                        tab_booking[i].addTrain(_train_number_id, _date, _a_to_b, _ad_time, _price);
                    }
                }
            }

                void Client::updateTrain(int _bookind_id, int _train_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
                {
                    for (int i = 0; i < booking_number; i++)
                    {
                        if (tab_booking[i].getID() == _bookind_id)
                        {
                            tab_booking[i].updatePlane(_train_id, _train_number_id, _date, _a_to_b, _ad_time, _price);
                        }  
                    }
                }

            void Client::deleteTrain(int _booking_id, int _train_id)
            {
                for (int i = 0; i < booking_number; i++)
                {
                    if (tab_booking[i].getID() == _booking_id)
                    {
                        tab_booking[i].deleteTrain(_train_id);
                    }
                }
            }

        void Client::deleteBooking(int _booking_id)
        {
            for (int i = 0; i < booking_number; i++)
            {
                if (tab_booking[i].getID() == _booking_id)
                {
                    tab_booking.erase(tab_booking.begin() + i);
                }
            }
            booking_number--;

            for (int i = 0; i < booking_number; i++)
            {
                tab_booking[i].setID(i);
            }
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

//

// Setter

    void Client::setID(int id)
    {
        client_id = id;
    }

//