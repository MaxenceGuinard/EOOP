#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
#include <vector>

using namespace std;

class Travel
{
    public:
        Travel();
        ~Travel();

        void createTravel();
        void updateTravel();
        void deleteTravel();


    protected:
        

    private:
        int travel_id;
        
        string start_date;
        string end_date;
        double duration;
        int place_available;
        double price;
        int hotel_number;
        int plane_number;
        int train_number;

        //vector<Hotel> tab_hotel;
        //vector<Plane> tab_plane;
        //vector<Train> tab_train;

};
#endif
