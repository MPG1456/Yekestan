#include "submission.h"

Submission::Submission(Assignment *Assignment, Student *student) : assignment(assignment), student(student)
{
    score = 0;
    respond = "No Respond Has Given Yet!";
}

void Submission::setRespond()
{
    string newRespond;
    cout << "Please Enter Your Respond: ";
    getline(cin, newRespond);
    this->respond = newRespond;
}

string Submission::getRespond(void) const
{
    return respond;
}

float Submission::getScore(void) const
{
    return score;
}

int Submission::getCourseId(void) const
{
    return assignment->getCourseId();
}

Student *Submission::getStu(void) const
{
    return student;
}

