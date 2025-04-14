#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string.h>
#include "course.h"

using namespace std;

class Assignment
{
private:
    string title;
    string description;
    struct SUBMISSION_LIST *subList;
    Course *course;
    bool isActive;

public:
    Assignment(Course *course);
    int getCourseId(void) const;
    struct SUBMISSION_LIST *getSubList(void) const;
    string getTitle(void) const;
    string getDescription(void) const;
    bool getIsActive(void) const;
};

struct ASSIGNMENT_LIST
{
    Assignment *assignment;
    struct ASSIGNMENT_LIST *aNext;
};

#endif