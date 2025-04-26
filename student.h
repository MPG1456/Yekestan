#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "course.h"
#include "submission.h"

using namespace std;

class Student : public Person
{
    float GPA;
    Course *enrolledCourses[10];

    public:
    Student();
    Student(string username, string password, string firstName, string lastName, bool gender, float GPA);
    float getGPA(void) const;
    void showMyCourses(void);
    bool studentCourseAction(void);
    void showMyAssignments(Course *);
    void giveScore(Course *);
};

struct STUDENT_LIST
{
    Student *student;
    struct STUDENT_LIST *sNext;
};

extern STUDENT_LIST *sHead;

struct STUDENT_LIST *createNewStudent();
void studentOperation(struct STUDENT_LIST *thisUser);
struct STUDENT_LIST *findStudent(void);
void showStudentMenu(void);

#endif