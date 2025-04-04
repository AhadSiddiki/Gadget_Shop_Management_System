#ifndef ADMIN_H
#define ADMIN_H
#include <bits/stdc++.h>
#include "Account.h"
#include "Retailer.h"
#include "Wholesaler.h"
#include "Product.h"
#include "Employee.h"
#include "EmployeeList.h"
#include "ProductList.h"
#include "CustomerList.h"
using namespace std;

class Admin
{
private:
    char username[50];
    char password[50];
public:
    Admin();
    void load();
    void update();
    void change_password();
    void menu();
    ~Admin(){};
};

#endif // ADMIN_H
