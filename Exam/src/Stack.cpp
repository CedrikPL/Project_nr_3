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

NumberStack* generateUniqueNumber(int n)
{

    NumberStack *root = NULL, *tempW=NULL;

    int i = 0;
    int r;
    bool isUnique = true;
    while(i < n)
    {
        r = ( rand() % 50 ) + 1;
        tempW = root; // save current stack pointer;
        while(root) // until root = NULL
        {
            int tmp = popStack(&root);
            if(r == tmp){
                isUnique = false;
                break;
            }
        }
        root = tempW; // return to top stack pointer

        if(isUnique){
            pushStack(&root, r);
            i++;
        }else{
            isUnique = true;
        }
    }

   // clearStack(&root);
    return root;
}
