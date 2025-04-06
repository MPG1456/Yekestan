#include "operation.h"
#include "student.h"
#include "master.h"
#include "admin.h"

void welcome(void)
{
    system("cls");
    cout << "----------YEKESTAN----------" << endl;
    cout << "WELCOME :)" << endl
         << endl;
}

void sign(void)
{
    int action;
    cout << "Please Choose The Action:" << endl;
    cout << "1. Sign Up" << endl
         << "2. Sign In" << endl;
    cin >> action;
    switch (action)
    {
    case 1:
        sign_up();
        break;
    case 2:
        sign_in();
        break;
    default:
        cout << "Wrong Input!!! Please Try Again." << endl;
        return sign();
    }
}

void sign_up(void)
{
    int action;
    cout << "For Signing Up as Student Enter 1" << endl;
    cout << "For Signing Up as Master Enter 2" << endl;
    cout << "For Signing Up as Admin Enter 3" << endl;
    cout << "For Exiting Enter 0" << endl;
    cout << "Choose The Operation: ";
    cin >> action;
    switch (action)
    {
    case 1:
        struct STUDENT_LIST *thisUser = createNewStudent();
        studentOperation(thisUser);
        break;
    case 2:
        struct MASTER_LIST *thisUser = createNewMaster();
        cout << "Once Admin Approved Your Account You Will Be able to Sign In to It." << endl;
        break;
    case 3:
        checkAdmin();
        break;
    default:
        break;
    }
    sign();
}

void sign_in(void)
{

}