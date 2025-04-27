#include "person.h"

Person::Person()
{
    string fName, lName;
    do
    {
        cout << "Please Enter Your FirstName(without spaces): ";
        cin >> fName;
        cout << "Please Enter Your LastName(without spaces): ";
        cin >> lName;
    } while (checkValidName(fName, lName) == false);

    firstName = fName;
    lastName = lName;

    cout << "Choose Your Gender(1 for male and 0 for female): ";
    cin >> gender;
}

bool checkValidName(string fName, string lName)
{
    int fLen = fName.length(), lLen = lName.length();
    for (int i = 0; i < fLen; ++i)
        if (fName[i] < 'A' || (fName[i] > 'Z' && fName[i] < 'a') || fName[i] > 'z')
        {
            cout << "You Can Only Use (A-Z), (a-z)" << endl;
            return false;
        }
    for (int i = 0; i < lLen; ++i)
        if (lName[i] < 'A' || (lName[i] > 'Z' && lName[i] < 'a') || lName[i] > 'z')
        {
            cout << "You Can Only Use (A-Z), (a-z)" << endl;
            return false;
        }
    return true;
}

Person::Person(string username, string password, string firstName, string lastName, bool gender) : User(username, password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
}

string Person::getFirstName(void) const
{
    return firstName;
}

string Person::getLastName(void) const
{
    return lastName;
}

bool Person::getGender(void) const
{
    return gender;
}

string Person::getFullName(void) const
{
    string newName = firstName + " " + lastName;
    return newName;
}

bool Person::isAvailable(void) const
{
    return available;
}

void Person::setAvailable(bool status)
{
    available = status;
}
