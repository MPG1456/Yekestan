#include "student.h"

STUDENT_LIST *sHead = nullptr;

Student::Student()
{
    cout << "New Student Added" << endl;
}

struct STUDENT_LIST *createNewStudent(void)
{
    struct STUDENT_LIST *sNew = new struct STUDENT_LIST;
    sNew->student = new Student;
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
    {
        cout << "There is no Such Username!" << endl;
    return;
    }
    if (checkPass(thisUser->student->getPassword()) == false)
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
        if (sTemp->student->getUsername().compare(tempUsername) == 0)
            break;
        else
            sTemp = sTemp->sNext;
    }

    return sTemp;
}

Student::Student(string username, string password, string firstName, string lastName, bool gender) : Person(username, password, firstName, lastName, gender)
{}