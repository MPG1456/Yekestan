#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "assignment.h"
#include "master.h"
#include "student.h"

using namespace std;

class Course
{
private:
    int id;
    float score;
    string name;
    int capacity;
    int remainedCapacity;
    Master *masterName;
    struct STUDENT_LIST *stuList;
    struct ASSIGNMENT_LIST *aList;
    static int courseCount;

public:
    Course(Master *masterName);
    static int getCourseCount(int setCount = 0);
    void addAssignment(void);
    string getCourseName(void) const;
    int getId(void) const;
    string getMasterName(void) const;
    struct ASSIGNMENT_LIST *getAssignmentList(void) const;
    float getScore(void);
    void setScore(void);
    int getCapacity(void) const;
    int getRemainedCapacity(void) const;
    void showCourseAssignments(void)
};

struct COURSE_LIST
{
    Course *course;
    COURSE_LIST *cNext;
};

struct ENROLLMENT_LIST
{
    Course *course;
    int Score;
    ENROLLMENT_LIST *eNext;
};

extern COURSE_LIST *cHead;

void showAllCourses(void);

#endif