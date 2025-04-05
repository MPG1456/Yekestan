#ifndef MASTER_H
#define MASTER_H

#include "person.h"

class Master : public Person
{
    public:
        Master();
};

typedef struct
{
    Master master;
    MASTER_LIST *mNext;
}MASTER_LIST;

void createNewMaster();

#endif