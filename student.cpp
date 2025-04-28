#include "student.h"

STUDENT_LIST *sHead = nullptr;

Student::Student()
{
    GPA = -1;
    setAvailable(true);
    for (int i = 0; i < 10; ++i)
    {
        myCourses[i].score = -1;
        myCourses[i].course = nullptr;
    }
}

struct STUDENT_LIST *createNewStudent(void)
{
    struct STUDENT_LIST *sNew = new struct STUDENT_LIST;
    sNew->student = new Student;
    if (sHead == nullptr)
        sHead = sNew;
    else
    {
        struct STUDENT_LIST *sTemp = sHead;
        while (sTemp->sNext)
            sTemp = sTemp->sNext;
        sTemp->sNext = sNew;
    }
    return sNew;
}

void studentOperation(struct STUDENT_LIST *thisUser)
{
    if (thisUser == nullptr)
    {
        cout << "There is no Such Username!" << endl;
        return;
    }
    if (checkPass(thisUser->student->getPassword()) == false)
        return;

    cout << "Welcome " << thisUser->student->getFirstName() << " " << thisUser->student->getLastName() << endl;
    int action;
    while (true)
    {
        showStudentMenu();
        cin >> action;
        switch (action)
        {
        case 1:
            thisUser->student->changePass();
            break;
        case 2:
            thisUser->student->showMyCourses();
            break;
        case 3:
            showAllCourses();
            break;
        case 4:
            return;
        default:
            cout << "Wrone Input! TRY AGAIN" << endl;
            break;
        }
    }
}

struct STUDENT_LIST *findStudent(void)
{
    struct STUDENT_LIST *sTemp;
    string tempUsername;
    sTemp = sHead;
    cout << "Enter Username: ";
    cin >> tempUsername;
    while (sTemp)
    {
        if (sTemp->student->getUsername().compare(tempUsername) == 0)
            break;
        else
            sTemp = sTemp->sNext;
    }

    return sTemp;
}

Student *findStudent(string myStu)
{
    struct STUDENT_LIST *sTemp;
    sTemp = sHead;
    while (sTemp)
    {
        if (sTemp->student->getFullName().compare(myStu) == 0)
            break;
        else
            sTemp = sTemp->sNext;
    }

    return sTemp->student;
}

Student::Student(string username, string password, string firstName, string lastName, bool available, bool gender, float GPA, float *scores) : Person(username, password, firstName, lastName, available, gender)
{
    this->GPA = GPA;
    for (int i = 0; i < 10; ++i)
    {
        this->myCourses[i].score = scores[i];
        this->myCourses[i].course = nullptr;
    }
}

void showStudentMenu(void)
{
    cout << "1. Change Password" << endl;
    cout << "2. Show Taken Courses" << endl;
    cout << "3. Show All Courses" << endl;
    cout << "4. Sign Out" << endl;
    cout << "Choose Desired Action: ";
}

float Student::getGPA(void) const
{
    return GPA;
}

void Student::showMyCourses(void)
{
    if (myCourses[0].course == nullptr)
    {
        cout << "There is No Enrolled Courses To Show!" << endl;
        return;
    }

    for (int i = 0; i < 10 && myCourses[i].course != nullptr; ++i)
    {
        cout << myCourses[i].course->getId() << ". " << myCourses[i].course->getCourseName() << ": ";
        cout << myCourses[i].course->getMasterName() << endl;
    }

    while (studentCourseAction() == false)
        ;
}

bool Student::studentCourseAction(void)
{
    int action, i;
    cout << "Enter Course ID To see The Details or Enter 0 To Exit: ";
    cin >> action;
    if (action == 0)
        return true;

    for (i = 0; i < 10 && myCourses[i].course != nullptr && myCourses[i].course->getId() != action; ++i)
        ;

    if (i == 10 || myCourses[i].course == nullptr)
    {
        cout << "No Courses Found With ID: " << action << endl
             << endl;
        return false;
    }

    cout << "1. To See The Assignments" << endl;
    cout << "2. To Give Score" << endl;
    cout << "2. To Exit" << endl;
    cout << "Choose Your Action: ";
    cin >> action;
    switch (action)
    {
    case 1:
        showMyAssignments(myCourses[i].course);
        return false;
    case 2:
        giveScore(myCourses[i].course);
        return false;
    case 3:
        return true;
    default:
        cout << "WRONG INPUT!" << endl;
        return false;
    }
}

