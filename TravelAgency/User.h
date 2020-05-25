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

            void updateAccount(string _email, string _username, string _password, string _name, string _surname, string _address);

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
