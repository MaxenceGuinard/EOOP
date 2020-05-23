#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
#include <vector>

#include "Hotel.h"

using namespace std;

class Travel
{
    public:
        Travel(int _creator_id, string _destination, int _place_available, string _start_date, string _end_date, double _duration);
        
            void print();

                void updateTravel(string _destination, int _place_available, string _start_date, string _end_date, double _duration);
                
            void deleteTravel();

            // Hotel functions
            void addHotel(int _night_number, string _address, string _name, double _price);
            
                void printHotel();
                void updateHotel(int _hotel_id, int _night_number, string _address, string _name, double _price);

            void deleteHotel(int _hotel_id);

        ~Travel();

        // Getter
        
            int getID();
            string getTitle();
            double getPrice();
            int getPlaceAvailable();

        //

        // Setter

            void setID(int id);
            void setPrice();
            void setPlaceAvailable();

        //       

    private:
        int travel_id;
        int creator_id;
        int hotel_number;
        int place_available;

        string destination;
        string start_date;
        string end_date;

        double duration;
        double price;
        
        vector<Hotel> tab_hotel;

};
#endif
