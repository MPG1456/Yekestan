#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "course.h"
#include "submission.h"

using namespace std;

class Student : public Person
{
    float GPA;
    struct ENROLLMENT_LIST *enrolledCourses;

    public:
    Student();
    Student(string username, string password, string firstName, string lastName, bool gender, float GPA);
    float getGPA(void) const;
    void showMyCourses(void);
    bool studentCourseAction(void);
    void showMyAssignments(struct ASSIGNMENT_LIST *aList);
    void giveScore(Course *course);
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