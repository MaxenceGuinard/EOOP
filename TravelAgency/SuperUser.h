#ifndef SUPERUSER_H
#define SUPERUSER_H

#include "Employee.h"

class SuperUser: public Employee
{
    public:
        SuperUser();
        ~SuperUser();

        void createSuperUser(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);

    protected:

    private:

};

#endif // SUPERUSER_H
