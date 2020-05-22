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

                void updateBooking();
                
                // Plane functions
                void addPlane();

                    void updatePlane();
                    
                void deletePlane();

                // Train functions
                void addTrain();

                    void updateTrain();

                void deleteTrain();

            void deleteBooking();

        //

        // Getter
            int getID();
            string getEmail();
            string getPassword();
        //

        // Setter
            void setID(int id);
        //
        
    protected:

    private:
        int client_id;
        int booking_number;

        vector<Booking> tab_booking;


};

#endif // CLIENT_H
