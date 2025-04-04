#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
private:
    char name[50];
    char type[50];
    float wage;
    public:
        Employee();
        void show();
        void set_Employee();
        void showname();
        void change_wage();
        virtual ~Employee();
        void upgrade();
        Employee(char* name_,char* type_,float wage);
};

#endif // EMPLOYEE_H
