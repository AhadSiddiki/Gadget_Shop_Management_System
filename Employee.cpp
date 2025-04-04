#include<bits/stdc++.h>
#include "Employee.h"
using namespace std;
Employee::Employee()
{
    strcpy(name,"N/A");
    strcpy(type,"N/A");
    wage  = 0.0;
}

Employee::~Employee()
{
    //dtor
}

Employee::Employee(char* name_,char* type_,float wage_){
    strcpy(name,name_);
    strcpy(type,type_);
    wage  = wage_;

}

void Employee:: show(){
    cout<<"Name : "<<name<<"\nWage : "<<wage<<"\nType : "<<type<<endl;
}

void Employee::showname(){
    cout<<name;
}
void Employee::change_wage(){
    cout<<"The old Wage is : "<<wage<<endl;
    cout<<"Enter new Wage : ";
    cin>>wage;
};
void Employee::upgrade(){
    cout<<"Current role is "<<type<<endl;
    cout<<"Enter new role ";
    cin>>type;
    return;
}
void Employee:: set_Employee(){
    cout<<"Enter new Employee Name : ";
    cin>>name;
    cout<<"Enter Wage : ";
    cin>>wage;
    cout<<"Enter Type : ";
    cin>>type;
    return ;
}
