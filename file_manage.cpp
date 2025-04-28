#include "file_manage.h"

void openFiles(void)
{
    ifstream readFile;
    ofstream writeFile;

    readFile.open("student.txt");
    if (readFile.is_open() == false)
    {
        writeFile.open("student.txt");
        if (writeFile.is_open() == false)
        {
            cout << "Error While Opening Files!" << endl;
            cout << "Closing The Program... " << endl;
            exit(0);
        }
        writeFile.close();
    }
    else
    {
        readStudentList(readFile);
        readFile.close();
    }

    readFile.open("master.txt");
    if (readFile.is_open() == false)
    {
        writeFile.open("master.txt");
        if (writeFile.is_open() == false)
        {
            cout << "Error While Opening Files!" << endl;
            cout << "Closing The Program... " << endl;
            exit(0);
        }
    }
    else
    {
        readMasterList(readFile);
        readFile.close();
    }

    readFile.open("course.txt");
    if (readFile.is_open() == false)
    {
        writeFile.open("course.txt");
        if (writeFile.is_open() == false)
        {
            cout << "Error While Opening Files!" << endl;
            cout << "Closing The Program... " << endl;
            exit(0);
        }
    }
    else
    {
        readCourseList(readFile);
        readFile.close();
    }
}

void readStudentList(ifstream &studentFile)
{
    STUDENT_LIST *sNew;
    string line, username, password, firstName, lastName, available, gender, GPA, score;
    int availableNum, genderNum, GPANum;
    float scores[10];
    while (getline(studentFile, line))
    {
        if (sHead == nullptr)
        {
            sHead = new STUDENT_LIST;
            sNew = sHead;
            sHead->sNext = nullptr;
        }
        else
        {
            sNew->sNext = new STUDENT_LIST;
            sNew = sNew->sNext;
            sNew->sNext = nullptr;
        }

        username = line;
        getline(studentFile, password);
        getline(studentFile, firstName);
        getline(studentFile, lastName);
        getline(studentFile, available);
        getline(studentFile, gender);
        getline(studentFile, GPA);
        for (int i = 0; i < 10; ++i)
        {
            getline(studentFile, score);
            scores[i] = stof(score);
        }
        availableNum = stoi(available);
        genderNum = stoi(gender);
        GPANum = stoi(GPA);

        sNew->student = new Student(username, password, firstName, lastName, availableNum, genderNum, GPANum, scores);
    }
    cout << "Student File Read Completely :-)" << endl;
}

void readMasterList(ifstream &masterFile)
{
    MASTER_LIST *mNew;
    string line, username, password, firstName, lastName, gender, active, available;
    int genderNum, activeNum, availableNum;
    while (getline(masterFile, line))
    {
        if (mHead == nullptr)
        {
            mHead = new MASTER_LIST;
            mNew = mHead;
            mHead->mNext = nullptr;
        }
        else
        {
            mNew->mNext = new MASTER_LIST;
            mNew = mNew->mNext;
            mNew->mNext = nullptr;
        }

        username = line;
        getline(masterFile, password);
        getline(masterFile, firstName);
        getline(masterFile, lastName);
        getline(masterFile, gender);
        getline(masterFile, active);
        getline(masterFile, available);
        genderNum = stoi(available);
        activeNum = stoi(active);
        availableNum = stoi(available);

        mNew->master = new Master(username, password, firstName, lastName, availableNum, genderNum, activeNum);
    }
    cout << "Master File Read Completely :-)" << endl;
}

void readCourseList(ifstream &courseFile)
{
    MASTER_LIST *mTemp;
    STUDENT_LIST *sTemp;
    COURSE_LIST *cNew;
    string line, name, score, capacity, remainedCapacity, masterNmae, stuList;
    int idNum, capacityNum, remainedCapacityNum;
    float scoreNum;
    while (getline(courseFile, line))
    {
        if (cHead == nullptr)
        {
            cHead = new COURSE_LIST;
            cNew = cHead;
            cHead->cNext = nullptr;
        }
        else
        {
            cNew->cNext = new COURSE_LIST;
            cNew = cNew->cNext;
            cNew->cNext = nullptr;
        }
        idNum = stoi(line);
    }
}

