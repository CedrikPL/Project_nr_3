#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

struct questionAnswers{
    char answer[20];
};

struct Question{
    char questionText[80];
    questionAnswers qA[3];
    unsigned short correctAnswer;
};

Question readQuestionFromFile(const char* fileDir, int questionOffset);

void displayQuestion(Question q);

#endif // QUESTION_H_INCLUDED
