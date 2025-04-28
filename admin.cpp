#include "admin.h"

Admin::Admin(void) : User(ADMIN, ADMIN) {}

Admin admin;

bool checkAdmin(void)
{
    string tempUsername;
    cout << "Enter Admin Username: ";
    cin >> tempUsername;
    if (tempUsername != "admin")
        return false;
    return checkPass(admin.getPassword());
}

void adminOperation(bool isAdmin)
{
    if (isAdmin == false)
    {
        cout << "Signing in as Admin FAILED." << endl;
        return;
    }
    else
        cout << "Signed in as Admin" << endl;

    int action;
    while (true)
    {
        showAdminMenu();
        cin >> action;
        switch (action)
        {
        case 1:
            admin.createNewUser();
            break;
        case 2:
            admin.deleteUser();
            break;
        case 3:
            admin.showUserInfo();
            break;
        case 4:
            admin.restoreUser();
            break;
        case 5:
            admin.showMasterRequests();
            break;
        case 6:
            admin.showAllCourses();
            break;
        case 7:
            return;
        default:
            cout << "Wrone Input! TRY AGAIN" << endl;
            break;
        }
    }
}

void showAdminMenu(void)
{
    cout << "1. Create New User" << endl;
    cout << "2. Delete a User" << endl;
    cout << "3. Show and Update User Information" << endl;
    cout << "4. Restore Deleted User" << endl;
    cout << "5. Show New Master Requests" << endl;
    cout << "6. Show All Courses" << endl;
    cout << "7. Sign Out" << endl;
    cout << "Choose Desired Action: ";
}

void Admin::createNewUser(void)
{
    int action;
    while (true)
    {
        cout << "0. EXIT" << endl;
        cout << "1. Create New Master" << endl;
        cout << "2. Create New Student" << endl;
        cout << "Choose Action: ";
        cin >> action;
        switch (action)
        {
        case 0:
            return;
        case 1:
            createNewMaster();
            break;
        case 2:
            createNewStudent();
            break;
        default:
            cout << "Wrong Input! TRY AGAIN!" << endl;
            break;
        }
    }
}

void Admin::deleteUser(void)
{
    int action;
    while (true)
    {
        cout << "0. EXIT" << endl;
        cout << "1. Delete Master" << endl;
        cout << "2. Delete Student" << endl;
        cout << "Choose The Action: ";
        cin >> action;
        switch (action)
        {
        case 0:
            return;
        case 1:
            deleteMaster();
            break;
        case 2:
            deleteStudent();
            break;
        default:
            cout << "WRONG INPUT! TRY AGAIN!" << endl;
            return;
        }
    }
}

void Admin::showUserInfo(void)
{
    int action;
    cout << "0. EXIT" << endl;
    cout << "1. Master Info" << endl;
    cout << "2. Student Info" << endl;
    cout << "Choose Operation: ";
    cin >> action;
    switch (action)
    {
    case 0:
        return;
    case 1:
        showMasterInfo();
        break;
    case 2:
        showStudentInfo();
        break;
    default:
        cout << "WRONG INPUT! TRY AGAIN!" << endl;
        break;
    }
}

void Admin::restoreUser(void)
{
    int action;
    while (true)
    {
        cout << "0. EXIT" << endl;
        cout << "1. Restore Master" << endl;
        cout << "2. Restore Student" << endl;
        cout << "Choose The Action: ";
        cin >> action;
        switch (action)
        {
        case 0:
            return;
        case 1:
            restoreMaster();
            break;
        case 2:
            restoreStudent();
            break;
        default:
            cout << "WRONG INPUT! TRY AGAIN!" << endl;
            return;
        }
    }
}

void Admin::showMasterRequests(void)
{
    int action;
    struct MASTER_LIST *mTemp = mHead;
    while (mTemp)
    {
        if (mTemp->master->isActive() == false)
        {
            cout << mTemp->master->getFullName() << endl;
            cout << mTemp->master->getGender() << endl;
            cout << "Enter 0 to Show Next, 1 to Active This Master: ";
            cin >> action;
            switch (action)
            {
            case 0:
                break;
                ;
            case 1:
                mTemp->master->setActive(true);
                break;
            default:
                cout << "WRONG INPUT! showing next Request." << endl;
                break;
            }
        }
        mTemp = mTemp->mNext;
    }
    cout << "~~~~~~End of Requests~~~~~~" << endl << endl;
}

void Admin::showAllCourses(void)
{
    struct COURSE_LIST *cTemp = cHead;
    while(cTemp)
    {
        cout << cTemp->course->getId() << ". " << cTemp->course->getCourseName() << endl;
        cout << "Capacity: " << cTemp->course->getCapacity() << endl;
        cout << "Remained Capacity: " << cTemp->course->getRemainedCapacity() << endl;
        cout << "Master: " << cTemp->course->getMasterName() << endl;
        cout << "Scores Students Have Given To this Course: " << cTemp->course->getScore() << endl;
        cout << endl;
        cTemp = cTemp->cNext;
    }
    cout << "~~~~~~~End of Courses~~~~~~~" << endl;
    cout << endl;
}

