#include "CustomerList.h"
#include<bits/stdc++.h>
#include"Account.h"
#include"Wholesaler.h"
#include"Retailer.h"
#include"ProductList.h"
using namespace std;
template<class T>
void details_show(T obj){
    obj.see_details();
}
CustomerList::CustomerList()
{

    //ctor
}

CustomerList::~CustomerList()
{
    //dtor
}
void CustomerList::load()
{
    Wholesalers.clear();
    ifstream ifile("Wholesalers.bin",ios::binary);
    if(!ifile.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    Wholesaler dumWholesaler;
    while(ifile.read(reinterpret_cast<char*>(&dumWholesaler),sizeof(Wholesaler)))
    {
        Wholesalers.push_back(dumWholesaler);
    }
    ifile.close();

    Retailers.clear();
    ifstream ifile1("Retailers.bin",ios::binary);
    if(!ifile1.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    Retailer dumRetailer;
    while(ifile1.read(reinterpret_cast<char*>(&dumRetailer),sizeof(Retailer)))
    {
        Retailers.push_back(dumRetailer);
    }
    ifile1.close();

}
void CustomerList::update()
{
    ofstream ifile("Wholesalers.bin",ios::binary);
    if(!ifile.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }

    for(Wholesaler dumWholesaler:Wholesalers)
    {
        ifile.write(reinterpret_cast<char*>(&dumWholesaler),sizeof(Wholesaler));
    }
    ifile.close();

    ofstream ifile1("Retailers.bin",ios::binary);
    if(!ifile1.is_open())
    {
        cout<<"Error Opening File.\n";
        return;
    }
    Retailer dumRetailer;
    for(Retailer dumRetailer:Retailers)
    {
        ifile1.write(reinterpret_cast<char*>(&dumRetailer),sizeof(Retailer));
    }
    ifile1.close();
};
void CustomerList::manipulate()
{
start:
    Account *generalCustomer;
    //map<int,int> arb;
    system("cls");
    cout<<"|---------~~Customer List Options~~--------|\n";
    cout<<" (1) Retailer List                         |\n";
    cout<<" (2) Wholesaler List                       |\n";
    cout<<" (0) Back                                  |\n";
    cout<<"|------------------------------------------|\n";
    int button;
    int index=1;
    cin>>button;
    if(button==1)
    {
ss1:
        index=1;
        system("cls");
        cout<<"|-----~~~~~~~Retailer List~~~~~~~----|\n";
        cout<<"|---------Press 0 to go back---------|\n";
        for(Retailer r: Retailers)
        {
            cout<<"("<<index++<<") : ";
            r.show_username();
            cout<<endl;
        }
        int button1 ;
        cout<<"Select index : ";
        cin>>button1;
        if(button1>0 && button1<=Retailers.size())
        {
            system("cls");
            generalCustomer = new Retailer(Retailers[button1-1]);
            generalCustomer->see_details();
            system("pause");
        }
        if(button1==0)
        {
            goto start;
        }
        goto ss1;
    }
    else if(button==2)
    {
ss2:
        index = 1;
        system("cls");
        cout<<"|-----~~~~~~Wholesaler List~~~~~~----|\n";
        cout<<"|---------Press 0 to go back---------|\n";
        for(Wholesaler r: Wholesalers)
        {
            cout<<"("<<index++<<") : ";
            r.show_username();
            cout<<endl;
        }
        int button1 ;
        cout<<"Select index : ";
        cin>>button1;
        if(button1>0 && button1<=Wholesalers.size())
        {
            system("cls");
            generalCustomer = new Wholesaler(Wholesalers[button1-1]);
            generalCustomer->see_details();
            system("pause");
        }
        if(button1==0)
        {
            goto start;
        }
        goto ss2;
    }
    else if(button ==0)
    {
        update();
        return;
    }
    goto start;

};
void CustomerList::refresh()
{
    int i=0;
    for(Retailer dum:Retailers)
    {
        Customers[i] = new Retailer(dum);
        //*Customers[i++] = dum;

    }
    for(Wholesaler dum:Wholesalers)
    {
        Customers[i] = new Wholesaler(dum);
        //*Customers[i++] = dum;
    }
    for(int j=i; j<200; j++)
    {
        Customers[i] = NULL;
    }
};
void CustomerList::manipulate2()
{
    refresh();
start:
    //map<int,int> arb;
    system("cls");
    cout<<"|---------~~Customer List Options~~--------|\n";
    cout<<" (1) Retailer List                         |\n";
    cout<<" (2) Wholesaler List                       |\n";
    cout<<" (0) Back                                  |\n";
    cout<<"|------------------------------------------|\n";
    int button;
    int index=1;
    cin>>button;
    if(button==1)
    {
ss1:
        map<int ,int> mar;
        index=1;
        system("cls");
        cout<<"|-----~~~~~~~Retailer List~~~~~~~----|\n";
        cout<<"|---------Press 0 to go back---------|\n";
        for(int i=0; i<Retailers.size(); i++)
        {
            if(Customers[i]->get_type()==0)
            {
                mar[index] = i ;
                cout<<"("<<index++<<") : ";
                Customers[i]->show_username();
                cout<<endl;
            }
        }
        int button1 ;
        cout<<"Select index : ";
        cin>>button1;
        if(button1>0 && button1<index)
        {
            system("cls");
            Customers[mar[button1]]->see_details();
            system("pause");
        }
        if(button1==0)
        {
            goto start;
        }
        goto ss1;
    }
    else if(button==2)
    {
ss2:
        map<int ,int> mar;
        index=1;
        system("cls");
        cout<<"|-----~~~~~~~Wholesaler List~~~~~~~----|\n";
        cout<<"|----------Press 0 to go back----------|\n";
        for(int i=Retailers.size(); i<Retailers.size()+Wholesalers.size(); i++)
        {
            if(Customers[i]->get_type()==1)
            {
                mar[index] = i ;
                cout<<"("<<index++<<") : ";
                Customers[i]->show_username();
                cout<<endl;
            }
        }
        int button1 ;
        cout<<"Select index : ";
        cin>>button1;
        if(button1>0 && button1<index)
        {
            system("cls");
            Customers[mar[button]]->see_details();
            system("pause");
        }
        if(button1==0)
        {
            goto start;
        }
        goto ss2;
    }
    else if(button ==0)
    {
        update();
        return;
    }
    goto start;
}




void CustomerList::add_Wholesaler()
{
start:
    char username_[50],password_[50];
    system("cls");
    cout<<"|-----~Wholesaler Account Creation~----|\n";
    cout<<"|--------------------------------------|\n";
    cout<<"Type your desired username : ";
    cin>>username_;
    for(Wholesaler w:Wholesalers)
    {
        if(w.same_name(username_))
        {
            cout<<"Username Already Exists.\n";
            system("pause");
            goto start;
        }
    }
    cout<<"Set Password : ";
    cin>>password_;
    Wholesaler dum(username_,password_);
    dum.add_balance();
    Wholesalers.push_back(dum);
    system("cls");
    cout<<"~~~~~New Wholesaler Account Created~~~~\n";
    system("pause");
    return ;
};
void CustomerList::add_Retailer()
{
start:
    system("cls");
    char username_[50],password_[50];
    cout<<"|-----~~Retailer Account Creation~~----|\n";
    cout<<"|--------------------------------------|\n";
    cout<<"Type your desired username : ";
    cin>>username_;
    for(Retailer w:Retailers)
    {
        if(w.same_name(username_))
        {
            cout<<"Username Already Exists.\n";
            system("pause");
            goto start;
        }
    }
    cout<<"Set Password : ";
    cin>>password_;
    Retailer dum(username_,password_);
    dum.add_balance();
    Retailers.push_back(dum);
    system("cls");
    cout<<"~~~~~~New Retailer Account Created~~~~~\n";
    system("pause");
    return ;
}
void CustomerList::Customer_portal()
{
start:
    system("cls");
    bool is = false;
    cout<<"|--------~~~~~[ Customer Service Portal ]~~~~~---------|\n";
    cout<<"(1) Wholesaler Service                                 |\n";
    cout<<"(2) Retailer Service                                   |\n";
    cout<<"(0) to go back                                         |\n";
    cout<<"|----------------------~~~~~~--------------------------|\n";
    int button;
    cin>>button;
    if(button==1)
    {
start2:
        system("cls");
        cout<<"||----------------Wholesaler----------------|\n";
        cout<<"|---------~~~[ Log-In / Sign-up ]~~~--------|\n";
        cout<<"(1) Already Have Account                    |\n";
        cout<<"(2) Create Account                          |\n";
        cout<<"(0) Go Back                                 |\n";
        cout<<"|-------------------------------------------|\n";
        int b2;
        cin>>b2;
        if(b2==1)
        {
            system("cls");
            char username_[50];
            char password_[50];
            cout<<"|-----------~Wholesaler Login~----------|\n";
            cout<<"Give Username :\n\t";
            cin>>username_;
            cout<<"Give Password :\n\t";
            cin>>password_;
            is = false;  // Reset the flag before checking login
            for(Wholesaler &ws :Wholesalers)
            {
                if(ws.login(username_,password_))
                {
                    is = true;
                    cout<<"|----------~Login Successful~----------|\n";
                    system("pause");  // Add pause to see the success message
s3:
                    system("cls");
                    cout<<"|-------------~~Services~~-------------|\n";
                    cout<<"(1) Buy Products                       |\n";
                    cout<<"(2) See Account details                |\n";
                    cout<<"(3) Add balance                        |\n";
                    cout<<"(0) Go back                            |\n";
                    cout<<"|--------------------------------------|\n";
                    int b3;
                    cin>>b3;
                    if(b3==1)
                    {
                        ProductList p1;
                        p1.load();
                        sell_Product(p1,ws);
                        p1.update();
                        update();
                    }
                    else if(b3==2)
                    {
                        details_show(ws);
                        system("pause");
                    }
                    else if(b3==3)
                    {
                        ws.add_balance();
                    }
                    if(b3!=0)
                    {
                        update();
                        goto s3;
                    }
                }
            }
            if(!is)
            {
                cout<<"Username Or Password didnot match\n";
                system("pause");  // This ensures you see the error message
                system("cls");    // Clear screen after seeing the message
            }
        }
        else if(b2==2)
        {
            add_Wholesaler();
            update();
        }
        if(b2!=0)
        {
            goto start2;
        }
    }
    else if(button==2)
    {
start4:
        system("cls");
        cout<<"||-----------------Retailer-----------------|\n";
        cout<<"|---------~~~[ Log-In / Sign-up ]~~~--------|\n";
        cout<<"(1) Already Have Account                    |\n";
        cout<<"(2) Create Account                          |\n";
        cout<<"(0) Go Back                                 |\n";
        cout<<"|-------------------------------------------|\n";
        int b4;
        cin>>b4;
        if(b4==1)
        {
            char username_[50];
            char password_[50];
            system("cls");
            cout<<"|*--*--*---*~Retailer Login~--*---*---|\n";
            cout<<"Give Username :\n\t";
            cin>>username_;
            cout<<"Give Password :\n\t";
            cin>>password_;
            for(Retailer &r1:Retailers)
            {
                if(r1.login(username_,password_))
                {
                    is = true;
                    cout<<"|----------~Login Successful~----------|\n";
                    system("pause");

s5:
                    system("cls");
                    cout<<"|-------------~~Services~~-------------|\n";
                    cout<<"(1) Buy Products                       |\n";
                    cout<<"(2) See Account details                |\n";
                    cout<<"(3) Add balance                        |\n";
                    cout<<"(0) Go back                            |\n";
                    cout<<"|--------------------------------------|\n";
                    int b5;
                    cin>>b5;
                    if(b5==1)
                    {
                        ProductList p1;
                        p1.load();
                        sell_Product(p1,r1);
                        p1.update();
                        update();
                    }
                    else if(b5==2)
                    {
                        system("cls");
                        details_show(r1);
                        system("pause");
                    }
                    else if(b5==3)
                    {
                        r1.add_balance();
                    }
                    if(b5!=0)
                    {
                        update();
                        goto s5;
                    }

                }
            }
            if(!is)
            {
                cout<<"Username Or Password didnot match!\n";
                system("pause");
            }
        }
        else if(b4==2)
        {
            add_Retailer();
            update();
            goto start4;
        }
        if(b4!=0)
        {
            goto start4;
        }
    }
    else if(button==0)
    {
        update();
        return ;
    }
    goto start;

}
