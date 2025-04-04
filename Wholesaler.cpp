#include<bits/stdc++.h>
#include "Wholesaler.h"
using namespace std;
void Wholesaler::operator += (float balanceTobeadded){
    balance+=balanceTobeadded;
}
Wholesaler::Wholesaler():Account(),balance(0.0)
{
    type=1;
    //ctor
}

Wholesaler::~Wholesaler()
{
    //dtor
}

Wholesaler:: Wholesaler (char *username_,char *password_):Account(username_,password_),balance(0.0){
    type=1;
};
void Wholesaler::see_details(){
    cout<<"Type : Wholesaler\n";
    cout<<"Username : "<<username<<'\n'<<"Balance : "<<balance<<'\n'<<"|~~~~~~~~----Records------~~~~~~~~|\n";
    cout<<"|"<<setw(15)<<"Product name |"<<setw(10)<<"Quantity |"<<setw(12)<<"Charge |"<<setw(12)<<"Discount |\n";
    cout<<records<<endl;
}

int Wholesaler::get_type(){
    return type;
}
void Wholesaler:: add_balance(){
    system("cls");
    cout<<"|----------------Add Money Option----------------|\n";
    cout<<"|--------------~ "<<username<<" ~----------------|\n";
    cout<<"|--~Current Balance : "<<balance<<" unit of Money~-|\n";
    cout<<"How much balance want add to account?\n";
    float money;
    cin>>money;
    *this+=money;
    system("cls");
    cout<<balance<<" unit of money is added to your account---|\n";
    cout<<"|--~Current Balance : "<<balance<<" unit of Money~-|\n";
    system("pause");
    return ;
};
void Wholesaler::show_username(){
    cout<<username;
}
void Wholesaler::buy(char *pname,int quantity,float charge,float dis){
    char str[100];
    balance-=charge;
    sprintf(str,"%15s %10d %10.2f %10.2f\n", pname,quantity,charge,dis);
    strcat(records,str);
}
float Wholesaler::get_balance(){
    return balance;
}
