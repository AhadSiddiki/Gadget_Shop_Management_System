#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include"Account.h"
#include"Wholesaler.h"
#include"Retailer.h"

#include<bits/stdc++.h>
using namespace std;

class CustomerList
{
private:
    vector<Wholesaler> Wholesalers;
    vector<Retailer> Retailers;
    Account *Customers[200];
public:
    CustomerList();
    void load();
    void update();
    void manipulate();
    void manipulate2();
    void refresh();
    void add_Wholesaler();
    void add_Retailer();
    void Customer_portal();
    virtual ~CustomerList();

};
template<class T>
void details_show(T obj);
#endif // CUSTOMERLIST_H
