#include "operation.h"
#include "student.h"
#include "master.h"
#include "admin.h"

void welcome(void)
{
    cout << "----------YEKESTAN----------" << endl;
    cout << "WELCOME :)" << endl
         << endl;
}

void sign(void)
{
    int action;
    cout << "0. Exit" << endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Sign In" << endl;
    cout << "Please Choose The Action: ";
    cin >> action;
    switch (action)
    {
    case 0:
        return;
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
    sign();
}

void sign_up(void)
{
    int action;
    cout << endl;
    cout << "0. Exit" << endl;
    cout << "1. Sign Up as Student" << endl;
    cout << "2. Sign Up as Master" << endl;
    cout << "Choose The Operation: ";
    cin >> action;
    switch (action)
    {
    case 1:
        studentOperation(createNewStudent());
        break;
    case 2:
        createNewMaster();
        cout << "Once Admin Approved Your Account You Will Be able to Sign In to It." << endl;
        break;
    default:
        break;
    }
}

void sign_in(void)
{
    int action;
    cout << endl;
    cout << "0. Exit" << endl;
    cout << "1. Sign in as Student" << endl;
    cout << "2. Sign in as Master" << endl;
    cout << "3. Sign in as Admin" << endl;
    cout << "Choose The Operation: ";

    cin >> action;
    switch (action)
    {
    case 1:
        studentOperation(findStudent());
        break;
    case 2:
        masterOperation(findMaster());
        break;
    case 3:
        adminOperation(checkAdmin());
        break;
    default:
        break;
    }
}

void endMessage(void)
{
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "PROMGRAM SUCCESSFULY CLOSED" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
}

