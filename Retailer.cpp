#include<bits/stdc++.h>
#include "Retailer.h"
using namespace std;
void Retailer::operator+=(float m){
    balance+= m;
}
Retailer::Retailer():Account(),balance(0.0)
{
    type=0;
    //ctor
}

Retailer::~Retailer()
{
    //dtor
}

Retailer:: Retailer (char *username_,char *password_):Account(username_,password_),balance(0.0){
    type = 0;
};
void Retailer::see_details(){
    cout<<"Type : Retailer\n";
    cout<<"Username : "<<username<<'\n'<<"Balance : "<<balance<<'\n'<<"|~~~~~~~~----Records------~~~~~~~~|\n";
    cout<<"|"<<"Product name |"<<setw(10)<<"  Quantity  |"<<setw(10)<<"Charge |\n";
    cout<<records<<endl;
    //system("pause");
}
void Retailer:: add_balance(){
    system("cls");
    cout<<"|*****Current Balance : "<<balance<<" unit of money*******|\n";
    cout<<"Type amount to be added to your account?\n";
    float money;
    cin>>money;
    *this+=money;
    system("pause");
    return ;
}
int  Retailer::get_type(){
    return type;
}
void Retailer::show_username(){
    cout<<username;
}

void Retailer::buy(char *pname,int quantity,float charge){
    char str[100];
    balance-=charge;
    sprintf(str,"%15s %10d %10.2f\n", pname,quantity,charge);
    strcat(records,str);
}
float Retailer::get_balance(){
    return balance;
}
