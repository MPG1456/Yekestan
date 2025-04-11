#include "assignment.h"

Assignment::Assignment(Course *course) : course(course)
{
    cout << "Enter The Capacity of The Assignment: ";
    cin >> capacity;
    cout << "Enter Title of Assignment: ";
    cin >> title;
    cout << "Enter Description of Assignment: ";
    cin >> description;
    cout << "Do You Want to Active This Assignment? (1 for yes, 0 for no): ";
    cin >> isActive;
    cout << "Assignment Successfuly Added" << endl;
}

int Assignment::getCourseId(void) const
{
    return course->getId();
}

struct SUBMISSION_LIST *Assignment::getSubList(void) const
{
    return subList;
}