void submitInformation(void)
{
    ofstream studentFile("student.txt", ios::trunc), masterFile("master.txt", ios::trunc);
    ofstream courseFile("course.txt", ios::trunc);
    struct STUDENT_LIST *sTemp = sHead;
    struct MASTER_LIST *mTemp = mHead;
    struct ENROLLED_COURSES *myCourses;
    struct COURSE_LIST *cTemp = cHead;
    Student **tempStu;
    Assignment **tempAssign;
    Submission **tempSub;

    while (cHead)
    {
        courseFile << cTemp->course->getId() << endl;
        courseFile << cTemp->course->getCourseName() << endl;
        courseFile << cTemp->course->getScore() << endl;
        courseFile << cTemp->course->getCapacity() << endl;
        courseFile << cTemp->course->getRemainedCapacity() << endl;
        courseFile << cTemp->course->getMasterName() << endl;

        tempStu = cTemp->course->getStuList();
        for (int i = 0; i < 50; ++i)
        {
            if (tempStu[i] != nullptr)
                courseFile << tempStu[i]->getFullName() << endl;
            else
                courseFile << "#" << endl;
        }

        tempAssign = cTemp->course->getAssignmentList();
        for(int i = 0; i < 10; ++i)
            if(tempAssign[i] != nullptr)
            {
                courseFile << tempAssign[i]->getTitle() << endl;
                courseFile << tempAssign[i]->getDescription() << endl;
                courseFile << tempAssign[i]->getIsActive() << endl;
                
                tempSub = tempAssign[i]->getSubList();
                for(int j = 0; j < 50; ++i)
                    if(tempSub[j] != nullptr)
                    {
                        courseFile << tempSub[j]->getStu()->getFullName() << endl;
                        courseFile << tempSub[j]->getRespond() << endl;
                        courseFile << tempSub[j]->getScore() << endl;
                        delete[] tempSub[j];
                    }
                    else
                    {
                        courseFile << "#" << endl;
                        courseFile << "#" << endl;
                        courseFile << "#" << endl;
                    }
                delete[] tempAssign[i];
            }
            else
                courseFile << "#" << endl;

        cTemp = cTemp->cNext;
        delete cHead->course;
        delete cHead;
        cHead = cTemp;
    }
    courseFile.close();

    while (sHead)
    {
        studentFile << sTemp->student->getUsername() << endl;
        studentFile << sTemp->student->getPassword() << endl;
        studentFile << sTemp->student->getFirstName() << endl;
        studentFile << sTemp->student->getLastName() << endl;
        studentFile << sTemp->student->isAvailable() << endl;
        studentFile << sTemp->student->getGender() << endl;
        studentFile << sTemp->student->getGPA() << endl;

        myCourses = sTemp->student->getCourses();
        for (int i = 0; i < 10; ++i)
            studentFile << myCourses[i].score << endl;

        sTemp = sTemp->sNext;
        delete sHead->student;
        delete sHead;
        sHead = sTemp;
    }
    studentFile.close();

    while (mHead)
    {
        masterFile << mTemp->master->getUsername() << endl;
        masterFile << mTemp->master->getPassword() << endl;
        masterFile << mTemp->master->getFirstName() << endl;
        masterFile << mTemp->master->getLastName() << endl;
        masterFile << mTemp->master->isAvailable() << endl;
        masterFile << mTemp->master->getGender() << endl;
        masterFile << mTemp->master->isActive() << endl;

        mTemp = mTemp->mNext;
        delete mHead->master;
        delete mHead;
        mHead = mTemp;
    }
    masterFile.close();
}
