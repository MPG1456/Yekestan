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

    cout << "Welcome " << thisUser->student->getFirstName() << " " << thisUser->student->getLastName() << endl;
    int action;
    while (true)
    {
        showStudentMenu();
        cin >> action;
        switch (action)
        {
        case 1:
            thisUser->student->changePass(&thisUser->student->getPassword());
            break;
        case 5:
            return;
        default:
            cout << "Wrone Input! TRY AGAIN" << endl;
            break;
        }
    }
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

void showStudentMenu(void)
{
    cout << "1. Change Password" << endl;
    cout << "2. Show Taken Courses" << endl;
    cout << "3. Show All Courses" << endl;
    cout << "4. Show Assignments" << endl;
    cout << "5. Sign Out" << endl;
    cout << "Choose Desired Action: ";
}
