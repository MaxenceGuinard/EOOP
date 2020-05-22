#include "Travel.h"

#include <iostream>

Travel::Travel(int _creator_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration, double _price)
{
    creator_id = _creator_id;
    destination = _destination;
    place_available = _place_available;
    start_date = _start_date;
    end_date = _end_date;
    duration = _duration;
    price = _price;
    hotel_number = 0;
    plane_number = 0;
    train_number = 0;
}

        void Travel::print()
        {
            cout << travel_id << "; " << destination << "; " << start_date << "; " << end_date << "; " << duration << "; " << price << "; " << place_available << "; " << creator_id << endl;
            printHotel();
        }

        void Travel::updateTravel(string _destination, int _place_available, string _start_date, string _end_date, double _duration, double _price)
        {
            destination = _destination;
            place_available = _place_available;
            start_date = _start_date;
            end_date = _end_date;
            duration = _duration;
            price = _price;
        }

        // Hotel functions
        void Travel::addHotel(string _address, string _name, double _price)
        {
            Hotel hotel(_address, _name, _price);
            hotel.setID(hotel_number);
            tab_hotel.push_back(hotel);
            hotel_number++;
        }

                void Travel::printHotel()
                {
                    if (hotel_number != 0)
                    {
                        cout << travel_id << "; " <<"Hotel:" << endl;
                        for (int i = 0; i < hotel_number; i++)
                        {
                            tab_hotel[i].print();
                        }
                    }
                }

            void Travel::updateHotel(int _hotel_id, string _address, string _name, double _price)
            {
                for (int i = 0; i < hotel_number; i++)
                {
                    if (tab_hotel[i].getID() == _hotel_id)
                    {
                        tab_hotel[i].update(_address, _name, _price);
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
        }

Travel::~Travel()
{
    
}


// Getter

    int Travel::getID()
    {
        return travel_id;
    }

//

// Setter
    
    void Travel::setID(int id)
    {
        travel_id = id;
    }

//

