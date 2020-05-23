#include "Payment.h"

#include <iostream>

Payment::Payment(int _client_id, int _booking_id, double _amount)
{
    client_id = _client_id;
    booking_id = _booking_id;
    amount = _amount;
}

        void Payment::print()
        {
            cout << client_id << "; " << booking_id << "; " << payment_id << "; " << amount << endl;
        }

Payment::~Payment()
{
    
}


// Getter

int Payment::getID()
{
    return payment_id;
}

int Payment::getClientID()
{
    return client_id;
}

int Payment::getBookingID()
{
    return booking_id;
}

int Payment::getAmount()
{
    return amount;
}

// Setter

void Payment::setID(int id)
{
    payment_id = id;
}