#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

using namespace std;

class Payment
{
    public:
        Payment();
        ~Payment();       

        void addPayment();
        void refundPayment();
        void searchPayment();

    protected:

    private:
        int payment_id;
        double amount;
        string date;
        int booking_id;
        int client_id;
};  
#endif
