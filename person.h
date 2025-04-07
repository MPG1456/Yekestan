#ifndef PERSON_H
#define PERSON_H

#include "user.h"
using namespace std;

class Person : public User
{
    private:
    string firstName;
    string lastName;
    bool gender;
    public:
    Person();
    Person(string username, string password, string firstName, string lastName, bool gender);
    string getName(void);
};

bool checkValidName(string fName, string lName);

#endif