#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "main.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

using namespace std;

std::string castToPL( string * text );

void generateQuestionbinaryFile(const char* fileDir);

#endif
