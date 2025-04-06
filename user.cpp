#include "user.h"

User::User()
{
    setUsername(username);
    setPassword(password);
}

void setUsername(char *username)
{
    string uTemp;
    int uLen;
    do
    {
        cout << "Please Enter Username: ";
        cin >> uTemp;
    } while (!checkValidUsername(uTemp));
    uLen = uTemp.length();
    for (int i = 0; i <= uLen; ++i)
        username[i] = uTemp[i];
}

void setPassword(char *Password)
{
    string pTemp;
    int pLen;
    do
    {
        cout << "Please Enter Password: ";
        cin >> pTemp;
    } while (!checkValidPassword(pTemp));
    doubleCheckPassword(pTemp);
    pLen = pTemp.length();
    for (int i = 0; i <= pLen; ++i)
        Password[i] = pTemp[i];
}

bool checkValidUsername(string username)
{
    int len = username.length();

    if (len > 10)
    {
        cout << "Username Length Must Be less than 10 characters!" << endl;
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

User::User(char *newUsername, char *newPass)
{
    int len;
    len = strlen(newUsername);
    for (int i = 0; i <= len; ++i)
        this->username[i] = newUsername[i];

    len = strlen(newPass);
    for (int i = 0; i <= len; ++i)
        this->password[i] = newPass[i];
}

string User::getUsername(void)
{
    string usernameStr(username);
    return usernameStr;
}

string User::getPassword(void)
{
    string passwordStr(password);
    return passwordStr;
}

// void freeAllUsers()
// {
    
// }