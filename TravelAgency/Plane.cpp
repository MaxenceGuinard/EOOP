#include "Plane.h"

#include <iostream>

Plane::Plane(string _flight_id, string _day, string _start_airport, string _arriving_airport, string _start_time, string _arriving_time)
{
    flight_id = _flight_id;
    day = _day;
    start_airport = _start_airport;
    arriving_airport = _arriving_airport;
    start_time = _start_time;
    arriving_time = _arriving_time;
}

Plane::~Plane()
{
    
}