#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

const char QuestionFileName[] = "res/Questions.pq";

struct Question{
    string questionText;
    string questionAnswers[3];
    char correctAnswer;
};

Question readQuestionFromFile(const char* fileDir, int questionIndex);

void displayQuestion(Question q);

#endif // QUESTION_H_INCLUDED
