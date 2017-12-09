#include "main.h"

int main()
{
    srand( time(0));

    NumberStack *root = generateUniqueNumber(QUESTION_IN_FILE);
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

   // generateQuestionbinaryFile("res/test.txt");

  // displayQuestion(readQuestionFromFile(QuestionFileName, 1));


//        displayQuestion(readQuestionFromFile(QuestionFileName , 28));

    return 0;
}
