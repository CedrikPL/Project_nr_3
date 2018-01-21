#ifndef Stack_H_INCLUDED
#define Stack_H_INCLUDED

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

const int QUESTION_IN_FILE = 100;

struct NumberStack{
    int number;
    NumberStack *next;
};

//dodaj element do stosu (root)
void pushStack(NumberStack **root, int wartosc);

//zdejmij element ze stosu (root)
int popStack(NumberStack **root);

void clearStack(NumberStack **root);

NumberStack* generateUniqueNumber(int n);

#endif
