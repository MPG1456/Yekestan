#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <iostream>
#include "assignment.h"
#include "course.h"
#include "student.h"

using namespace std;

class Submission
{
private:
    Assignment *assignment;
    Student *student;
    string respond;
    float score;
public:
    Submission(Assignment *assginment, Student *student);
    void setRespond(void);
    float getScore(void) const;
    string getRespond(void) const;
    int getCourseId(void) const;
    Student *getStu(void) const;
};

struct SUBMISSION_LIST
{
    Submission *submission;
    SUBMISSION_LIST *subNext;    
};

#endif