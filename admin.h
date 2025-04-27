#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "master.h"
#include "student.h"

using namespace std;
#define ADMIN "admin"

class Admin : public User
{   
    public:
    Admin();
    void createNewUser(void);
    void deleteUser(void);
    void showUserInfo(void);
    void restoreUser(void);
    void showMasterRequests(void);
    void showAllCourses(void);
};

extern Admin admin;

bool checkAdmin();
void adminOperation(bool checkAdmin);
void showAdminMenu(void);

#endif