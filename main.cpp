#include <bits/stdc++.h>
#include "Account.h"
#include "Retailer.h"
#include "Wholesaler.h"
#include "Product.h"
#include "Employee.h"
#include "EmployeeList.h"
#include "ProductList.h"
#include "CustomerList.h"
#include "Admin.h"
using namespace std;

int main()
{
    Admin a1;

    CustomerList c1;

    start:
        system("cls");
        cout<<"____________________________________\n";
        cout<<"|---------Starting Menu------------|\n";
        cout<<"| _________________________________|\n";
        cout<<"| (1) Customer Options             |\n";
        cout<<"| (2) Admin Options                |\n";
        cout<<"| (0) Exit Program                 |\n";
        cout<<"____________________________________\n";
        cout<<"____________________________________\n";
        int button;
        cin>>button;
        if(button ==1){
            c1.load();
            c1.Customer_portal();
            c1.update();
        }else if(button ==2){
            a1.load();
            a1.menu();
            a1.update();
        }if(button!=0){
            goto start;
        }
        system("cls");
        cout<<"___________~~Thank You~~____________\n";
    return 0;
}
