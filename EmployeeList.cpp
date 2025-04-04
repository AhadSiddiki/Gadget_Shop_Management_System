#include "EmployeeList.h"
#include "Employee.h"
#include<bits/stdc++.h>
using namespace std;
EmployeeList::EmployeeList()
{

    //ctor
}

EmployeeList::~EmployeeList()
{
    //dtor
}
void EmployeeList::load()
{
    employees.clear();
    ifstream ifile("Employees.bin",ios::binary);
    if(!ifile.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    Employee dumEmployee;
    while(ifile.read(reinterpret_cast<char*>(&dumEmployee),sizeof(Employee)))
    {
        employees.push_back(dumEmployee);
    }
    ifile.close();
}
void EmployeeList::update()
{
    ofstream ofile("Employees.bin",ios::binary);
    if(!ofile.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    for(Employee dumEmployee:employees)
    {
        ofile.write(reinterpret_cast<char*>(&dumEmployee),sizeof(Employee));
    }
    ofile.close();
}
void EmployeeList::manipulate()
{
    label:
        system("cls");
        int b;
        cout<<"|---------~Employee Menu~----------|\n";
        cout<<" (1) Current Employee Option       |\n";
        cout<<" (2) Add new Employee              |\n";
        cout<<" (0) go back                       |\n";
        cout<<"|----------------------------------|\n";
        cin>>b;
        if(b==0){
            return;
        }
        if(b==1){
            goto start;
        }
        if(b==2){
            add_employee();
        }
        goto label;

start:
    system("cls");
    int index = 1;
    cout<<"|------------~~~~~~~~~Employee List for Admin~~~~~~~--------------|\n";
    cout<<"|~-~-~-~-~Select index to do further operations of  Employee~-~-~-|\n";
    for(auto i:employees)
    {
        cout<<"("<<index++<<") : ";
        i.showname();
        cout<<endl;
    }
    cout<<"\(0) : Go Back\n";
    cin>>index;
    index--;
    if(index>=0 && index<(int)employees.size())
    {
        ss2:
        system("cls");
        cout<<"|~-~-~-~The Employee~-~-~|\n";
        employees[index].show();
        cout<<"\n (1) Change Wage\n";
        cout<<" (2) Remove employee\n";
        cout<<" (3) Upgrade employee\n";
        cout<<" (0) Go back\n";
        cout<<"|~-~-~-~-~-~-~-~-~-~-~-~-|\n";
        int button;
        cin>>button;
        if(button==1)
        {
            employees[index].change_wage();
            cout<<"Employee wage is Changed Successfully\n ";
            system("pause");
        }
        else if(button ==2)
        {

            employees.erase(employees.begin()+index);
            cout<<"Employee is fired Successfully \n";
            system("pause");
            return ;
        }
        else if(button == 3)
        {
            employees[index].upgrade();
            cout<<"Employee is upgraded Successfully \n";
            system("pause");

        }
        if(button!=0)
        {
            goto ss2;
        }
    }
    if (index+1 !=0)
    {
        goto start;
    }
    goto label ;
}
void EmployeeList::add_employee()
{
    system("cls");
    cout<<"|--------New Employee adding Option--------|\n";
    Employee dumEmployee;
    dumEmployee.set_Employee();
    employees.push_back(dumEmployee);
    cout<<"New employee added successfully \n";
    system("pause");
    update();
}
