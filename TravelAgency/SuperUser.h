#ifndef SUPERUSER_H
#define SUPERUSER_H

#include "Employee.h"

class SuperUser: public Employee
{
    public:
        SuperUser();
        ~SuperUser();

        void createSuperUser(string _email, string _username, string _password, string _name, string _surname, string _address);
        void printSuperUser();

        // SuperUser functions (login need)



        //

        // Setter

            void setSUID(int id);

        //

    protected:

    private:
        int superUser_id;
};

#endif // SUPERUSER_H
