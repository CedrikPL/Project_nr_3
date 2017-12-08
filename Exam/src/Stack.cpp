#include "Stack.h"

void pushStack(NumberStack **root, int wartosc)
{
    NumberStack *nowa= new NumberStack;
    nowa->number = wartosc;
    nowa->next=*root;
    *root=nowa;
}

int popStack(NumberStack **root)
{
    NumberStack *temp=*root;
    *root=(*root)->next;
    return temp->number;
    // delete temp;
}

void clearStack(NumberStack **root)
{
    while(*root)  //sprawdz czy stos nie jest juz pusty
    {
        NumberStack *temp=*root;
        *root=(*root)->next;
        delete temp;
    }
}
