#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

class Employee: public User
{
    public:
        Employee();
        ~Employee();

        // Call by TravelAgency.cpp
        void createEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void printEmployee();

        

        // Employee functions (login need)

            // Client help functions
            void addClient();
            void updateClient();
            void removeClient();
        
            // Travel functions
            void createTravel();
            void updateTravel();
            void deleteTravel();
        
        //

        // Getter
            int getID();
            string getEmail();
            string getPassword();
        //

        // Setter
            void setID(int id);
        //


        void sayHello();

    protected:

    private:
        int employee_id;
};
#endif
