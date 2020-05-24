#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include "Travel.h"

class TravelAgency;

class Employee: public User
{
    public:
        Employee();
        ~Employee();

        // Call by TravelAgency.cpp
        void createEmployee(string _email, string _username, string _password, string _name, string _surname, string _address);
        void printEmployee();

        

        // Employee functions (login need)

            // Client help functions
            void addClient(TravelAgency* travelAgency, string _email, string _username, string _password, string _name, string _surname, string _address);
            void removeClient(TravelAgency* travelAgency, int _client_id);
        
            // Travel functions
            void createTravel(TravelAgency* travelAgency, string _destination, int _place_available, string _start_date, string _end_date, double _duration);
                
                void publishTravel(TravelAgency* travelAgency, int _travel_id);
                void unPublishTravel(TravelAgency* travelAgency, int _travel_id);
                void updateTravel(TravelAgency* travelAgency, int _travel_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration);
                
                // Hotel functions
                void addHotel(TravelAgency* travelAgency, int _travel_id, int _night_number, string _address, string _name, double _price);
                
                    void updateHotel(TravelAgency* travelAgency, int _travel_id, int _hotel_id, int _night_number, string _address, string _name, double _price);

                void deleteHotel(TravelAgency* travelAgency, int _travel_id, int _hotel_id);

                // Plane functions
                void addPlane(TravelAgency* travelAgency);

                // Train functions
                void addTrain();
            
            void deleteTravel(TravelAgency* travelAgency, int _travel_id);

            void deleteAccount(TravelAgency* travelAgency);
        
        //

        // Getter
            int getID();
            string getEmail();
            string getPassword();
        //

        // Setter
            void setID(int id);
        //

    private:
        int employee_id;
};
#endif
