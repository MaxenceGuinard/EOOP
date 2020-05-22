#ifndef PLANE_H
#define PLANE_H

#include <string>

using namespace std;

class Plane
{
    public:
        Plane(string _flight_id, string _date, string _start_airport, string _arriving_airport, string _start_time, string _arriving_time);
        ~Plane();       

    protected:

    private:
        string flight_id; 
        string date;
        string start_airport;
        string arriving_airport;
        string start_time;
        string arriving_time;
        double price;
};
#endif
