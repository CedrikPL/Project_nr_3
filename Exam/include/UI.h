#ifndef UI_H
#define UI_H

#include <conio.h>
#include <sstream>
#include <ctime>

#include "User.h"
#include "Question.h"
#include "Stack.h"
#include "utilities.h"
#include "Exam.h"

void mainScreen();

void loginStage();

void createUserStage();

void preExamStage();

void examDetaiStage();

void exam();

void logoutStage();

#endif // UI_H
