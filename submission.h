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
    Student *student;
    string respond;
    float score;
public:
    Submission(Student *student);
    Submission();
    Submission(Student *, string, float);
    void setRespond(void);
    float getScore(void) const;
    string getRespond(void) const;
    Student *getStu(void) const;
};

#endif