#ifndef MASTER_H
#define MASTER_H

#include "person.h"
#include "course.h"
#include "assignment.h"
#include "submission.h"

using namespace std;

class Master : public Person
{
    bool active;
    bool available;

public:
    Master();
    Master(string username, string password, string firstName, string lastName, bool available, bool gender, bool active);
    bool isActive(void) const;
    void showMasterCourses(void);
    void changeMasterInfo(void);
    void setActive(bool activeStatus);
};

struct MASTER_LIST
{
    Master *master;
    struct MASTER_LIST *mNext;
};

extern MASTER_LIST *mHead;

struct MASTER_LIST *createNewMaster();
void masterOperation(struct MASTER_LIST *);
struct MASTER_LIST *findMaster(void);
Master *findMaster(string myMaster);
void showMasterMenu(void);
void addNewAssignment(Master *);
void deleteMaster(void);
void showMasterInfo(void);
void restoreMaster(void);

#endif