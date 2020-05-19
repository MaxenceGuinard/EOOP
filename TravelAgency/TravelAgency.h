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
        ~TravelAgency();

        TravelAgency(string initializer_name, string initializer_address);

        void showAgencyDetails();
        
        void addEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void removeEmployee(int id);
        void printEmployee(); 
        
        void addClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void removeClient(int id);
        void printClient();

        void addSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);

        void employeeLogin(string email, string password);
        void clientLogin(string email, string password);


        void bankrupt();
        
        Employee returnEmployee();
        void setEmployee(Employee tempEmployee);

    protected:

    private:

        string name;
        string address;

        int employee_number;
        int client_number;
        int bankrupt_flag;

        vector<Employee> tab_employee;
        vector<Client> tab_client;

};
#endif
