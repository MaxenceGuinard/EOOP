#include "Hotel.h"

#include <iostream>

Hotel::Hotel(string _address, string _name, double _price)
{
    address = _address;
    name = _name;
    price = _price;
}

        void Hotel::print()
        {
            cout << "       " << hotel_id << "; " << name << "; " << address << "; " << price << endl;
        }

        void Hotel::update(string _address, string _name, double _price)
        {
            address = _address;
            name = _name;
            price = _price;
        }

Hotel::~Hotel()
{
    
}

// Getter

    int Hotel::getID()
    {
        return hotel_id;
    }

//

// Setter

    void Hotel::setID(int _id)
    {
        hotel_id = _id;
    }

//
