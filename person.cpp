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

    int fLen = fName.length(), lLen = lName.length();
    for (int i = 0; i <= fLen; ++i)
        firstName[i] = fName[i];
    for (int i = 0; i <= lLen; ++i)
        lastName[i] = lName[i];

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