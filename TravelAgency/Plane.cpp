#include "Plane.h"

#include <iostream>

Plane::Plane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
{
    flight_id = _flight_id;
    date = _date;
    a_to_b = _a_to_b;
    ad_time = _ad_time;
    price = _price;
}

        void Plane::print()
        {
            cout << "       " << plane_id << "; " << flight_id << "; " << date << "; " << a_to_b << "; " << ad_time << "; " << price << "€" << endl;
        }

        void Plane::updatePlane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price)
        {
            flight_id = _flight_id;
            date = _date;
            a_to_b = _a_to_b;
            ad_time = _ad_time;
            price = _price;
        }

Plane::~Plane()
{
    
}

// Getter

    int Plane::getID()  
    {
        return plane_id;
    }

    double Plane::getPrice()
    {
        return price;
    }

//

// Setter 

    void Plane::setID(int id)
    {
        plane_id = id;
    }

//