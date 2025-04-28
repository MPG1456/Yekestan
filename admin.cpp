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
        case 8:
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
    cout << "3. Show User Information" << endl;
    cout << "4. Update User Information" << endl;
    cout << "5. Restore Deleted User" << endl;
    cout << "6. Show New Master Requests" << endl;
    cout << "7. Show All Courses" << endl;
    cout << "8. Sign Out" << endl;
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

