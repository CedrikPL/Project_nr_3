#include "main.h"

#define genFile 1

int main()
{
    srand( time(0));

    #ifndef genFile
    if(isQuestionFileExist(QuestionFileName)){
        mainScreen();
    }else{
        cout << "Fatal error! Question file don't exist!";
    }
    #else

    generateQuestionbinaryFile("res/qsrc.txt");

    #endif
    return 0;
}
