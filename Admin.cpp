#include "Admin.h"
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
Admin::Admin()
{
    strcpy(username,"Admin");
    strcpy(password,"Admin");
}
void Admin:: load(){
    ifstream ifile("AdminUsernamePass.txt");
    if(!ifile.is_open()){
        cout<<"Error!\n";
        return ;
    }
    ifile>>username>>password;
};
void Admin:: update(){
    ofstream ifile("AdminUsernamePass.txt");
    if(!ifile.is_open()){
        cout<<"Error!\n";
        return ;
    }
    ifile<<username<<' '<<password;
};

void Admin::menu(){
    start:
        system("cls");
        char username_[50];
        char password_[50];
        cout<<"|---------Admin Login---------|\n";
        cout<<"Type username : ";
        cin>>username_;
        cout<<"Type password : ";
        cin>>password_;
        if(strcmp(username_,username)!=0 || strcmp(password_,password)!=0){
            system("cls");
            cout<<"Login unsuccessful!Try again!";
            system("pause");
            goto start;
        }
        system("cls");
        cout<<"|-------`````~~~Login Successful~~~```------|\n";
        ProductList p1;
        p1.load();

        EmployeeList e1;
        e1.load();

        CustomerList c1;
        c1.load();

        start2:
        cout<<"|--------~~~~~Admin Functionalities~~~------|\n";
        cout<<" (1) Product Menu                           |\n";
        cout<<" (2) Employee Menu                          |\n";
        cout<<" (3) Customer Menu                          |\n";
        cout<<" (4) Change Admin Password                  |\n";
        cout<<" (5) See Profit                             |\n";
        cout<<" (0) to Back                                |\n";
        cout<<"|-------------------------------------------|\n";
        int button;
        cin>>button;
        if(button==1){

                s2:
                system("cls");
                int btn1;
                cout<<"|++++++++--------Product Option--------+++++++++|\n";
                cout<<" (1) Add new product                            |\n";
                cout<<" (2) Operation on old product                   |\n";
                cout<<" (0) to back                                    |\n";
                cout<<"|-----------------------------------------------|\n";
                cin>>btn1;
                if(btn1==1){
                    p1.add_Product();
                }else if(btn1==2){
                    p1.manipulate();
                }else if(btn1==0){
                    goto s3;
                }
                goto s2;

        }else if(button==2){
            e1.manipulate();
        }else if(button == 3){
            c1.manipulate();
        }else if(button==4){
            change_password();
        }else if(button==5){
            int profit = up_profit();
            system("cls");
            cout<<"Overall profit : "<<profit<<endl;
            char bp;
            cout<<"You want to cash it out?(y/n)\n";
            cin>>bp;
            if(bp=='y'){
                cout<<"How much ?\n";
                float tmp;
                cin>>tmp;
                if(tmp<=profit){
                    cout<<"Cashout Success!\n";
                    up_profit((-1)*tmp);
                    system("pause");
                }else{
                    cout<<"Not that much money!\n";
                    system("pause");
                }
            }
        }
        s3:
        p1.update();
        e1.update();
        c1.update();
        if(button==0){
            return;
        }
        system("cls");
        goto start2;
}
void Admin::change_password(){
        system("cls");
    start:
        char ch[50];
        cout<<"|---------Admin Password Changing Menu---------|\n";
        cout<<"Type old Password : ";
        cin>>ch;
        if(strcmp(ch, password)){
            //goto start;
            system("cls");
            cout<<"Wrong password!\n";
            goto start;
        }
        cout<<"Type new password\n";
        cin>>ch;
        strcpy(password,ch);
        cout<<"|----~~~~~Successfully Password Changed~~~~~~--|\n";
        update();
        system("pause");
        return ;
}
