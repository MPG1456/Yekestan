#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
using namespace std;

class Student : public Person
{
    public:
    Student();
    Student(string username, string password, string firstName, string lastName, bool gender);
};

struct STUDENT_LIST
{
    Student *student;
    struct STUDENT_LIST *sNext;
};

extern STUDENT_LIST *sHead;

struct STUDENT_LIST *createNewStudent();
void studentOperation(struct STUDENT_LIST *);
struct STUDENT_LIST *findStudent(void);
void showStudentMenu(void);

#endif