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
}

void readStudentList(ifstream &studentFile)
{
    STUDENT_LIST *sNew;
    string line, username, password, firstName, lastName, gender, GPA;
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
        getline(studentFile, gender);
        getline(studentFile, GPA);
        if (gender[0] == '1')
            sNew->student = new Student(username, password, firstName, lastName, 1, stof(GPA));
        else
            sNew->student = new Student(username, password, firstName, lastName, 0, stof(GPA));
    }
    cout << "Student File Read Completely :-)" << endl;
}

void readMasterList(ifstream &masterFile)
{
    MASTER_LIST *mNew;
    string line, username, password, firstName, lastName, gender, active;
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
        if (gender[0] == '1')
            if (active[0] == '1')
                mNew->master = new Master(username, password, firstName, lastName, 1, 1);
            else
                mNew->master = new Master(username, password, firstName, lastName, 1, 0);

        else if (active[0] == '1')
            mNew->master = new Master(username, password, firstName, lastName, 0, 1);
        else
            mNew->master = new Master(username, password, firstName, lastName, 0, 0);
    }
    cout << "Master File Read Completely :-)" << endl;
}

void submitInformation(void)
{
    ofstream studentFile("student.txt", ios::trunc), masterFile("master.txt", ios::trunc);
    STUDENT_LIST *sTemp = sHead;
    MASTER_LIST *mTemp = mHead;
    while (sHead)
    {
        studentFile << sTemp->student->getUsername() << endl;
        studentFile << sTemp->student->getPassword() << endl;
        studentFile << sTemp->student->getFirstName() << endl;
        studentFile << sTemp->student->getLastName() << endl;
        studentFile << sTemp->student->getGender() << endl;
        studentFile << sTemp->student->getGPA() << endl;
        sTemp = sTemp->sNext;
        delete sHead->student;
        delete sHead;
        sHead = sTemp;
    }

    while (mHead)
    {
        masterFile << mTemp->master->getUsername() << endl;
        masterFile << mTemp->master->getPassword() << endl;
        masterFile << mTemp->master->getFirstName() << endl;
        masterFile << mTemp->master->getLastName() << endl;
        masterFile << mTemp->master->getGender() << endl;
        masterFile << mTemp->master->isActive() << endl;
        mTemp = mTemp->mNext;
        delete mHead->master;
        delete mHead;
        mHead = mTemp;
    }
    masterFile.close();
    studentFile.close();
}
