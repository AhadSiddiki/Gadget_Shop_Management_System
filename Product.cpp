#include<bits/stdc++.h>
#include "Product.h"
#include "Wholesaler.h"
#include "Retailer.h"
using namespace std;
Product::Product()
{
    strcpy(name,"N/A");
    quantity=0;
    price = 0.0;
    discount = 0.0;
    initial =0.0;
    //ctor
}

Product::~Product()
{
    //dtor
}
void Product::set_Product()
{
    cout<<"|========New Product Creation==========|\n";
    cout<<"Type name of the new Product : ";
    cin>>name;
    cout<<"Type Quantity : ";
    cin>>quantity;
    cout<<"Type initial value : ";
    cin>>initial ;
    cout<<"Type price : ";
    cin>>price;
    cout<<"Type discount (%): ";
    cin>>discount;
    return ;
}
void Product::show()
{
    cout<<"Name : "<<name<<"\nQuantity : "<<quantity<<"\nPrice : "<<price<<"\nDiscount : "<<discount<<"%"<<endl;
    return ;
}
void Product:: show_name()
{
    cout<<name<<endl;
}
void Product::change_price()
{
    cout<<"Current price of "<<name << " is "<<price<<" per unit\n";
    cout<<"Enter new price : ";
    cin>>price;
};
void Product::make_stock()
{
    cout<<"Current stock is "<<quantity<<endl;
    cout<<"Enter the quantity to be added :";
    int q;
    cin>> q;
    quantity+=q;
}
void Product::change_discount()
{
    cout<<"Current discount of "<<name << " is "<<discount<<" per unit\n";
    cout<<"Enter new discount : ";
    cin>>discount;
};
float up_profit(float f){

    ifstream ifile("profit.txt");
    float dum ;
    ifile>>dum;
    ifile.close();
    dum+=f;
    ofstream ofile("profit.txt");
    ofile<<dum;
    ofile.close();
    return dum;
}

void Product::buy(Wholesaler &ws){
    start:
        system("cls");
    cout<<"|"<<setw(30)<<setfill('-')<<name<<"---------------------|\n";
    cout<<"|"<<setw(30)<<setfill('-')<<"(1)To buy"<<"---------------------|\n";
    cout<<"|"<<setw(30)<<setfill('-')<<"(0)To Back"<<"---------------------|\n";
    cout<<"Name : "<<name<<"\nQuantity : "<<quantity<<"\nPrice : "<<price<<"\nDiscount : "<<discount<<" %"<<endl;
    int button;
    cin>>button;
    if(button==1)
    {
        system("cls");
        cout<<"|--------------- "<<ws.get_username()<<" -------------------|\n";
        cout<<"Name : "<<name<<"\nQuantity : "<<quantity<<"\nPrice : "<<price<<"\nDiscount : "<<discount<<" %"<<endl;
        cout<<"Your balance is "<<ws.get_balance()<<" unit of money\n";
        cout<<"How many unit of "<<name<<" you wanna buy ?\n";
        int q2;
        cin>>q2;
        if(q2>0 || q2<=quantity)
        {

            if(q2>quantity)
            {
                system("cls");
                cout<<"No requested Stock\n";
                system("pause");
                goto start;
            }
            if(q2*price*(100 - discount)/100.0 > ws.get_balance())
            {
                system("cls");
                cout<<"Not enough money\n";
                system("pause");
                goto start;
            }
            system("cls");
            //cout<<"Your balance is "<<ws.get_balance()<<" unit of money\n";
            cout<<"The price for "<<q2<<" unit of "<<name <<" is "<< q2*price<<" unit of money.\nYou'll have :"<<discount<<" % discount\nCharge will be "<<q2*price*(100-discount)/100.0<<"\nYou proceed?(y/n)\n";
            char p;
            cin>>p;
            if(p=='y')
            {
                system("cls");
                ws.buy(name,q2,q2*price*(100-discount)/100.0,discount);
                cout<<q2<<" unit of "<<name <<" is bought .\n"<<q2*price*(100-discount)/100<<" unit of money is charged.\n";
                up_profit(q2*((price*(100-discount)/100) - initial));
                cout<<"Your balance is "<<ws.get_balance()<<" unit of money\n";
                quantity-=q2;
                system("pause");
            }
        }
        system("cls");
        goto start;
    }
    else if(button==0)
    {
        return ;
    }
    goto start;
}
void Product::buy(Retailer &r1){
start:
    system("cls");
    cout<<"|"<<setw(30)<<setfill('-')<<name<<"---------------------|\n";
    cout<<"|"<<setw(30)<<setfill('-')<<"(1)To buy"<<"---------------------|\n";
    cout<<"|"<<setw(30)<<setfill('-')<<"(0)To Back"<<"---------------------|\n";
    cout<<"Name : "<<name<<"\nQuantity : "<<quantity<<"\nPrice : "<<price<<endl;
    int button;
    cin>>button;
    if(button==1)
    {
        system("cls");
        cout<<"Name : "<<name<<"\nQuantity : "<<quantity<<"\nPrice : "<<price<<"\nDiscount : "<<discount<<" %"<<endl;
        cout<<"How many unit you wanna buy ?\nThere is "<<quantity<<" unit of "<<name<<endl;
        cout<<"Your balance is "<<r1.get_balance()<<" unit of money\n";
        int q2;
        cin>>q2;
        if(q2>0 || q2<=quantity)
        {
            if(q2>quantity)
            {
                system("cls");
                cout<<"No requested Stock\n";
                system("pause");
                goto start;
            }
            if(q2*price > r1.get_balance())
            {
                system("cls");
                cout<<"Not enough money\n";
                system("pause");
                goto start;
            }
            system("cls");
            cout<<"|********************************************************|\n";
            cout<<"Your balance is "<<r1.get_balance()<<" unit of money\n";
            cout<<"The price for "<<q2<<" unit of "<<name <<" is "<< q2*price<<" unit of money.\nYou proceed?(y/n)\n";
            char p;
            cin>>p;
            if(p=='y')
            {
                system("cls");
                cout<<q2<<" unit of "<<name <<" is bought .\n"<<q2*price<<" unit of money charged.\n";
                quantity-=q2;
                r1.buy(name,q2,q2*price);
                up_profit(q2*price);
                cout<<"Your balance is "<<r1.get_balance()<<" unit of money\n";
                system("pause");

            }
        }
        system("cls");
        goto start;
    }
    else if(button==0)
    {
        return ;
    }
    goto start;
};
