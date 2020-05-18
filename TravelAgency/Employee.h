#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

class Employee: public User
{
    public:
        Employee();
        ~Employee();

        void createEmployee(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void printEmployee();

        void addClient();
        void updateClient();
        void removeClient();

        void createTravel();
        void updateTravel();
        void deleteTravel();

        void setID(int id);
        int getID();



    protected:

    private:
        int employee_id;
};
#endif
