#ifndef PERSON_H
#define PERSON_H

#include "user.h"

class Person : public User
{
    private:
    char firstName[50];
    char lastName[50];
    bool gender;
    public:
    Person();
};

bool checkValidName(string fName, string lName);

#endif