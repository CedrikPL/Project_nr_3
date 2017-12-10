#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <locale>

#include "main.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "User.h"

using namespace std;

std::string castToPL( string * text );

void generateQuestionbinaryFile(const char* fileDir);

string toLowerCase(string text);

bool isUserNULL(User u);

bool isQuestionFileExist(const char* file);

void examConfirm();

void waitKey();

#endif
