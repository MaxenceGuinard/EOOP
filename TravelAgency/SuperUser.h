#ifndef SUPERUSER_H
#define SUPERUSER_H

#include "Employee.h"

class SuperUser: public Employee
{
    public:
        SuperUser();
        ~SuperUser();

        void createSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
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
