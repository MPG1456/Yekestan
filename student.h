#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "course.h"
#include "assignment.h"
#include "submission.h"
using namespace std;

class Course;

struct ENROLLED_COURSES
{
    Course *course;
    float score;
    struct ENROLLE_COURSES *eNext;
};

class Student : public Person
{
    float GPA;
    struct ENROLLED_COURSES myCourses[10];

    public:
    Student();
    Student(string username, string password, string firstName, string lastName, bool available, bool gender, float GPA, float *scores);
    float getGPA(void) const;
    void showMyCourses(void);
    bool studentCourseAction(void);
    void showMyAssignments(Course *);
    void giveScore(Course *);
    int getCourseScore(Course *) const;
    void setCourseScore(Course *);
    void changeStudentInfo(void);
    struct ENROLLED_COURSES *getCourses(void);
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
Student *findStudent(string myStu);
void showStudentMenu(void);
void deleteStudent(void);
void showStudentInfo(void);
void restoreStudent(void);

#endif