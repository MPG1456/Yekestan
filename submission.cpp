#include "submission.h"

Submission::Submission(Student *student) : student(student)
{
    score = -1;
    respond = "No Respond Has Given Yet!";
}

Submission::Submission(Student *myStu, string respond, float score) : student(myStu), respond(respond), score(score)
{}

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

Student *Submission::getStu(void) const
{
    return student;
}

