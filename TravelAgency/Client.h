#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"

class Client: public User
{
    public:
        Client();
        ~Client();

        void createClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void printClient();

        void setID(int id);
        int getID();

    protected:

    private:
        int client_id;
};

#endif // CLIENT_H
