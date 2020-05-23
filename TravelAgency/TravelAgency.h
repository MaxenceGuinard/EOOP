#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <string>
#include <vector>

#include "SuperUser.h"
#include "Travel.h"

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
            SuperUser returnSuperUser();
            void setSuperUser(SuperUser tempSuperUser);
        //
        
        // Employee functions
        void addEmployee(string _email, string _username, string _password, string _name, string _surname, string _address);
            
            void printEmployee();
            void employeeLogin(string email, string password);
            Employee returnEmployee();
            void setEmployee(Employee tempEmployee);

            // Travel functions
            void pbTravel(Travel travel);
               
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
            Client returnClient();
            void setClient(Client tempClient);

            // Booking functions
            bool checkAvaibilityToBook(int _travel_id);
            Travel returnBooking(int _travel_id);
            void addedBook(int _travel_id);
            void deletedBook(int _travel_id);

        void removeClient(int id);

        // Getter

            int getTravelNbr();
            int getTravelID();

        //

        // Setter

            void setTravelNbr(int _travel_number);

        //


        vector<Employee> tab_employee;
        vector<Client> tab_client;
        vector<SuperUser> tab_superUser;
        vector<Travel> tab_travel;
        
    protected:

    private:

        string name;
        string address;

        int employee_number;
        int client_number;
        int superUser_number;
        int travel_number;

        int bankrupt_flag;

        

};
#endif
