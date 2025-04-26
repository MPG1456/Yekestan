#ifndef USER_H
#define USER_H

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class User
{
    private:
    string username;
    string password;

    public:
    User();
    User(string username, string password);
    string getUsername();
    string getPassword();
    void changePass(void);
};

void setUsername(string *username);
void setPassword(string *password);
bool checkValidUsername(string username);
bool checkValidPassword(string password);
void doubleCheckPassword(string password);
bool checkPass(string tempPass);

#endif