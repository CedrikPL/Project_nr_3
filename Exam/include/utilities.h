#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <sstream>
#include "User.h"
#include "Exam.h"
#include "Stack.h"

using namespace std;

void generateQuestionbinaryFile(const char* fileDir);

string toLowerCase(string text);

string formatExamData(Exam exam);

bool isUserNULL(User u);

bool isQuestionFileExist(const char* file);

void examConfirm();

void waitKey();

#endif
