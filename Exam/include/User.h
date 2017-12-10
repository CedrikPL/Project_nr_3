#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

const char UserFileName[] = "res/User.ed";

const char undefinedUser = '~';

struct User{
    string userName;
    string lastExamID;
    int examCnt;
    int topScore;
};

User createUser(string userName);

User userExist(string userName);

void updateUser(User user);

#endif
