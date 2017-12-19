#include "main.h"

#define genFile 0

int main()
{
    srand( time(0));

    #if genFile == 0
    if(isQuestionFileExist(QuestionFileName)){
        mainScreen();
    }else{
        cout << "Fatal error! Question file don't exist!";
    }a
    #else

    generateQuestionbinaryFile("res/qsrc.txt");

   /*Question q[QUESTION_IN_FILE];

    for(int i = 0; i < QUESTION_IN_FILE; i++)
       q[i] = readQuestionFromFile(QuestionFileName, i);

     for(int i = 0; i < QUESTION_IN_FILE; i++)
        displayQuestion(q[i]);*/


    #endif
    return 0;
}
