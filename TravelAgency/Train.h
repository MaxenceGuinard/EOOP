#ifndef TRAIN_H
#define TRAIN_H

#include <string>

using namespace std;

class Train
{
    public:
        Train();
        ~Train();       

    protected:

    private:
        int train_id;
        string address;
        string name;
        double price;
};
#endif
