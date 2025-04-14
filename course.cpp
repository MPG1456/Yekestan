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
    stuList = nullptr;
    cout << "Do You Want to Add Assignment To This Course? (1 for yes, 0 for no): ";
    bool operation;
    if (operation == true)
        addAssignment();
    else
        aList = nullptr;

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
    struct ASSIGNMENT_LIST *aTemp = aList;
    if (aList == nullptr)
    {
        aTemp = new struct ASSIGNMENT_LIST;
        aTemp->aNext = nullptr;
    }
    else
    {
        while (aTemp->aNext != nullptr)
            aTemp = aTemp->aNext;
        aTemp->aNext = new struct ASSIGNMENT_LIST;
        aTemp = aTemp->aNext;
        aTemp->aNext = nullptr;
    }
    aTemp->assignment = new Assignment(this);
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
    string fullName = masterName->getFirstName() + masterName->getLastName();
    return fullName;
}

struct ASSIGNMENT_LIST *Course::getAssignmentList(void) const
{
    return aList;
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
