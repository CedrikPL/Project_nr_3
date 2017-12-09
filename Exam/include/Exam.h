#ifndef EAXM_H_INCLUDED
#define EAXM_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

const char ExamFileName[] = "res/Exam.ex";

const int QuestionInExam = 20;

struct Date{
    int d,mm,rrrr;
};

struct Exam{
    Date examDate;
    int totalScore;
    string examID;
    string nextExamID;
};

void saveExam(Exam exam);

Exam loadExam(string examID);

#endif
