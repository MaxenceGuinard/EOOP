#ifndef BOOKING_H
#define BOOKING_H

#include <string>

using namespace std;

class Booking
{
    public:
        Booking();
        ~Booking();

        void bookTravel();
        void updateBooking();
        void deleteBooking();

    protected:

    private:
        int travel_id;
        string title;
        string description;
        double total_due;
        bool is_payed;
};
#endif
