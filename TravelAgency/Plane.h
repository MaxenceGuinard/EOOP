#ifndef PLANE_H
#define PLANE_H

#include <string>

using namespace std;

class Plane
{
    public:
        Plane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);
        
                void print();
                void updatePlane(string _flight_id, string _date, string _a_to_b, string _ad_time, double _price);
        
        ~Plane();       

        // Getter

            int getID();
            double getPrice();

        //

        // Setter 

            void setID(int id);

        //


    private:
        int plane_id;

        string flight_id; 
        string date;
        string a_to_b;
        string ad_time;

        double price;
};
#endif
