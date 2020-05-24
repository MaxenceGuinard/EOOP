#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

using namespace std;

class Payment
{
    public:
        Payment(int _client_id, int _booking_id, double _amount);
        
            void print();
        
        ~Payment();       

        // Getter

        int getID();
        int getClientID();
        int getBookingID();
        int getAmount();
        bool getIsRefund();

        // Setter

        void setID(int id);
        void setIsRefund(bool _is_refund);
    
    private:
        int payment_id;
        double amount;
        int booking_id;
        int client_id;

        bool is_refund;
};  
#endif
