#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <iostream>
#include "student.h"

using namespace std;

class Student;

class Submission
{
private:
    Student *student;
    string respond;
    float score;
public:
    Submission(Student *student);
    Submission(Student *, string, float);
    void setRespond(void);
    float getScore(void) const;
    string getRespond(void) const;
    Student *getStu(void) const;
};

#endif