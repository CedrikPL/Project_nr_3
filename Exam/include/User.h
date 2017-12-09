#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>

using namespace std;

const char UserFileName[] = "res/User.ed";

const char undefinedUser = '~';

const int QuestionInExam = 20;

struct Date{
    int d,mm,rrrr;
};

struct Exam{
    Date examDate;
    int totalScore;
};

struct User{
    string userName;
    int examCnt;
};

User login(string userName);

User createUser(string userName);

#endif
