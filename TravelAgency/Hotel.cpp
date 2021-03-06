#include "Hotel.h"

#include <iostream>

// constructor
Hotel::Hotel(int _night_number, string _address, string _name, double _price)
{
    night_number = _night_number;
    address = _address;
    name = _name;
    price = _price;
}

        // print all the informations about the hotel
        void Hotel::print()
        {
            cout << "       " << hotel_id << "; " << night_number << " n; " << name << "; " << address << "; " << price << "€ /n" <<  endl;
        }

        // update all the informations of the hotel
        void Hotel::update(int _night_number, string _address, string _name, double _price)
        {
            night_number = _night_number;
            address = _address;
            name = _name;
            price = _price;
        }

// destructor
Hotel::~Hotel()
{
    
}

// Getter

    int Hotel::getID()
    {
        return hotel_id;
    }

    double Hotel::getPrice()
    {
        return price;
    }

    int Hotel::getNightNbr()
    {
        return night_number;
    }

//

// Setter

    void Hotel::setID(int _id)
    {
        hotel_id = _id;
    }

//
