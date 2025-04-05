#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student
{
    public:
    Student();
};

typedef struct
{
    Student student;
    STUDENT_LIST *pNext;
}STUDENT_LIST;

void createNewStudent();

#endif