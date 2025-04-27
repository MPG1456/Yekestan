#include "assignment.h"

Assignment::Assignment(Course *course) : course(course)
{
    cout << "Enter Title of Assignment: ";
    cin >> title;
    cout << "Enter Description of Assignment: ";
    cin >> description;
    cout << "Do You Want to Active This Assignment? (1 for yes, 0 for no): ";
    cin >> isActive;
    for (int i = 0; i < 50; ++i)
        subList[i] = nullptr;
    cout << "Assignment Successfuly Added" << endl;
}

int Assignment::getCourseId(void) const
{
    return course->getId();
}

Submission **Assignment::getSubList(void)
{
    return subList;
}

string Assignment::getTitle(void) const
{
    return title;
}

string Assignment::getDescription(void) const
{
    return description;
}

bool Assignment::getIsActive(void) const
{
    return isActive;
}

void Assignment::setTitle(string newTitle)
{
    title = newTitle;
}

void Assignment::setDescription(string newDescription)
{
    description = newDescription;
}

void Assignment::setActive(bool newActiveMode)
{
    isActive = newActiveMode;
}

