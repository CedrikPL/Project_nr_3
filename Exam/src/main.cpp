#include "main.h"

int main()
{
    srand( time(0));

    mainScreen();

   /* NumberStack *root = generateUniqueNumber(QUESTION_IN_FILE);
    NumberStack *w;

    w = root;

    Question q;
    int t;
    while(root){
        t = popStack(&root);
        cout << t <<"\n";
        q = readQuestionFromFile(QuestionFileName , t);

        displayQuestion(q);
    }

    root = w;

    clearStack(&root);
    */
    return 0;
}
