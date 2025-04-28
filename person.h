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
    bool available;
    public:
    Person();
    Person(string username, string password, string firstName, string lastName, bool available, bool gender);
    string getFirstName(void) const;
    string getLastName(void) const;
    string getFullName(void) const;
    bool getGender(void) const;
    bool isAvailable(void) const;
    void setAvailable(bool status);
};

bool checkValidName(string fName, string lName);

#endif