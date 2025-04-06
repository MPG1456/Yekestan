#include "student.h"

STUDENT_LIST *sHead = nullptr;

Student::Student()
{
    cout << "New Student Added" << endl;
}

struct STUDENT_LIST *createNewStudent(void)
{
    struct STUDENT_LIST *sNew = new struct STUDENT_LIST;
    
    if(sHead == nullptr)
        sHead = sNew;
    else
    {
        struct STUDENT_LIST *sTemp = sHead;
        while(sTemp->sNext)
            sTemp = sTemp->sNext;
        sTemp->sNext = sNew;
    }
    return sNew;
}