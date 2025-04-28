#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

#include <iostream>
#include <fstream>
#include "student.h"
#include "master.h"

using namespace std;

void openFiles(void);
void readStudentList(ifstream &studentFile);
void readMasterList(ifstream &masterFile);
void readCourseList(ifstream &courseFile);
void submitInformation(void);

#endif