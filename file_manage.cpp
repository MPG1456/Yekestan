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
    string line, username, password, firstName, lastName, gender;
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
        if (gender[0] == '1')
            sNew->student = new Student(username, password, firstName, lastName, 1);
        else
            sNew->student = new Student(username, password, firstName, lastName, 0);
    }
    cout << "Student File Read Completely :-)" << endl;
}
