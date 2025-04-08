#include "admin.h"

Admin::Admin(void) : User(ADMIN, ADMIN) {}

Admin admin;

bool checkAdmin(void)
{
    string tempUsername;
    cout << "Enter Admin Username: ";
    cin >> tempUsername;
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
