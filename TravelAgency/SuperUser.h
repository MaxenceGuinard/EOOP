#ifndef SUPERUSER_H
#define SUPERUSER_H

#include "Employee.h"

class TravelAgency;

class SuperUser: public Employee
{
    public:
        SuperUser();
        ~SuperUser();

        void createSuperUser(string _email, string _username, string _password, string _name, string _surname, string _address);
        void printSuperUser();

        // SuperUser functions (login need)

            void addEmployee(TravelAgency* travelAgency, string _email, string _username, string _password, string _name, string _surname, string _address);
            void removeEmployee(TravelAgency* travelAgency, int _employee_id);

        //

        // Setter

            void setSUID(int id);

        //

    private:
        int superUser_id;
};

#endif // SUPERUSER_H
