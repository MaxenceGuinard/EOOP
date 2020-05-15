#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    public:
        User();
        ~User();

        //void createAccount(string initializer_email, string initializer_username, string initializer_password, string initializer_name, string initializer_surname, string initializer_address);
        void updateAccount();
        bool checkIdentity();
        void secretTextOn();
        void secretTextOff();

        void showAccount();
        void deleteAccount();




    protected:

        int user_id;

        string email;
		string username;
		string password;
		string name;
		string surname;
		string address;

    private:
};
#endif
