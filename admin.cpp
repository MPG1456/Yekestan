#include "admin.h"

Admin::Admin(void) : User(ADMIN, ADMIN){}

Admin admin;

void checkAdmin(void)
{
    string tempUsername;
    string tempPassword;
    cout << "Enter Admin Username: ";
    cin >> tempUsername;
    if(checkPass(admin.getPassword()) == false)
        return;
}