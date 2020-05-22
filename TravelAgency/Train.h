#ifndef TRAIN_H
#define TRAIN_H

#include <string>

using namespace std;

class Train
{
    public:
        Train(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);

                void print();
                void updateTrain(string _train_number_id, string _date, string _a_to_b, string _ad_time, double _price);
        
        ~Train();       

        // Getter

            int getID();
            double getPrice();

        //

        // Setter 

            void setID(int id);

        //


    private:
        int train_id;

        string train_number_id; 
        string date;
        string a_to_b;
        string ad_time;
        
        double price;
};
#endif
