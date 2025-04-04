#include<bits/stdc++.h>
#include "ProductList.h"
#include "Product.h"
#include "Wholesaler.h"
#include "Retailer.h"
using namespace std;
ProductList:: ProductList(){
};
void ProductList::load(){
    Products.clear();
    ifstream ifile("Products.bin",ios::binary);
    if(!ifile.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    Product dumProduct;
    while(ifile.read(reinterpret_cast<char*>(&dumProduct),sizeof(Product)))
    {
        Products.push_back(dumProduct);
    }
    ifile.close();
};
void ProductList::update(){
    ofstream ofile("Products.bin",ios::binary);
    if(!ofile.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    for(Product dumProduct:Products)
    {
        ofile.write(reinterpret_cast<char*>(&dumProduct),sizeof(Product));
    }
    ofile.close();
};
void ProductList::manipulate(){
    start:
    system("cls");
    int index = 1;
    cout<<"****~~~~~~Type index to select Product~~~~~~******\n";
    for(auto i:Products)
    {
        cout<<index++<<" : ";
        i.show_name();
        cout<<endl;
    }
    cout<<"\nPress 0 to go back\n";
    cin>>index;
    index--;
    if(index>=0 && index<(int)Products.size())
    {
        lab:
        system("cls");
        cout<<"The Product \n";
        Products[index].show();
        cout<<"\nPress 1 to change price of Product\n";
        cout<<"Press 2 to remove Product\n";
        cout<<"Press 3 to make stock of Product\n";
        cout<<"Press 4 to change discount\n";
        cout<<"Press 0 to go back\n";
        int button;
        cin>>button;
        system("cls");
        if(button==1)
        {
            Products[index].change_price();
            cout<<"|============Price Changed==============|\n";
            system("pause");

        }
        else if(button ==2)
        {
            Products.erase(Products.begin()+index);
            cout<<"|=========Deletion Successful===========|\n";
            system("pause");
            return ;
        }
        else if(button == 3)
        {
            Products[index].make_stock();
            cout<<"|==========Success in making Stock======|\n";
            system("pause");
        }
        else if(button == 4)
        {
            Products[index].change_discount();
            cout<<"|===========Discount Changed============|\n";
            system("pause");
        }else if (button==0){
            goto start;
        }
        goto lab;
    }
    else
    {
        return ;
    }
    return ;
};
ProductList::~ProductList(){
};
void ProductList::add_Product(){
    system("cls");
    Product dumProduct;
    dumProduct.set_Product();
    Products.push_back(dumProduct);
    cout<<"|=========New Product Added Successfully=========|\n";
    system("pause");
};
void sell_Product(ProductList &pList,Retailer &rt){
    start:
    system("cls");
    cout<<"|------------Retailer Product Buying portal----------|\n";
    cout<<"|---------------(0) to Back--------------------------|\n";
    int index = 1;
    for(auto p:pList.Products){
        cout<<index++<<" : ";
        p.show_name();
        cout<<endl;
    }
    cin>>index;
    if(index>0 && index<=pList.Products.size()){
        pList.Products[index-1].buy(rt);
    }
    if(index==0){
        pList.update();
        return;
    }
    goto start;
};
void sell_Product(ProductList &pList,Wholesaler &ws){
    start:
    system("cls");
    cout<<"|----------Wholesaler Product Portal-----------|\n";
    cout<<"|----------------(0) to Back-------------------|\n";
    int index = 1;
    for(auto p:pList.Products){
        cout<<"("<<index++<<") : ";
        p.show_name();
        cout<<endl;
    }
    cin>>index;
    if(index>0 && index<=pList.Products.size()){
        pList.Products[index-1].buy(ws);
    }
    if(index==0){
        pList.update();
        return;
    }
    goto start;
};
