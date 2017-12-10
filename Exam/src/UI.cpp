#include "UI.h"

User currentUser;
string toUpperUsername;

void mainScreen()
{
    currentUser.userName = undefinedUser;

    char s;
    bool isUserNull;
    do
    {
        isUserNull = isUserNULL(currentUser);

        system("cls");

        if(!isUserNull)
        {
            cout << "Welcome " << toUpperUsername << "! into the English language exam program!\nChoose one of the options below to start.\n\n1 - logout; 2 - Exam; 3 - Detail; 4 - Exit\nSelect option: ";
        }
        else
        {
            cout << "Welcome to the English language exam program!\nChoose one of the options below to start.\n\n1 - Login; 2 - Create user; 3 -Quick Exam; 4 - Exit\nSelect option: ";
        }
        cin.sync();
        s = getchar();
        switch(s)
        {
        case '1':
            isUserNull ? loginStage() : logoutStage();
            break;
        case '2':
            isUserNull ? createUserStage() : preExamStage();
            break;
        case '3':
            isUserNull ? exam() : examDetaiStage();
            break;
        }

    }
    while(s != '4');
}

void exam()
{
    bool isExit = false;

    NumberStack *root = generateUniqueNumber( QuestionInExam );
    NumberStack *tempRoot;
    tempRoot = root;

    Question question;
    Exam exam;

    //Time
    time_t timeNow = time(0);

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

            if(answer.length() == 0)
                continue;

            answer = toLowerCase(answer);

            if((answer.at(0) == 'a' || answer.at(0) == 'b' || answer.at(0) == 'c') && (answer.length() == 1))
            {
                goToNext = true;
            }
            else if(!answer.compare("exit"))
            {
                idx = QuestionInExam;
                isExit = true;
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

            if(goToNext)
            {
                if(answer.at(0) != question.correctAnswer)
                    badQuestion++;
            }

        }
        while( !goToNext );
    }
    finalScore = QuestionInExam - badQuestion;

    system("cls");
    if(!isExit)
    {
        if(!isUserNULL(currentUser))
        {

            if(currentUser.topScore < finalScore)
            {
                currentUser.topScore = finalScore;
            }

            exam.totalScore = finalScore;

            currentUser.examCnt++;

            stringstream ss;
            ss << currentUser.userName << "-" << currentUser.examCnt;

            exam.nextExamID = currentUser.lastExamID;

            string line;
            ss >> line;
            currentUser.lastExamID = line;
            exam.examID = line;

            tm *ltm = localtime(&timeNow);
            exam.examDate.s = (1 + ltm->tm_sec);
            exam.examDate.m = (1 + ltm->tm_min);
            exam.examDate.h = (1 + ltm->tm_hour);
            exam.examDate.dd = (ltm->tm_mday);
            exam.examDate.mm = (1 + ltm->tm_mon);
            exam.examDate.rrrr = (1900 + ltm->tm_year);

            saveExam(exam);
            updateUser(currentUser);

        }

        cout << "Congratulations! your final score is " << finalScore << "/" << QuestionInExam;

    }
    else
    {
        cout << "Exit";
    }

    root = tempRoot;

    clearStack(&root);

    if(isUserNULL(currentUser))
        waitKey();

}

void examDetaiStage()
{

    system("cls");

    Exam exam;
    string currStack = currentUser.lastExamID;
    for(int i = 0; i < currentUser.examCnt; i++)
    {
        exam = loadExam(currStack);

        if(exam.examID.at(0) == '~')
            break;
        else if(exam.examDate.rrrr == 0){
            cout << "\nWarning!: Data corruption occurred in "<<ExamFileName<<" file. Exam data lost!\n";
            break;
        }
        cout << "Exam: " << currentUser.examCnt - i << " score: " << exam.totalScore << "\nAt: " << exam.examDate.dd <<"/" << exam.examDate.mm << "/" << exam.examDate.rrrr << " , " << exam.examDate.h<<":"<<exam.examDate.m<<":"<<exam.examDate.h<<"\n";

        currStack = exam.nextExamID;
    }

    waitKey();

}

void preExamStage()
{

    system("cls");
    cout << "Welcome " << toUpperUsername << "! into exam part!\n";
    if(currentUser.examCnt == 0)
    {
        cout << "You have not taken any exams yet! Do you want to do it now?(Y/N): ";
        examConfirm();
    }
    else
    {
        cout << "You have already entered " << currentUser.examCnt << " exams and your best result is " << currentUser.topScore<< "/" <<QuestionInExam<< ".\n(To see more information about your exams go back to the main menu and select the 'Detail' sections)\n";
        cout << "Do you want to take the next exam?(Y/N): ";
        examConfirm();
    }

    waitKey();
}

void logoutStage()
{
    User u;
    u.userName = undefinedUser;
    currentUser = u;

    system("cls");

    cout << "Logout successfully!";
    waitKey();
}

void loginStage()
{
    system("cls");
    string userName;
    cout << "To start using program, type your 'username' for which you want to take the exam.\nEnter your username: ";
    cin.sync();
    getline(cin, userName);

    User user = userExist(userName);
    if(isUserNULL(user))
    {
        char s;
        cout << "User: " << userName << " don't exist! Do you want to create new user? (Y/N): ";
        cin >> s;
        s = tolower(s);
        if( s == 'y')
        {
            currentUser = createUser(userName);
            cout << "User " << userName << " created and auto login successfully!";
        }
    }
    else
    {
        currentUser = user;
        toUpperUsername = currentUser.userName;
        toUpperUsername.at(0) = toupper(toUpperUsername.at(0));
        cout << toUpperUsername <<" user logged successfully!";
    }
    waitKey();
}

void  createUserStage()
{
    system("cls");
    string userName;
    cout << "To create user and start using program, type your 'username' for which you want to take the exam.\nEnter your username: ";
    cin.sync();
    getline(cin, userName);

    User user = userExist(userName);
    if(isUserNULL(user))
    {
        char s;
        cout << "User: " << userName << " don't exist! Do you want to create new user? (Y/N): ";
        cin >> s;
        s = tolower(s);
        if( s == 'y')
        {
            currentUser = createUser(userName);
            cout << "User " << userName << " created and auto login successfully!";
        }
    }
    else
    {
        cout << "User: " << userName << " exist! You can't create user witch same 'username'!";
    }

    waitKey();
}
