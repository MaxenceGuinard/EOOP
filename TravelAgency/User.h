#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class TravelAgency;

class User
{
    public:
        User();
        ~User();

        // Account functions (login need)
        void login();

            void updateAccount(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);

        void logout();



        
        
        bool isLogin();

    protected:
        string email;
		string username;
		string password;
		string name;
		string surname;
		string address;

        bool is_login;


    private:
};
#endif
