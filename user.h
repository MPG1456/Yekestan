#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
    private:
    char username[11];
    char password[21];

    public:
    User();
};

void getUsername(char *username);
void getPassword(char *password);
bool checkValidUsername(string username);
bool checkValidPassword(string password);
void doubleCheckPassword(string password);

#endif