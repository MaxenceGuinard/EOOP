#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>

#include "Travel.h"
#include "Plane.h"
#include "Train.h"

using namespace std;

class Booking
{
    public:
        Booking(int _travel_id);
        ~Booking();

        void bookTravel();

            void print();

            // Plane functions
            void addPlane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);
            
                void printPlane();
                void updatePlane(int _plane_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);

            void deletePlane(int _plane_id);

            // Train functions
            void addTrain(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);

                void printTrain();
                void updateTrain(int _train_id, string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);

            void deleteTrain(int _train_id);

        void deleteBooking();

        // Getter

            int getID();
            int getClientID();
            int getTravelID();
            bool getIsFinished();
            string getTitle();
            double getTotalDue();
            bool getIsPayed();
        
        //

        // Setter

            void setID(int _id);    
            void setTitle(string _title);
            void setTotalDue();
            void setTravelPrice(double _price);
            void setPlanePrice();
            void setTrainPrice();
            void setClientID(int _client_id);
            void setIsFinished(bool _is_finished);
            void setIsPayed(bool _is_payed);
        
        //

    private:
        int booking_id;
        int travel_id;
        int client_id;
        string title;

        double total_due;
        double travel_price;
        double plane_price;
        double train_price;
        
        bool is_finished;
        bool is_payed;

        int plane_number;
        int train_number;

        vector<Plane*> tab_plane;
        vector<Train*> tab_train;

};
#endif
