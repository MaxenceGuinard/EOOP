#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"

class TravelAgency;

class Client: public User
{
    public:
        Client();
        ~Client();

        // Call by TravelAgency.cpp
        void createClient(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void printClient();

        // Client functions (login need)

            void deleteAccount(TravelAgency* travelAgency);

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
