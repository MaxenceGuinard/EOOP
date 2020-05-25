#include "Travel.h"

#include <iostream>

// constructor
Travel::Travel(int _creator_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration)
{
    creator_id = _creator_id;
    destination = _destination;
    place_available = _place_available;
    start_date = _start_date;
    end_date = _end_date;
    duration = _duration;
    hotel_number = 0;
    price = 0;
    is_published = false;
}

        // print all the travel 
        void Travel::print()
        {
            cout << travel_id << "; " << destination << "; " << start_date << " - " << end_date << "; " << duration << " d; " << price << "€; " << place_available << " p; " << creator_id << endl;
            printHotel();
        }
        
        // print the published travel (for client)
        void Travel::printForClient()
        {
            if (!is_published)
            {
                cout << travel_id << "; " << destination << "; " << start_date << " - " << end_date << "; " << duration << " d; " << price << "€; " << place_available << " p; " << creator_id << endl;
                printHotel();
            }       
        }
        
        // print a message
        void Travel::errorBecauseTravelIsPublished()
        {
            cout << "Travel to " << destination << " cannot be modified because it is published.." << endl;
        }

        // update the travel if the travel is published. Else the message above
        void Travel::updateTravel(string _destination, int _place_available, string _start_date, string _end_date, double _duration)
        {
            if (!is_published)
            {
                destination = _destination;
                place_available = _place_available;
                start_date = _start_date;
                end_date = _end_date;
                duration = _duration;
            }
            else
            {
                errorBecauseTravelIsPublished();
            }
            
        }

        // Hotel functions
        // create and add an hotel to tab_hotel if the travel is not published
        void Travel::addHotel(int _night_number, string _address, string _name, double _price)
        {
            if (!is_published)
            {
                Hotel* hotel = new Hotel(_night_number, _address, _name, _price);
                hotel->setID(hotel_number);
                tab_hotel.push_back(hotel);
                hotel_number++;
                setPrice();
            }
            else
            {
                errorBecauseTravelIsPublished();
            }
        }

                // display all the hotel of the travelAgency
                void Travel::printHotel()
                {
                    if (hotel_number != 0)
                    {
                        cout <<"Hotel:" << endl;
                        for (int i = 0; i < hotel_number; i++)
                        {
                            tab_hotel[i]->print();
                        }
                    }
                }

            // update hotel if the travel is not published
            void Travel::updateHotel(int _hotel_id, int _night_number, string _address, string _name, double _price)
            {
                if (!is_published)
                {
                    for (int i = 0; i < hotel_number; i++)
                    {
                        if (tab_hotel[i]->getID() == _hotel_id)
                        {
                            tab_hotel[i]->update(_night_number, _address, _name, _price);
                            setPrice();
                        }  
                    }
                }
                else
                {
                    errorBecauseTravelIsPublished();
                }    
            }

        // delete hotel if the travel is not published
        void Travel::deleteHotel(int _hotel_id)
        {
            if (!is_published)
            {
                for (int i = 0; i < hotel_number; i++)
                {
                    if (tab_hotel[i]->getID() == _hotel_id)
                    {
                        tab_hotel.erase(tab_hotel.begin() + i);
                    }
                }
                hotel_number--;

                for (int i = 0; i < hotel_number; i++)
                {
                    tab_hotel[i]->setID(i);
                }
                setPrice();
                }
            else
            {
                errorBecauseTravelIsPublished();
            }
        }

// destructor
Travel::~Travel()
{
    
}


// Getter

    int Travel::getID()
    {
        return travel_id;
    }

    string Travel::getTitle()
    {
        return destination;
    }

    double Travel::getPrice()
    {
        return price;
    }

    // reduced the number of place (because this function is called after a booking) and return place_available 
    int Travel::getPlaceAvailable()
    {
        if (place_available != 0)
        {
            place_available--;
        }
        
        return place_available;
    }

    bool Travel::getIsPublished()
    {
        return is_published;
    }

//

// Setter
    
    void Travel::setID(int id)
    {
        travel_id = id;
    }

    // compute the travel price according to the number of hotel and their prices
    void Travel::setPrice()
    {
        price = 0;
        for (int i = 0; i < hotel_number; i++)
        {
            price = price + (tab_hotel[i]->getNightNbr() * tab_hotel[i]->getPrice());
        }
    }

    void Travel::setPlaceAvailable()
    {
        place_available++;
    }

    // publish travel if there is at least one hotel in the travel
    void Travel::setIsPublishedTrue()
    {
        if (hotel_number != 0)
        {
            is_published = true;
            cout << "Travel to " << destination << " successfully published.." << endl;
        }
        else
        {
            cout << "Travel to " << destination << " cannot be published because no hotel has been registered.." << endl;
        }
    }

    void Travel::setIsPublishedFalse()
    {
        is_published = false;
    }

//

