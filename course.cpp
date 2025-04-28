#include "course.h"

static int courseCount = 1;

COURSE_LIST *cHead = nullptr;

Course::Course(Master *masterName) : masterName(masterName)
{
    score = -1;
    id = getCourseCount(1);
    cout << "Please Enter The Name Of The Course: ";
    cin >> name;
    cout << "Please Enter The Capacity Of This Course: ";
    cin >> capacity;
    remainedCapacity = capacity;
    for(int i = 0; i < 50; ++i)
        stuList[i] = nullptr;
    cout << "Do You Want to Add Assignment To This Course? (1 for yes, 0 for no): ";
    bool operation;
    if (operation == true)
        addAssignment();
    else
        for(int i = 0; i < 10; ++i)
            assignList[i] = nullptr;

    struct COURSE_LIST *cTemp = cHead;
    if (cTemp == nullptr)
    {
        cTemp = new struct COURSE_LIST;
        cTemp->cNext = nullptr;
    }
    else
    {
        while (cTemp->cNext != nullptr)
            cTemp = cTemp->cNext;
        cTemp->cNext = new struct COURSE_LIST;
        cTemp = cTemp->cNext;
        cTemp->cNext = nullptr;
    }
    cTemp->course = this;
}

int Course::getCourseCount(int setNum)
{
    courseCount += setNum;
    return courseCount - setNum;
}

void Course::addAssignment()
{
    int i;
    for (i = 0; i < 10 && assignList[i] != nullptr; ++i)
        ;
    if (i == 10)
    {
        cout << "You Can't Add More than 10 Assignments!" << endl;
        return;
    }

    assignList[i] = new Assignment(this);
}

string Course::getCourseName(void) const
{
    return name;
}

int Course::getId(void) const
{
    return id;
}

string Course::getMasterName(void) const
{
    return masterName->getFullName();
}

Student **Course::getStuList(void)
{
    return stuList;
}

Assignment **Course::getAssignmentList(void)
{
    return assignList;
}

void showAllCourses(void)
{
    struct COURSE_LIST *cTemp = cHead;
    if (cTemp == nullptr)
    {
        cout << "There is No Courses To Show!" << endl;
        return;
    }

    cout << endl;
    while (cTemp)
    {
        cout << cTemp->course->getId() << ". " << cTemp->course->getCourseName() << ": ";
        cout << cTemp->course->getMasterName() << endl;
        cout << "Capacity: " << cTemp->course->getCapacity() << endl;
        cout << "Remained Capacity: " << cTemp->course->getRemainedCapacity() << endl
             << endl;
    }
}

void Course::setScore()
{
    static int counter = 0;
    float newScore;
    counter++;
    bool isCorrect = false;
    do
    {
        cout << "Enter Your Score For This Course (0 - 10): ";
        cin >> newScore;
        if (newScore <= 10 && newScore >= 0)
            isCorrect = true;
        else
            cout << "Score Must be a Value Between (0 - 10)" << endl;
    } while (isCorrect == false);

    score = score * (counter - 1);
    score += newScore;
    score /= counter;
}

float Course::getScore(void)
{
    return score;
}

int Course::getCapacity(void) const
{
    return capacity;
}

int Course::getRemainedCapacity(void) const
{
    return remainedCapacity;
}

void Course::showAllStudents(void)
{
    int action, i;
    string name;
    bool isFound;
    for (i = 0; i < 50 && stuList[i] != nullptr; ++i)
    {
        cout << i + 1 << ". " << stuList[i]->getFullName() << endl;
        cout << "Score: " << stuList[i]->getCourseScore(this) << endl;
        cout << endl;
    }
    while (true)
    {
        cout << "Enter 0 to exit. Else to Change Students Score: ";
        cin >> action;
        if(action == 0)
            return;
     
        cout << "Enter The Student Name That You Want To give Score: ";
        cin >> name;
        isFound = false;
        for(i = 0; i < 50 && stuList[i] != nullptr; ++i)
            if(stuList[i]->getFullName() == name)
            {
                isFound = true;
                break;
            }
        if(isFound = true)
            stuList[i]->setCourseScore(this);
        else
            cout << "Student " << name << " wasn't found. TRY AGAIN!" << endl;
    }
}

void Course::showCourseAssignments(void)
{
    for(int i = 0; i < 10 && assignList[i] != nullptr; ++i)
    {
        cout << assignList[i]->getCourseId() << ". " << assignList[i]->getTitle() << endl;
        cout << "Description: " << assignList[i]->getDescription() << endl;
        cout << "Active Status: " << assignList[i]->getIsActive() << endl;
        cout << endl;
    }
}

// void showMasterCourses(Master *master)
// {
//     struct COURSE_LIST *cTemp = cHead;
//     int counter = 0;
//     while(cTemp)
//     {
//         if(cTemp->course->getMasterName() == master->getFullName())
//         {
//             counter++;
//             cout << cTemp->course->getId() << ". " << cTemp->course->getCourseName() << endl;
//             // cout << 
//         }
//     }
// }

void MakeNewCourse(Master *master)
{
    Course newCourse(master);
}
