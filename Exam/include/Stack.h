#ifndef Stack_H_INCLUDED
#define Stack_H_INCLUDED

#include <iostream>

using namespace std;

struct NumberStack{
    int number;
    NumberStack *next;
};

//dodaj element do stosu (root)
void pushStack(NumberStack **root, int wartosc);

//zdejmij element ze stosu (root)
int popStack(NumberStack **root);

void clearStack(NumberStack **root);
#endif
