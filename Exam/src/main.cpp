#include "main.h"

int main()
{
    srand( time(0));

    if(isQuestionFileExist(QuestionFileName)){
        mainScreen();
    }else{
        cout << "Fatal error! Question file don't exist!";
    }

    return 0;
}