void Student::showMyAssignments(Course *myCourse)
{
    int action, i, j;
    Assignment **assignList = myCourse->getAssignmentList();
    Submission **subTemp;
    if (assignList[0] == nullptr)
    {
        cout << "No Assignments Yet!" << endl;
        return;
    }

    for (i = 0; i < 10 && assignList[i] != nullptr; ++i)
    {
        subTemp = assignList[i]->getSubList();
        for (j = 0; j < 50 && subTemp[j] != nullptr; ++j)
            if (subTemp[j]->getStu() == this)
            {
                cout << "==================================================================================" << endl;
                cout << i + 1 << ". ";
                cout << assignList[i]->getTitle() << ": " << assignList[i]->getDescription() << endl;
                cout << "Your Respond: " << subTemp[j]->getRespond() << endl;
                cout << "Score: " << subTemp[j]->getScore();
                cout << "Status: ";
                if (assignList[i]->getIsActive() == true)
                {
                    cout << "Actvie" << endl;
                    cout << "Do You Want To Change This Respond? (1 for yes, 0 for no)";
                    cin >> action;
                    if (action == 1)
                        subTemp[j]->setRespond();
                }
                else
                    cout << "Not Active" << endl;
                cout << "==================================================================================" << endl;

                cout << endl;
                break;
            }
    }
}

void Student::giveScore(Course *course)
{
    static bool isFirstTime = true;
    if (isFirstTime == false)
    {
        cout << "You Can Give Score Only once!" << endl;
        return;
    }

    course->setScore();
    isFirstTime = false;
}

int Student::getCourseScore(Course *course) const
{
    for (int i = 0; i < 10; ++i)
        if (myCourses[i].course == course)
            return myCourses[i].score;
    return -1;
}

void Student::setCourseScore(Course *course)
{
    int i;
    for (i = 0; i < 10; ++i)
        if (myCourses[i].course == course)
            break;
    cout << "Enter Students Score: " << endl;
    cin >> myCourses[i].score;
}

void deleteStudent(void)
{
    string tempName;
    struct STUDENT_LIST *sTemp = sHead;
    cout << "Enter Full Name: ";
    cin >> tempName;
    while (sHead)
    {
        if (tempName == sHead->student->getFullName())
        {
            sHead->student->setAvailable(false);
            return;
        }
        sHead = sHead->sNext;
    }
    cout << tempName << " wasn't found!" << endl;
    return;
}

void showStudentInfo(void)
{
    int action;
    string tempName;
    struct STUDENT_LIST *sTemp = sHead;
    cout << "Enter Full name: ";
    cin >> tempName;
    while (sTemp)
    {
        if (sTemp->student->getFullName() == tempName)
        {
            cout << "Username: " << sTemp->student->getUsername() << endl;
            cout << "Password: " << sTemp->student->getPassword() << endl;
            cout << "Full Name: " << sTemp->student->getFullName() << endl;
            cout << "Gender: " << (sTemp->student->getGender() == true ? "Male" : "Female") << endl;
            cout << "GPA: " << sTemp->student->getGPA() << endl;
            cout << "Avalilablity Status: " << (sTemp->student->isAvailable() == true ? "Available" : "Not Available") << endl;
            cout << "Do you want to change Info of this User?(1 for yes, else for no): ";
            cin >> action;
            if (action == 1)
                sTemp->student->changeStudentInfo();
            return;
        }
        sTemp = sTemp->sNext;
    }
    cout << tempnam << " wan't found!" << endl;
    return;
}

void Student::Student::changeStudentInfo(void)
{
    int action;
    cout << "0. EXIT" << endl;
    cout << "1. Password" << endl;
    cout << "2. GPA" << endl;
    cout << "Choose Action: ";
    cin >> action;
    switch (action)
    {
    case 0:
        return;
    case 1:
        this->changePass();
        break;
    case 2:
        cout << "Enter GPA: ";
        cin >> GPA;
    default:
        cout << "WRONG INPUT! TRY AGAIN" << endl;
        break;
    }
}

void restoreStudent(void)
{
    string tempName;
    struct STUDENT_LIST *sTemp = sHead;
    cout << "Enter Full Name: ";
    cin >> tempName;
    while (sHead)
    {
        if (tempName == sHead->student->getFullName())
        {
            sHead->student->setAvailable(true);
            return;
        }
        sHead = sHead->sNext;
    }
    cout << tempName << " wasn't found!" << endl;
    return;
}

struct ENROLLED_COURSES *Student::getCourses(void)
{
    return this->myCourses;
}