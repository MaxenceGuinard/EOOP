#include "Train.h"

#include <iostream>
// constructor
Train::Train(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
{
    train_number_id = _train_number_id;
    date = _date;
    a_to_b = _a_to_b;
    ad_time = _ad_time;
    price = _price;
}
        // print all the informations about the train
        void Train::print()
        {
            cout << "       " << train_id << "; " << train_number_id << "; " << date << "; " << a_to_b << "; " << ad_time << "; " << price << "€" <<  endl;
        }

        // update the informations of the train
        void Train::updateTrain(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price)
        {
            train_number_id = _train_number_id;
            date = _date;
            a_to_b = _a_to_b;
            ad_time = _ad_time;
            price = _price;
        }

// destructor
Train::~Train()
{
    
}

// Getter
int Train::getID()  
{
    return train_id;
}

double Train::getPrice()
{
    return price;
}

// Setter 
void Train::setID(int id)
{
    train_id = id;
}