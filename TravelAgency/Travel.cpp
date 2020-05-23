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
}

        void Travel::print()
        {
            cout << travel_id << "; " << destination << "; " << start_date << " - " << end_date << "; " << duration << " d; " << price << "€; " << place_available << " p; " << creator_id << endl;
            printHotel();
        }

        void Travel::updateTravel(string _destination, int _place_available, string _start_date, string _end_date, double _duration)
        {
            destination = _destination;
            place_available = _place_available;
            start_date = _start_date;
            end_date = _end_date;
            duration = _duration;
        }

        // Hotel functions
        void Travel::addHotel(int _night_number, string _address, string _name, double _price)
        {
            Hotel hotel(_night_number, _address, _name, _price);
            hotel.setID(hotel_number);
            tab_hotel.push_back(hotel);
            hotel_number++;
            setPrice();
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
                for (int i = 0; i < hotel_number; i++)
                {
                    if (tab_hotel[i].getID() == _hotel_id)
                    {
                        tab_hotel[i].update(_night_number, _address, _name, _price);
                        setPrice();
                    }  
                }
            }

        void Travel::deleteHotel(int _hotel_id)
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

        // Booking functions
        void Travel::addedBook()
        {

        }

        void Travel::deletedBook()
        {

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

//

