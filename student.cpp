#include "student.h"

STUDENT_LIST *pHead = nullptr;

Student::Student()
{
    cout << "New Student Added" << endl;
}

void createNewStudent()
{
    STUDENT_LIST *pNew = new STUDENT_LIST;
    
    if(pHead == nullptr)
        pHead = pNew;
    else
    {
        STUDENT_LIST *pTemp = pHead;
        while(pTemp->pNext)
            pTemp = pTemp->pNext;
        pTemp->pNext = pNew;
    }

}