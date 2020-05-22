#include "Booking.h"

#include <iostream>

Booking::Booking(int _travel_id)
{
    travel_id = _travel_id;
    title = "";
    total_due = 0;
    is_payed = false;
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

    void Booking::setTotalDue(int _price)
    {
        total_due = _price;
    }

//