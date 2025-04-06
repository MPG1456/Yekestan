#include "master.h"

MASTER_LIST *mHead = nullptr;

Master::Master()
{
    active = false;
}

struct MASTER_LIST *createNewMaster()
{
    struct MASTER_LIST *mNew = new struct MASTER_LIST;
    
    if(mHead == nullptr)
        mHead = mNew;
    else
    {
        struct MASTER_LIST *mTemp = mHead;
        while(mTemp->mNext)
            mTemp = mTemp->mNext;
        mTemp->mNext = mNew;
    }
    return mNew;
}

void masterOperation(struct MASTER_LIST *thisUser)
{
    if (thisUser == nullptr)
        return;

    if (checkPass(thisUser->master.getPassword()) == false)
        return;    
}

struct MASTER_LIST *findMaster(void)
{
    struct MASTER_LIST *mTemp;
    string tempUsername;
    mTemp = mHead;
    cout << "Enter Username: ";
    cin >> tempUsername;
    while (mTemp)
    {
        if (mTemp->master.getUsername().compare(tempUsername) == 0)
            break;
        else
            mTemp = mTemp->mNext;
    }

    return mTemp;
}

