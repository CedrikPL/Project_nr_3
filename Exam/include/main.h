#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "UI.h"
#include "Stack.h"

/*Napisz program, który umo¿liwi przeprowadzenie testu wyboru z „Jêzyka angielskiego”.
 Pytania i odpowiedzi podane s¹ w pliku binarnym. W teœcie jest 20 pytañ losowanych z puli 100 pytañ.
 U¿ytkownik po wykonaniu tekstu uzyskuje informacje o liczbie zdobytych punktów i poprawnoœci udzielanych odpowiedzi.
 Wyniki kolejnych u¿ytkowników s¹ zapisywane w pliku. Podaj rozwi¹zanie bez tablic pomocniczych.
*/

using namespace std;

const char QuestionFileName[] = "res/Questions.pq";
const char UserFileName[] = "res/User.ed";
const char TempFileName[] = "pq.tmp";

struct questionAnswers{
    char answer[20];
};

struct Question{
    char questionText[80];
    questionAnswers qA[3];
    unsigned short correctAnswer;
};

struct Date{
    int d,mm,rrrr;
};

struct Exam{
    Date examDate;
    int totalScore;
};

struct User{
    char userName[30];
    int examCnt;
};

Question readQuestionFromFile(int questionOffset);

void displayQuestion(Question q);

NumberStack* generateUniqueNumber(int n);

int main();

#endif
