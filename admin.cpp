#include "admin.h"

Admin::Admin(void) : User((char *)ADMIN, (char *)ADMIN){}

Admin admin;

void checkAdmin(void)
{
    string tempUsername;
    string tempPassword;
    cout << "Enter Admin Username: ";
    cin >> tempUsername;
    cout << "Enter Admin Password: ";
    cin >> tempPassword;
    if(tempUsername.compare(admin.getUsername()) == 0 && tempPassword.compare(admin.getPassword()) == 0)
        cout << "Signing in..." << endl << endl;
    else
    {
        cout << "Failed to Sign In" << endl;
        return;
    }
}