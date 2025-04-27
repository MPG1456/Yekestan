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
    Submission *subList[50];
    Course *course;
    bool isActive;

public:
    Assignment(Course *course);
    int getCourseId(void) const;
    Submission **getSubList(void);
    string getTitle(void) const;
    string getDescription(void) const;
    bool getIsActive(void) const;
    void setTitle(string newTitle);
    void setDescription(string newDescription);
    void setActive(bool newActiveMode);
};

#endif