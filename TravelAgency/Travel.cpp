#include "Travel.h"

#include <iostream>

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

        void Travel::print()
        {
            cout << travel_id << "; " << destination << "; " << start_date << " - " << end_date << "; " << duration << " d; " << price << "€; " << place_available << " p; " << creator_id << endl;
            printHotel();
        }
        
        void Travel::printForClient()
        {
            if (!is_published)
            {
                cout << travel_id << "; " << destination << "; " << start_date << " - " << end_date << "; " << duration << " d; " << price << "€; " << place_available << " p; " << creator_id << endl;
                printHotel();
            }
            else
            {
                errorBecauseTravelIsPublished();
            }        
        }

        void Travel::errorBecauseTravelIsPublished()
        {
            cout << "Travel to " << destination << " cannot be modified because it is published.." << endl;
        }

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
        void Travel::addHotel(int _night_number, string _address, string _name, double _price)
        {
            if (!is_published)
            {
                Hotel hotel(_night_number, _address, _name, _price);
                hotel.setID(hotel_number);
                tab_hotel.push_back(hotel);
                hotel_number++;
                setPrice();
            }
            else
            {
                errorBecauseTravelIsPublished();
            }
        }

                void Travel::printHotel()
                {
                    if (hotel_number != 0)
                    {
                        cout <<"Hotel:" << endl;
                        for (int i = 0; i < hotel_number; i++)
                        {
                            tab_hotel[i].print();
                        }
                    }
                }

            void Travel::updateHotel(int _hotel_id, int _night_number, string _address, string _name, double _price)
            {
                if (!is_published)
                {
                    for (int i = 0; i < hotel_number; i++)
                    {
                        if (tab_hotel[i].getID() == _hotel_id)
                        {
                            tab_hotel[i].update(_night_number, _address, _name, _price);
                            setPrice();
                        }  
                    }
                }
                else
                {
                    errorBecauseTravelIsPublished();
                }    
            }

        void Travel::deleteHotel(int _hotel_id)
        {
            if (!is_published)
            {
                for (int i = 0; i < hotel_number; i++)
                {
                    if (tab_hotel[i].getID() == _hotel_id)
                    {
                        tab_hotel.erase(tab_hotel.begin() + i);
                    }
                }
                hotel_number--;

                for (int i = 0; i < hotel_number; i++)
                {
                    tab_hotel[i].setID(i);
                }
                setPrice();
                }
            else
            {
                errorBecauseTravelIsPublished();
            }
        }

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

    void Travel::setPrice()
    {
        price = 0;
        for (int i = 0; i < hotel_number; i++)
        {
            price = price + (tab_hotel[i].getNightNbr() * tab_hotel[i].getPrice());
        }
    }

    void Travel::setPlaceAvailable()
    {
        place_available++;
    }

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

