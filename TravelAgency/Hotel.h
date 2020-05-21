#ifndef HOTEL_H
#define HOTEL_H

#include <string>

using namespace std;

class Hotel
{
    public:
        Hotel();
        ~Hotel();       

    protected:

    private:
        int hotel_id;
        string address;
        string name;
        double price;
};
#endif
