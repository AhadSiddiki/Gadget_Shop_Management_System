#ifndef RETAILER_H
#define RETAILER_H
#include "Account.h"

class Retailer : public Account
{
    private:
        float balance;
        char records[1000];
    public:
        Retailer();
        Retailer(char *username_,char *password_);
        virtual ~Retailer();
        int get_type();
        void add_balance();
        void operator+=(float);
        void see_details();
        void show_username();
        void buy(char *pname,int quantity,float charge);
        float get_balance();

};

#endif // RETAILER_H
