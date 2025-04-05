#include "master.h"

MASTER_LIST *mHead = nullptr;

Master::Master()
{
    cout << "New Master Created" << endl;
}

void createNewMaster()
{
    MASTER_LIST *mNew = new MASTER_LIST;
    
    if(mHead == nullptr)
        mHead = mNew;
    else
    {
        MASTER_LIST *mTemp = mHead;
        while(mTemp->mNext)
            mTemp = mTemp->mNext;
        mTemp->mNext = mNew;
    }

}