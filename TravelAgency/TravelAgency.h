#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <string>
#include <vector>

#include "Employee.h"
#include "Client.h"
#include "SuperUser.h"

using namespace std;

class TravelAgency
{
    public:
        // Agency functions
        TravelAgency(string initializer_name, string initializer_address);
            
            void showAgencyDetails();
            void bankrupt();    

        ~TravelAgency();

        // SuperUser functions
        void addSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);

            void printSuperUser();
            void superUserLogin(string email, string password);
            SuperUser returnSuperUser();
            void setSuperUser(SuperUser tempSuperUser);

        // Employee functions
        void addEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
            
            void printEmployee();
            void employeeLogin(string email, string password);
            Employee returnEmployee();
            void setEmployee(Employee tempEmployee);
        
        void removeEmployee(int id);
         
        // Client functions
        void addClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        
            void printClient();
            void clientLogin(string email, string password);
            Client returnClient();
            void setClient(Client tempClient);

        void removeClient(int id);

    protected:

    private:

        string name;
        string address;

        int employee_number;
        int client_number;
        int superUser_number;

        int bankrupt_flag;

        vector<Employee> tab_employee;
        vector<Client> tab_client;
        vector<SuperUser> tab_superUser;

};
#endif
