#ifndef USER_H
#define USER_H

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class User
{
    private:
    char username[11];
    char password[21];

    public:
    User();
    User(char *username, char *password);
    string getUsername();
    string getPassword();
};

void setUsername(char *username);
void setPassword(char *password);
bool checkValidUsername(string username);
bool checkValidPassword(string password);
void doubleCheckPassword(string password);
//void freeAllUsers();

#endif