#ifndef PRODUCT_H
#define PRODUCT_H
#include "Wholesaler.h"
#include "Retailer.h"

class Product
{
private:
    char name[50];
    float price;
    int quantity;
    float discount;
    float initial;
public:
    Product();
    virtual ~Product();
    void set_Product();
    void show();
    void change_price();
    void make_stock();
    void show_name();
    void change_discount();
    void buy(Retailer &r1);
    void buy(Wholesaler &ws);
};
float up_profit(float f=0.0);
#endif // PRODUCT_H
