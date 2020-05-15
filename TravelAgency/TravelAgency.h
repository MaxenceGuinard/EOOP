#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <string>
#include <vector>

#include "Employee.h" // vector blabla
#include  "Client.h"

using namespace std;

class TravelAgency
{
    public:
        ~TravelAgency();

        TravelAgency(string initializer_name, string initializer_address);

        void showAgencyDetails();
        void addEmployee(int initializer_employee_id, string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void removeEmployee(int id);
        
        void printEmployee();
        
        void addClient();
        void addSuperUser();
        void bankrupt();


    protected:

    private:

        string name;
        string address;

        int employee_number;
        int client_number;

        vector<Employee> tab_employee;
        vector<Client> tab_client;

};
#endif
