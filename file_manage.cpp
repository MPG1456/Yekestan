#include "file_manage.h"

void openFiles(void)
{
    ifstream readFile;
    ofstream writeFile;

    readFile.open("student.txt");
    if(readFile.is_open() == false)
    {
        writeFile.open("student.txt");
        if(writeFile.is_open() == false)
        {
            cout << "Error While Opening Files!" << endl;
            cout << "Closing The Program... " << endl;
            exit(0);
        }
    }
    else
    {
        readStudentList();
        readFile.close();
    }

    readFile.open("master.txt");
    if(readFile.is_open() == false)
    {
        writeFile.open("master.txt");
        if(writeFile.is_open() == false)
        {
            cout << "Error While Opening Files!" << endl;
            cout << "Closing The Program... " << endl;
            exit(0);
        }
    }
    else
    {
        readMasterList();
        readFile.close();
    }
}