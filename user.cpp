#include "user.h"

User::User()
{
    setUsername(&username);
    setPassword(&password);
}

void setUsername(string *username)
{
    string uTemp;
    do
    {
        cout << "Please Enter Valid Username: ";
        cin >> uTemp;
    } while (!checkValidUsername(uTemp));
    *username = uTemp;
}

void setPassword(string *password)
{
    string pTemp;
    do
    {
        cout << "Please Enter Valid Password: ";
        cin >> pTemp;
    } while (!checkValidPassword(pTemp));
    doubleCheckPassword(pTemp);
    *password = pTemp;
}

bool checkValidUsername(string username)
{
    int len = username.length();

    if (len > 10 || len < 4)
    {
        cout << "Username Length Must Be 4 to 10 Characters!" << endl;
        return false;
    }

    if (username[0] < 'A' || (username[0] > 'Z' && username[0] < 'a') || username[0] > 'z')
    {
        cout << "Username MUST Start With Alphabet" << endl;
        return false;
    }

    if (username[len - 1] == '.' || username[len - 1] == '_')
    {
        cout << "Username MUST not End with \'.\' or \'_\'" << endl;
        return false;
    }

    for (int i = 0; (i + 1) < len; ++i)
        if (username[i] == '_' || username[i] == '.')
        {
            if (username[i + 1] == '_' || username[i + 1] == '.')
            {
                cout << "Username MUST not include following \'.\' and \'_\' ." << endl;
                return false;
            }
        }
        else if (username[i] < 'A' || (username[i] > 'Z' && username[i] < 'a') || username[i] > 'z')
            if (username[i] != '.' && username[i] != '_' && username[i] < '0' && username[i] > '9')
            {
                cout << "Valid Characters: (A-Z), (a-z), (0-9), (\'.\'), (\'_\') ." << endl;
                return false;
            }

    if (username[len - 1] < 'A' || (username[len - 1] > 'Z' && username[len - 1] < 'a') || username[len - 1] > 'z')
        if (username[len - 1] != '.' && username[len - 1] != '_' && username[len - 1] < '0' && username[len - 1] > '9')
        {
            cout << "Valid Characters: (A-Z), (a-z), (0-9), (\'.\'), (\'_\') ." << endl;
            return false;
        }
    return true;
}

bool checkValidPassword(string password)
{
    int plen = password.length(), lChar = 0, uChar = 0, sChar = 0, nChar = 0;
    if (plen < 6 || plen > 20)
    {
        cout << "Password Must Have Min of 6 and Max of 20 Characters!" << endl;
        return false;
    }

    for (int i = 0; i < plen; ++i)
        if (password[i] >= 'A' && password[i] <= 'Z')
            uChar++;
        else if (password[i] >= 'a' && password[i] <= 'z')
            lChar++;
        else if (password[i] >= '0' && password[i] <= '9')
            nChar++;
        else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$')
            sChar++;
        else if (password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*')
            sChar++;
        else if (password[i] == '(' || password[i] == ')' || password[i] == '_' || password[i] == '-')
            sChar++;
        else if (password[i] == '+' || password[i] == '=')
            sChar++;
        else
        {
            cout << "Password Can Only Contain (A-Z), (a-z), (0-9), !@#$%^&*)(_-+=" << endl;
            return false;
        }

    if (lChar < 1 || uChar < 1 || nChar < 1 || sChar < 1)
    {
        cout << "Password Must Contain At Least a LowerCase, an UpperCase, a number and a symbol" << endl;
        return false;
    }

    return true;
}

void doubleCheckPassword(string password1)
{
    string password2;
    while (1)
    {
        cout << "Enter Again Your Password: ";
        cin >> password2;
        if (password2.compare(password1) == 0)
            return;
        else
            cout << "Passwords Don't Match! TRY AGAIN" << endl;
    }
}

User::User(string newUsername, string newPass)
{
    username = newUsername;
    password = newPass;
}

string User::getUsername(void)
{
    return username;
}

string User::getPassword(void)
{
    return password;
}

bool checkPass(string Password)
{
    string tempPassword;
    int operation = 1;
    while (operation != 0)
    {
        cout << "Please Enter Your Password: ";
        cin >> tempPassword;
        if (Password.compare(tempPassword) == 0)
            return true;
        cout << "WRONG PASSWORD!" << endl;
        cout << "Press 1 to Retry and 0 to exit: ";
        cin >> operation;
    }
    return false;
}

void User::changePass(void)
{
    string newPass;
    while (1)
    {
        cout << "Please Enter Your New Password: ";
        cin >> newPass;

        if (checkValidPassword(newPass) == true)
        {
            doubleCheckPassword(newPass);
            break;
        }
    }
    password = newPass;
    cout << "Password Successfuly Changed." << endl;
}

