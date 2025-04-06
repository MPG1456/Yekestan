#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
using namespace std;
#define ADMIN "admin"

class Admin : public User
{   
    public:
    Admin();
};

extern Admin admin;

void checkAdmin();

#endif