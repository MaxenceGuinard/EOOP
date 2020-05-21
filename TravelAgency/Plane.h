#ifndef PLANE_H
#define PLANE_H

#include <string>

using namespace std;

class Plane
{
    public:
        Plane();
        ~Plane();       

    protected:

    private:
        int plane_id;
        string address;
        string name;
        double price;
};
#endif
