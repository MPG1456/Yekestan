#include "student.h"

STUDENT_LIST *sHead = nullptr;

Student::Student()
{
    cout << "New Student Added" << endl;
}

struct STUDENT_LIST *createNewStudent(void)
{
    struct STUDENT_LIST *sNew = new struct STUDENT_LIST;

    if (sHead == nullptr)
        sHead = sNew;
    else
    {
        struct STUDENT_LIST *sTemp = sHead;
        while (sTemp->sNext)
            sTemp = sTemp->sNext;
        sTemp->sNext = sNew;
    }
    return sNew;
}

void studentOperation(struct STUDENT_LIST *thisUser)
{
    if (thisUser == nullptr)
        return;

    if (checkPass(thisUser->student.getPassword()) == false)
        return;
}

struct STUDENT_LIST *findStudent(void)
{
    struct STUDENT_LIST *sTemp;
    string tempUsername;
    sTemp = sHead;
    cout << "Enter Username: ";
    cin >> tempUsername;
    while (sTemp)
    {
        if (sTemp->student.getUsername().compare(tempUsername) == 0)
            break;
        else
            sTemp = sTemp->sNext;
    }

    return sTemp;
}

bool checkPass(string Password)
{
    string tempPassword;
    int operation = 1;
    while (operation != 0)
    {
        cout << "Please Enter Your Password: ";
        cin >> tempPassword;
        if (Password.compare(tempPassword) == 0)
            return true;
        cout << "WRONG PASSWORD!" << endl;
        cout << "Press 1 to Retry and 0 to exit: ";
        cin >> operation;
    }
    return false;
}