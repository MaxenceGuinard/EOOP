#include "Payment.h"

#include <iostream>

// constructor
Payment::Payment(int _client_id, int _booking_id, double _amount)
{
    client_id = _client_id;
    booking_id = _booking_id;
    amount = _amount;
    is_refund = false;
}

        // print all informations about the payment
        void Payment::print()
        {
            cout << client_id << "; " << booking_id << "; " << payment_id << "; " << amount << endl;
        }

// destructor
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

bool Payment::getIsRefund()
{
    return is_refund;
}

// Setter

void Payment::setID(int id)
{
    payment_id = id;
}

void Payment::setIsRefund(bool _is_refund)
{
    is_refund = _is_refund;
}