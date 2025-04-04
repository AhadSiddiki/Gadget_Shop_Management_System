#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H
#include"Employee.h"
#include<bits/stdc++.h>
using namespace std;
class EmployeeList
{
    private:
        vector<Employee> employees;
    public:
        EmployeeList();
        void load();
        void update();
        void manipulate();
        virtual ~EmployeeList();
        void add_employee();

};

#endif // EMPLOYEELIST_H
