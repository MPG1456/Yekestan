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
    string name;
    float score;
    int capacity;
    int remainedCapacity;
    Master *masterName;
    Student *stuList[50];
    Assignment *assignList[10];
    static int courseCount;

public:
    Course(Master *masterName);
    static int getCourseCount(int setCount = 0);
    void addAssignment(void);
    string getCourseName(void) const;
    int getId(void) const;
    string getMasterName(void) const;
    Assignment **getAssignmentList(void);
    float getScore(void);
    void setScore(void);
    int getCapacity(void) const;
    int getRemainedCapacity(void) const;
    void showCourseAssignments(void);
    void showAllStudents(void);
};

struct COURSE_LIST
{
    Course *course;
    COURSE_LIST *cNext;
};

extern COURSE_LIST *cHead;

void showAllCourses(void);
void showMasterCourses(Master *);
void makeNewCourse(Master *);
#endif