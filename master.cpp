#include "master.h"

MASTER_LIST *mHead = nullptr;

Master::Master()
{
    active = false;

}

struct MASTER_LIST *createNewMaster()
{
    struct MASTER_LIST *mNew = new struct MASTER_LIST;
    mNew->master = new Master;
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

    if (checkPass(thisUser->master->getPassword()) == false)
        return;    
    
    if(thisUser->master->isActive() == false)
    {
        cout << "Admin Hasn't Accepted Your Master Request Yet! Please Be Patient. " << endl << endl;
        return;
    }

    cout << "Welcome " << thisUser->master->getFirstName() << " " << thisUser->master->getLastName() << endl;
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
        if (mTemp->master->getUsername().compare(tempUsername) == 0)
            break;
        else
            mTemp = mTemp->mNext;
    }

    return mTemp;
}

Master::Master(string username, string password, string firstName, string lastName, bool gender, bool active) : Person(username, password, firstName, lastName, gender)
{
    this->active = active;
}

bool Master::isActive(void)
{
    return active;
}

