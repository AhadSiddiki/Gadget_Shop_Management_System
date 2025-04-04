#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H
#include"Product.h"
#include "Wholesaler.h"
#include "Retailer.h"
#include<bits/stdc++.h>
using namespace std;
class ProductList
{
    private:
        vector<Product> Products;
    public:
        ProductList();
        void load();
        void update();
        void manipulate();
        virtual ~ProductList();
        void add_Product();
        friend void sell_Product(ProductList&,Wholesaler&);
        friend void sell_Product(ProductList&,Retailer&);
};

#endif // PRODUCTLIST_H
