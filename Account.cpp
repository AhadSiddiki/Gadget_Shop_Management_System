#include "Account.h"
#include <string.h>
Account::Account()
{
    strcpy(username,"N/A");
    strcpy(password,"N/A");
}

Account::~Account()
{
    //dtor
}

Account :: Account(char *username_,char *password_){
    strcpy(username,username_);
    strcpy(password,password_);
}
bool Account::login(char *username_,char *password_){
    if(strcmp(username,username_)==0 && strcmp(password,password_)==0 ){
        return true;
    }
    return 0;
}
bool Account:: same_name(char *ch){
    if(strcmp(username,ch)==0){
        return 1;
    }
    return 0;
}
string Account:: get_username(){
    return string(username);
}

