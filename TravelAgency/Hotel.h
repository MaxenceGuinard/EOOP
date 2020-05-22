#ifndef HOTEL_H
#define HOTEL_H

#include <string>

using namespace std;

class Hotel
{
    public:
        Hotel(int _night_number, string _address, string _name, double _price);
        
            void print();
            void update(int _night_number, string _address, string _name, double _price);
        
        ~Hotel();       

    // Getter

        int getID();
        double getPrice();
        int getNightNbr();

    //

    // Setter

        void setID(int _id);

    //


    private:
        int hotel_id;
        int night_number;
        string address;
        string name;
        double price;
};
#endif
