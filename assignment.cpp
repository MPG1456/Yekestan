#include "assignment.h"

Assignment::Assignment(Course *course) : course(course)
{
    cout << "Enter Title of Assignment: ";
    cin >> title;
    cout << "Enter Description of Assignment: ";
    cin >> description;
    cout << "Do You Want to Active This Assignment? (1 for yes, 0 for no): ";
    cin >> isActive;
    cout << "Assignment Successfuly Added" << endl;
    for(int i = 0; i < 50; ++i)
        subList[i] = nullptr;
}

int Assignment::getCourseId(void) const
{
    return course->getId();
}

Submission **Assignment::getSubList(void) const
{
    return subList;
}

