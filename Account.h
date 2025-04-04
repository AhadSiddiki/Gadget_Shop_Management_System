#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class Account
{
protected:
    char username[50];
    char password[50];
    int type;
public:
    Account();
    Account(char *username_,char *password_);
    virtual ~Account();
    bool login(char * username_,char * password_);
    virtual void  see_details()=0;
    virtual int get_type()=0;
    virtual void show_username()=0;
    bool same_name(char *ch);
    string get_username();
};

#endif // ACCOUNT_H
