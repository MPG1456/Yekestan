#ifndef MASTER_H
#define MASTER_H

#include "person.h"
using namespace std;

class Master : public Person
{
    public:
        Master();
};

struct MASTER_LIST
{
    Master master;
    struct MASTER_LIST *mNext;
};

extern MASTER_LIST *mHead;

void createNewMaster();

#endif