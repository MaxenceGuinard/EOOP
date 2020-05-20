#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"

class Client: public User
{
    public:
        Client();
        ~Client();

        // Call by TravelAgency.cpp
        void createClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void printClient();

        // Client functions (login need)



        //

        // Getter
            int getID();
            string getEmail();
            string getPassword();
        //

        // Setter
            void setID(int id);
        //
        
    protected:

    private:
        int client_id;
};

#endif // CLIENT_H
