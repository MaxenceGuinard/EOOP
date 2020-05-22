#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Travel.h"

using namespace std;

class Booking
{
    public:
        Booking(int _travel_id);
        ~Booking();

        void bookTravel();

            void updateBooking();

        void deleteBooking();

        // Getter

            int getID();
        
        //

        // Setter

            void setID(int _id);    
            void setTitle(string _title);
            void setTotalDue(int _price);
        
        //

    private:
        int booking_id;
        int travel_id;
        string title;
        double total_due;
        bool is_payed;
};
#endif
