#ifndef WHOLESALER_H
#define WHOLESALER_H
#include"Account.h"


class Wholesaler : public Account
{
    private:
        float balance;
        char records[1000];
    public:
        Wholesaler();
        Wholesaler(char *username_,char *password_);
        virtual ~Wholesaler();
        void add_balance();
        void operator +=(float);
        void see_details();
        void show_username();
        int get_type();
        float get_balance();
        void buy(char *pname,int quantity,float charge,float dis);
};


#endif // WHOLESALER_H
