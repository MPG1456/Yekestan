#include "admin.h"

Admin::Admin(void) : User(ADMIN, ADMIN){}

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
    if(isAdmin == false)
    {
        cout << "Signing in as Admin FAILED." << endl;
        return;
    }
}