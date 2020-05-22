#ifndef HOTEL_H
#define HOTEL_H

#include <string>

using namespace std;

class Hotel
{
    public:
        Hotel(string _address, string _name, double _price);
        
            void print();
            void update(string _address, string _name, double _price);
        
        ~Hotel();       

    // Getter

        int getID();

    //

    // Setter

        void setID(int _id);

    //


    private:
        int hotel_id;
        string address;
        string name;
        double price;
};
#endif
