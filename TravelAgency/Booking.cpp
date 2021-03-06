#include "Booking.h"

#include <iostream>

// constructor
Booking::Booking(int _travel_id)
{
    travel_id = _travel_id;
    title = "";
    total_due = 0;
    is_payed = false;
    is_finished = false;
    plane_number = 0;
    train_number = 0;
    travel_price = 0;
    plane_price = 0;
    train_price = 0;
}

        // print all informations about the booking
        void Booking::print()
        {
            cout << travel_id << "; " << booking_id << "; Trip in " << title << "; " << total_due << "€; " << is_payed << endl;
            printPlane();
            printTrain();            
        }

        // Plane functions
        // add a plane in tab_plane 
        void Booking::addPlane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
        {
            if (!is_finished) // test if the booking gave been applied by the client
            {
                Plane* plane = new Plane(_flight_id, _date, _a_to_b, _ad_time, _price);
                plane->setID(plane_number);
                tab_plane.push_back(plane);
                plane_number++;
                setPlanePrice();
            }
            else
            {
                cout << "Booking to " << title << " cannot be modified because you applied.." << endl;
            }    
        }
            // print all the planes informations related to the booking
            void Booking::printPlane()
            {
                if (plane_number != 0)
                {
                    cout << "Plane:" << endl;
                    for (int i = 0; i < plane_number; i++)
                    {
                        tab_plane[i]->print();
                    }
                }
            }

            // call the function updatePlane of the Plane class by searching the plane to modify in tab_plane
            void Booking::updatePlane(int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                if (!is_finished)
                {
                    for (int i = 0; i < plane_number; i++)
                    {
                        if (tab_plane[i]->getID() == _plane_id)
                        {
                            tab_plane[i]->updatePlane(_flight_id, _date, _a_to_b, _ad_time, _price);
                        } 
                    }
                    setPlanePrice();
                }
                else
                {
                    cout << "Booking to " << title << " cannot be modified because you applied.." << endl;
                }
            }

        // delete one plane in the tab_plane
        void Booking::deletePlane(int _plane_id)
        {
            if (!is_finished)
            {
                for (int i = 0; i < plane_number; i++)
                {
                    if (tab_plane[i]->getID() == _plane_id)
                    {
                        tab_plane.erase(tab_plane.begin() + i);
                    }
                }
                plane_number--;

                for (int i = 0; i < plane_number; i++)
                {
                    tab_plane[i]->setID(i);
                }
                setPlanePrice();
                }
            else
            {
                cout << "Booking to " << title << " cannot be modified because you applied.." << endl;
            }
        }

        // Train functions
        // add a train in tab_train
        void Booking::addTrain(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
        {
            if (!is_finished)
            {
                Train* train = new Train(_train_number_id, _date, _a_to_b, _ad_time, _price);
                train->setID(train_number);
                tab_train.push_back(train);
                train_number++;
                setTrainPrice();
            }
            else
            {
                cout << "Booking to " << title << " cannot be modified because you applied.." << endl;
            }
        }

            // print all the trains informations related to the booking
            void Booking::printTrain()
            {
                if (train_number != 0)
                {
                    cout << "Train:" << endl;
                    for (int i = 0; i < train_number; i++)
                    {
                        tab_train[i]->print();
                    }
                }
            }

            // call the function updateTrain of the Train class by searching the train to modify in tab_train
            void Booking::updateTrain(int _train_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
            {
                if (!is_finished)
                {
                    for (int i = 0; i < train_number; i++)
                    {
                        if (tab_train[i]->getID() == _train_id)
                        {
                            tab_train[i]->updateTrain(_flight_id, _date, _a_to_b, _ad_time, _price);
                        } 
                    } 
                    setTrainPrice();
                    }
                else
                {
                    cout << "Booking to " << title << " cannot be modified because you applied.." << endl;
                }
            }

        // delete one train in the tab_train
        void Booking::deleteTrain(int _train_id)
        {
            for (int i = 0; i < train_number; i++)
            {
                if (tab_train[i]->getID() == _train_id)
                {
                    tab_train.erase(tab_train.begin() + i);
                }
            }
            train_number--;

            for (int i = 0; i < train_number; i++)
            {
                tab_train[i]->setID(i);
            }
            setTrainPrice();
        }

// destructor 
Booking::~Booking()
{
    
}

// Getter

    int Booking::getID()
    {
        return booking_id;
    }

    int Booking::getClientID()
    {
        return client_id;
    }

    int Booking::getTravelID()
    {
        return travel_id;
    }

    bool Booking::getIsFinished()
    {
        return is_finished;
    }

    string Booking::getTitle()
    {
        return title;
    }

    double Booking::getTotalDue()
    {
        return total_due;
    }

    bool Booking::getIsPayed()
    {
        return is_payed;    
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

    // compute the booking price
    void Booking::setTotalDue()
    {
        total_due = (travel_price + plane_price + train_price);
    }

    void Booking::setTravelPrice(double _price)
    {
        travel_price = _price;
        setTotalDue();
    }

    // compute the price of all the plane 
    void Booking::setPlanePrice()
    {
        plane_price = 0;
        for (int i = 0; i < plane_number; i++)
        {
            plane_price = plane_price + tab_plane[i]->getPrice();
        }
        
        setTotalDue();
    }


    //compute the price of all the train 
    void Booking::setTrainPrice()
    {
        train_price = 0;
        for (int i = 0; i < train_number; i++)
        {
            train_price = train_price + tab_train[i]->getPrice();
        }
        
        setTotalDue();
    }

    void Booking::setClientID(int _client_id)
    {
        client_id = _client_id;
    }

    void Booking::setIsFinished(bool _is_finished)
    {
        is_finished = _is_finished;
        is_payed = false;
        if (is_finished)
        {
            cout << "You applied your booking.." << endl;
        }
        else
        {
            cout << "You unapplied your booking.." << endl;
        }        
    }

    void Booking::setIsPayed(bool _is_payed)
    {
        is_payed = _is_payed;
    }

//