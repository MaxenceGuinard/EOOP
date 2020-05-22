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
        void createClient(string _email, string _username, string _password, string _name, string _surname, string _address);
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
