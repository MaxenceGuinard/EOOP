#include "Booking.h"

#include <iostream>

Booking::Booking(int _travel_id)
{
    travel_id = _travel_id;
    title = "";
    total_due = 0;
    is_payed = false;
    plane_number = 0;
    train_number = 0;
    travel_price = 0;
    plane_price = 0;
    train_price = 0;
}

        void Booking::print()
        {
            cout << travel_id << "; " << booking_id << "; Trip in " << title << "; " << total_due << "; " << is_payed << endl;
            printPlane();
            printTrain();            
        }

        // Plane functions
        void Booking::addPlane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
        {
            Plane plane(_flight_id, _date, _a_to_b, _ad_time, _price);
            plane.setID(plane_number);
            tab_plane.push_back(plane);
            plane_number++;
            setPlanePrice();
        }

            void Booking::printPlane()
            {
                if (plane_number != 0)
                {
                    cout << travel_id << "; " << "Plane:" << endl;
                    for (int i = 0; i < plane_number; i++)
                    {
                        tab_plane[i].print();
                    }
                }
            }

            void Booking::updatePlane(int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                for (int i = 0; i < plane_number; i++)
                {
                    if (tab_plane[i].getID() == _plane_id)
                    {
                        tab_plane[i].updatePlane(_flight_id, _date, _a_to_b, _ad_time, _price);
                    } 
                }
                setPlanePrice();
            }

        void Booking::deletePlane(int _plane_id)
        {
            for (int i = 0; i < plane_number; i++)
            {
                if (tab_plane[i].getID() == _plane_id)
                {
                    tab_plane.erase(tab_plane.begin() + i);
                }
            }
            plane_number--;

            for (int i = 0; i < plane_number; i++)
            {
                tab_plane[i].setID(i);
            }
            setPlanePrice();
        }

        // Train functions
        void Booking::addTrain(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
        {
            Train train(_train_number_id, _date, _a_to_b, _ad_time, _price);
            train.setID(train_number);
            tab_train.push_back(train);
            train_number++;
            setTrainPrice();
        }

            void Booking::printTrain()
            {
                if (train_number != 0)
                {
                    cout << travel_id << "; " << "Train:" << endl;
                    for (int i = 0; i < train_number; i++)
                    {
                        tab_train[i].print();
                    }
                }
            }

            void Booking::updateTrain(int _train_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                for (int i = 0; i < train_number; i++)
                {
                    if (tab_train[i].getID() == _train_id)
                    {
                        tab_train[i].updateTrain(_flight_id, _date, _a_to_b, _ad_time, _price);
                    } 
                } 
                setTrainPrice();
            }

        void Booking::deleteTrain(int _train_id)
        {
            for (int i = 0; i < train_number; i++)
            {
                if (tab_train[i].getID() == _train_id)
                {
                    tab_train.erase(tab_train.begin() + i);
                }
            }
            train_number--;

            for (int i = 0; i < train_number; i++)
            {
                tab_train[i].setID(i);
            }
            setTrainPrice();
        }

        


Booking::~Booking()
{
    
}

// Getter

    int Booking::getID()
    {
        return booking_id;
    }

// Setter

    void Booking::setID(int id)
    {
        booking_id = id;
    }

    void Booking::setTitle(string _title)
    {
        title = _title;
    }

    void Booking::setTotalDue()
    {
        total_due = (travel_price + plane_price + train_price);
    }

    void Booking::setTravelPrice(double _price)
    {
        travel_price = _price;
        setTotalDue();
    }

    void Booking::setPlanePrice()
    {
        plane_price = 0;
        for (int i = 0; i < plane_number; i++)
        {
            plane_price = plane_price + tab_plane[i].getPrice();
        }
        
        setTotalDue();
    }

    void Booking::setTrainPrice()
    {
        train_price = 0;
        for (int i = 0; i < train_number; i++)
        {
            train_price = train_price + tab_train[i].getPrice();
        }
        
        setTotalDue();
    }

//