#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    public:
        User();
        ~User();

        void updateAccount();
        bool checkIdentity();
        void secretTextOn();
        void secretTextOff();

        void showAccount();
        void deleteAccount();




    protected:
        string email;
		string username;
		string password;
		string name;
		string surname;
		string address;

    private:
};
#endif
