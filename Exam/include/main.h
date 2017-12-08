#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include "utilities.h"
#include "UI.h"
#include "Stack.h"

/*Napisz program, kt�ry umo�liwi przeprowadzenie testu wyboru z �J�zyka angielskiego�.
 Pytania i odpowiedzi podane s� w pliku binarnym. W te�cie jest 20 pyta� losowanych z puli 100 pyta�.
 U�ytkownik po wykonaniu tekstu uzyskuje informacje o liczbie zdobytych punkt�w i poprawno�ci udzielanych odpowiedzi.
 Wyniki kolejnych u�ytkownik�w s� zapisywane w pliku. Podaj rozwi�zanie bez tablic pomocniczych.
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
