#include "student.h"

STUDENT_LIST *sHead = nullptr;

Student::Student()
{
    enrolledCourses = nullptr;
    GPA = -1;
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
            thisUser->student->changePass(&thisUser->student->getPassword());
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

Student::Student(string username, string password, string firstName, string lastName, bool gender, float GPA) : Person(username, password, firstName, lastName, gender)
{
    this->GPA = GPA;
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
    struct ENROLLMENT_LIST *eTemp = enrolledCourses;
    if (eTemp == nullptr)
    {
        cout << "There is No Enrolled Courses To Show!" << endl;
        return;
    }

    while (eTemp != nullptr)
    {
        cout << eTemp->course->getId() << ". " << eTemp->course->getCourseName() << ": ";
        cout << eTemp->course->getMasterName() << endl;
    }

    while (studentCourseAction() == false)
        ;
}

bool Student::studentCourseAction(void)
{
    struct ENROLLMENT_LIST *eTemp = enrolledCourses;
    int action;
    cout << "Enter Course ID To see The Details or Enter 0 To Exit: ";
    cin >> action;
    if (action == 0)
        return true;

    while (eTemp != nullptr && eTemp->course->getId() != action)
        eTemp = eTemp->eNext;
    if (eTemp == nullptr)
    {
        cout << "No Courses Found With ID: " << action << endl;
        return false;
    }

    cout << "1. To See The Assignments" << endl;
    cout << "2. To Exit" << endl;
    cout << "Choose Your Action: ";
    cin >> action;
    switch (action)
    {
    case 1:
        showMyAssignments(eTemp->course->getAssignmentList());
    case 2:
        return true;
    default:
        cout << "WRONG INPUT!" << endl;
        return false;
    }
}

void Student::showMyAssignments(struct ASSIGNMENT_LIST *aList)
{
    int action, submissionCount = 0;
    struct ASSIGNMENT_LIST *aTemp = aList;
    Submission *tempSub;
    while (aTemp != nullptr)
    {
        aTemp = aTemp->aNext;
        tempSub = aTemp->assignment->getSubList()->submission;
        if (tempSub->getStu() == this)
        {
            submissionCount++;
            cout << "==================================================================================" << endl;
            cout << submissionCount << ". ";
            cout << aTemp->assignment->getTitle() << ": " << aTemp->assignment->getDescription() << endl;
            cout << "Your Respond: " << tempSub->getRespond() << endl;
            cout << "Score: " << tempSub->getScore();
            cout << "Status: ";
            if (aTemp->assignment->getIsActive() == true)
            {
                cout << "Actvie" << endl;
                cout << "Do You Want To Change This Respond? (1 for yes, 0 for no)";
                cin >> action;
                if (action == 1)
                    tempSub->setRespond();
            }
            else
                cout << "Not Active" << endl;
            cout << "==================================================================================" << endl;

            cout << endl;
        }
    }
    if (submissionCount == 0)
        cout << "No Submission Has Submited Yet!" << endl;
}
