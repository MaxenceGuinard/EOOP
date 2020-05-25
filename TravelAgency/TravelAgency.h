#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <string>
#include <vector>

#include "Travel.h"
#include "Booking.h"
#include "Payment.h"

class SuperUser;
class Employee;
class Client;

using namespace std;

class TravelAgency
{
    public:
        // Agency functions
        TravelAgency(string _name, string _address);
            
            void showAgencyDetails();
            void bankrupt();    

        ~TravelAgency();

        // SuperUser functions
        void addSuperUser(string _email, string _username, string _password, string _name, string _surname, string _address);

            void printSuperUser();
            void superUserLogin(string email, string password);
            SuperUser* returnSuperUser();
            void setSuperUser(SuperUser* tempSuperUser);
        //
        
        // Employee functions
        void addEmployee(string _email, string _username, string _password, string _name, string _surname, string _address);
            
            void printEmployee();
            void employeeLogin(string email, string password);
            Employee* returnEmployee();
            void setEmployee(Employee* tempEmployee);

            // Travel functions
            void pbTravel(Travel* travel);
               
                void publishTravel(int _travel_id);
                void unPublishTravel(int _travel_id);
                void printTravel();
                void updateTravel(int _travel_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration);
                
                // Hotel functions
                void addHotel(int _travel_id, int _night_number, string _address, string _name, double _price);

                    void updateHotel(int _travel_id, int _hotel_id, int _night_number, string _address, string _name, double _price);

                void deleteHotel(int _travel_id, int _hotel_id);

            void deleteTravel(int _travel_id);
        
        void removeEmployee(int id);
         
        // Client functions
        void addClient(string _email, string _username, string _password, string _name, string _surname, string _address);
        
            void printClient();
            void clientLogin(string email, string password);
            Client* returnClient();
            void setClient(Client* tempClient);            

            // Booking functions
            void addBooking(int _client_id, int _travel_id);
                
                void printTravelForClient();
                void printBooking(int _client_id);
                void printAppliedBooking(int _client_id);
                bool checkAvaibilityToBook(int _travel_id);
                void applied(int _client_id, int _booking_id);
                void unapplied(int _client_id, int _booking_id);

                // Plane functions
                void addPlane(int _client_id, int _bookind_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);

                    void updatePlane(int _client_id, int _booking_id, int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);
                    
                void deletePlane(int _client_id, int _booking_id, int _plane_id);

                // Train functions
                void addTrain(int _client_id, int _bookind_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);

                    void updateTrain(int _client_id, int _bookind_id, int _train_id, string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);

                void deleteTrain(int _client_id, int _booking_id, int _train_id);

                // Payment functions
                void createPayment(int _client_id, int _booking_id);
                bool checkIfIsApplied(int _client_id, int _booking_id);
                void printPayment(int _client_id);

            void deleteBooking(int _client_id, int _booking_id);



        void removeClient(int id);

        // Getter

            int getTravelNbr();
            int getTravelID();

        //

        // Setter

            void setTravelNbr(int _travel_number);

        //      

    private:

        string name;
        string address;

        int employee_number;
        int client_number;
        int superUser_number;
        int travel_number;
        int booking_number;
        int payment_number;

        int bankrupt_flag;

        vector<Employee*> tab_employee;
        vector<Client*> tab_client;
        vector<SuperUser*> tab_superUser;
        vector<Travel*> tab_travel;
        vector<Booking*> tab_booking;
        vector<Payment*> tab_payment;

};
#endif
