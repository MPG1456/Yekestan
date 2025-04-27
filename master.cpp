#include "master.h"

MASTER_LIST *mHead = nullptr;

Master::Master()
{
    active = false;
    setAvailable(true);
}

struct MASTER_LIST *createNewMaster()
{
    struct MASTER_LIST *mNew = new struct MASTER_LIST;
    mNew->master = new Master;
    if (mHead == nullptr)
        mHead = mNew;
    else
    {
        struct MASTER_LIST *mTemp = mHead;
        while (mTemp->mNext)
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

    if (thisUser->master->isActive() == false)
    {
        cout << "Admin Hasn't Accepted Your Master Request Yet! Please Be Patient. " << endl
             << endl;
        return;
    }

    cout << "Welcome " << thisUser->master->getFirstName() << " " << thisUser->master->getLastName() << endl;

    int action;
    while (true)
    {
        showMasterMenu();
        cin >> action;
        switch (action)
        {
        case 1:
            thisUser->master->changePass();
            break;
        case 2:
            makeNewCourse(thisUser->master);
            break;
        case 3:
            showMasterCourses(thisUser->master);
            break;
        case 4:
            return;
        default:
            cout << "Wrone Input! TRY AGAIN" << endl;
            break;
        }
    }
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

bool Master::isActive(void) const
{
    return active;
}

void showMasterMenu(void)
{
    cout << "1. Change Password" << endl;
    cout << "2. Make New Course" << endl;
    cout << "3. Show My Courses" << endl;
    cout << "4. Sign Out" << endl;
    cout << "Choose Desired Action: ";
}

void Master::showMasterCourses(void)
{
    struct COURSE_LIST *cTemp = cHead;
    while (cTemp != nullptr)
    {
        if (cTemp->course->getMasterName() == this->getFullName())
            cout << cTemp->course->getId() << ". " << cTemp->course->getCourseName() << endl;
        cTemp = cTemp->cNext;
    }
    cout << endl;
    int action;
    bool isCorrect = false;
    while (true)
    {
        do
        {
            cout << "Choose A Course ID To continue or Enter 0 to exit: ";
            cin >> action;
            if (action == 0)
                return;
            cTemp = cHead;
            while (cTemp)
                if (cTemp->course->getId() == action)
                {
                    isCorrect = true;
                    break;
                }
                else
                    cTemp = cTemp->cNext;
        } while (isCorrect == false);
        while (true)
        {
            cout << "0. Exit" << endl;
            cout << "1. Add Assignment" << endl;
            cout << "2. See Assignments" << endl;
            cout << "3. Show Students" << endl;
            cout << "Choose The Action: ";
            cin >> action;
            switch (action)
            {
            case 0:
                return;
            case 1:
                cTemp->course->addAssignment();
                break;
            case 2:
                cTemp->course->showCourseAssignments();
                break;
            case 3:
                cTemp->course->showAllStudents();
                break;
            default:
                cout << "Wrong Input! TRY AGAIN" << endl;
                break;
            }
        }
    }
}

void deleteMaster(void)
{
    string tempName;
    struct MASTER_LIST *mTemp = mHead;
    cout << "Enter Full Name: ";
    cin >> tempName;
    while (mTemp)
    {
        if (tempName == mTemp->master->getFullName())
        {
            mTemp->master->setAvailable(false);
            return;
        }
        mTemp = mTemp->mNext;
    }
    cout << tempName << " wan't found!" << endl;
    return;
}

void showMasterInfo(void)
{
    int action;
    string tempName;
    struct MASTER_LIST *mTemp = mHead;
    cout << "Enter Full name: ";
    cin >> tempName;
    while(mTemp)
    {
        if(mTemp->master->getFullName() == tempName)
        {
            cout << "Username: " << mTemp->master->getUsername() << endl;
            cout << "Password: " << mTemp->master->getPassword() << endl;
            cout << "Full Name: " << mTemp->master->getFullName() << endl;
            cout << "Gender: " << (mTemp->master->getGender() ? "Male" : "Female") << endl;
            cout << "Availablity Status: " << (mTemp->master->isAvailable() == true ? "Available" : "Not Available") << endl;
            cout << "Active Status: " << (mTemp->master->isActive() == true ? "Active" : "Not Active") << endl;
            cout << "Do you want to change Info of this User?(1 for yes, else for no): ";
            cin >> action;
            if(action == 1)
                mTemp->master->changeMasterInfo();
            return;
        }
        mTemp = mTemp->mNext;
    }
    cout << tempnam << " wan't found!" << endl;
    return;
}

void Master::changeMasterInfo(void)
{
    int action;
    string strTemp;
    int boolTemp;
    cout << "0. EXIT" << endl;
    cout << "1. Password" << endl;
    cout << "2. Active Status" << endl;
    cout << "Choose Action: ";
    cin >> action;
    switch(action)
    {
        case 0:
            return;
        case 1:
            this->changePass();
            break;
        case 2:
            cout << "Enter Active Status: ";
            cin >> active;
        default:
            cout << "WRONG INPUT! TRY AGAIN" << endl;
            break;   
    }
}