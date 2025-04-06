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
};

bool checkValidName(string fName, string lName);

#endif