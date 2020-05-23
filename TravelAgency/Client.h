#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"
#include "Booking.h"
#include "Travel.h"

#include <vector>

using namespace std;

class TravelAgency;

class Client: public User
{
    public:
        Client();
        ~Client();

        // Call by TravelAgency.cpp
        void createClient(string _email, string _username, string _password, string _name, string _surname, string _address);
        void printClient();

        // Client functions (login need)

            void deleteAccount(TravelAgency* travelAgency);

            void showTravel(TravelAgency* travelAgency);

            // Booking functions
            void addBooking(TravelAgency* travelAgency, int _travel_id);
                
                void printBooking(TravelAgency* travelAgency);

                // Plane functions
                void addPlane(TravelAgency* travelAgency, int _bookind_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);

                    void updatePlane(TravelAgency* travelAgency, int _booking_id, int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);
                    
                void deletePlane(TravelAgency* travelAgency, int _booking_id, int _plane_id);

                // Train functions
                void addTrain(TravelAgency* travelAgency, int _bookind_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);

                    void updateTrain(TravelAgency* travelAgency, int _bookind_id, int _train_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);

                void deleteTrain(TravelAgency* travelAgency, int _booking_id, int _train_id);

            void deleteBooking(TravelAgency* travelAgency, int _booking_id);

        //

        // Getter
            int getID();
            string getEmail();
            string getPassword();
            int getBookingNumber();
        //

        // Setter
            void setID(int id);
            void setBookingNumberU();
            void setBookingNumberL();
        //
        
    protected:

    private:
        int client_id;
        int booking_number;

};

#endif // CLIENT_H
