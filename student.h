#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
using namespace std;

class Student
{
    public:
    Student();
};

struct STUDENT_LIST
{
    Student student;
    struct STUDENT_LIST *sNext;
};

extern STUDENT_LIST *sHead;

void createNewStudent();

#endif