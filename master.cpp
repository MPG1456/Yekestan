#include "master.h"

MASTER_LIST *mHead = nullptr;

Master::Master()
{
    cout << "New Master Created" << endl;
}

void createNewMaster()
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
}