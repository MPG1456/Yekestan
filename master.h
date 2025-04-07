#ifndef MASTER_H
#define MASTER_H

#include "person.h"
using namespace std;

class Master : public Person
{
    bool active;

public:
    Master();
    Master(string username, string password, string firstName, string lastName, bool gender);
};

struct MASTER_LIST
{
    Master *master;
    struct MASTER_LIST *mNext;
};

extern MASTER_LIST *mHead;

struct MASTER_LIST *createNewMaster();
void masterOperation(struct MASTER_LIST *);
struct MASTER_LIST *findMaster(void);
#endif