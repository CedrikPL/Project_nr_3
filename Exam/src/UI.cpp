#include "UI.h"


void mainScreen()
{

    char s;
    do
    {
        system("cls");
        cout << "Welcome to the English language exam program!\nChoose one of the options below to start.\n\n1 - Login; 2 - Create user; 4 -DEBUG TEST; 3 - Exit\nSelect option: ";
        cin.sync();
        s = getchar();

        switch(s)
        {
        case '1':
            loginStage();
            break;
        case '2':
            createUserStage();
            break;
        case '3':
            break;
        case '4':
            examStage();
            break;
        default:
            cout << "Incorrect value!\n";
        }

    }
    while(s != '3');
}

void loginStage()
{

    system("cls");
    string userName;
    cout << "To start using program, type your username for which you want to take the exam.\nEnter your username: ";
    cin.sync();
    getline(cin, userName);

    User user = login(userName);
    if(user.userName.at(0) == undefinedUser)
    {

    }


}

void  createUserStage()
{

}

void examStage()
{
    NumberStack *root = generateUniqueNumber( QuestionInExam );
    NumberStack *tempRoot;
    tempRoot = root;

    Question question;

    int idx = 0, finalScore = 0, badQuestion = 0;
    for(; idx < QuestionInExam; idx++ )
    {
        question = readQuestionFromFile(QuestionFileName, popStack(&root));

        string answer;
        bool goToNext = false;

        system("cls");
        cout << "Question number " << (idx+1)<<"/"<<QuestionInExam <<"\n";

        displayQuestion(question);

        if( idx < 2 )
        {
            cout << "TIP: If you do not know how to use this program, type 'help' in to the answer to get more information!\n";
        }

        do
        {
            cout << "Your answer: ";
            cin.sync();
            getline(cin, answer);
            answer = toLowerCase(answer);

            if(answer.at(0) == 'a' || answer.at(0) == 'b' || answer.at(0) == 'c')
            {
                goToNext = true;
            }
            else if(!answer.compare("exit"))
            {
                idx = QuestionInExam;
                break;
            }
            else if(!answer.compare("help"))
            {
                cout << "1) Type letter 'a' if you want choose answer a) and letter `b` if answer b).\n2) If you want to exit current exam and lose your score type 'exit' in to answer\n";
            }
            else
            {
                cout << "Incorrect answer! Type 'help' for more information!\n";
            }

            if(goToNext){
                if(answer.at(0) != question.correctAnswer)
                    badQuestion++;
            }

        }
        while( !goToNext );
    }

    finalScore = QuestionInExam - badQuestion;

    root = tempRoot;

    clearStack(&root);
}

