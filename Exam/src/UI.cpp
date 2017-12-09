#include "UI.h"

User currentUser;
string toUpperUsername;

void mainScreen()
{
    currentUser.userName = undefinedUser;

    char s;
    do
    {
        system("cls");

        if(currentUser.userName.at(0) != undefinedUser)
        {
            toUpperUsername = currentUser.userName;
            toUpperUsername.at(0) = toupper(toUpperUsername.at(0));
            cout << "Welcome " << toUpperUsername << "! into the English language exam program!\nChoose one of the options below to start.\n\n1 - logout; 2 - Exam; 3 - Detail; 4 - Exit\nSelect option: ";
            cin.sync();
            s = getchar();

            switch(s)
            {
            case '1':
                logoutStage();
                break;
            case '2':
                preExamStage();
                break;
            case '3':
                examDetaiStage();
                break;
            }
        }
        else
        {
            cout << "Welcome to the English language exam program!\nChoose one of the options below to start.\n\n1 - Login; 2 - Create user; 3 -Quick Exam; 4 - Exit\nSelect option: ";
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
                exam();
                break;
            }

        }


    }
    while(s != '4');
}

void exam(){

    NumberStack *root = generateUniqueNumber( QuestionInExam );
    NumberStack *tempRoot;
    tempRoot = root;

    Question question;
    Exam exam;

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
                idx = QuestionInExam+1;
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

    if(idx == QuestionInExam){
        system("cls");

        if(currentUser.topScore < finalScore){
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

        saveExam(exam);
        updateUser(currentUser);

        cout << "Congratulations! your final score is " << finalScore << "/" << QuestionInExam;
        cout << "\nPress any key to continue...";
        getch();
    }

    root = tempRoot;

    clearStack(&root);


}

void examDetaiStage(){




}

void preExamStage(){

    system("cls");
    cout << "Welcome " <<currentUser.userName << "! into exam part!\n";
    if(currentUser.examCnt == 0){
        cout << "You have not taken any exams yet! Do you want to do it now?(Y/N): ";
        char s;
        cin >> s;
        s = tolower(s);
        if( s == 'y')
        {
           cout << "Press 'Enter' to begin exam or 'Escape' to discard decision and go back to main menu!";
           do{
            s = getch();
            if(s == 13){
                exam();
                break;
            }
           }while(s != 27);
        }
    }else{
        cout << "You have already entered " << currentUser.examCnt << " exams and your best result is " << currentUser.topScore<< "/" <<QuestionInExam<< ".\n(To see more information about your exams go back to the main menu and select the 'Detail' sections)\n";
        cout << "Do you want to take the next exam? (Y/N): ";
        char s;
        cin >> s;
        s = tolower(s);
        if( s == 'y')
        {
           cout << "Press 'Enter' to begin exam or 'Escape' to discard decision and go back to main menu!";
           do{
            s = getch();
            if(s == 13){
                exam();
                break;
            }
           }while(s != 27);
        }
    }
}

void logoutStage(){
    User u;
    u.userName = undefinedUser;
    currentUser = u;

    cout << "Logout successfully!\nPress any key to continue...";
    getch();
}

void loginStage()
{
    system("cls");
    string userName;
    cout << "To start using program, type your 'username' for which you want to take the exam.\nEnter your username: ";
    cin.sync();
    getline(cin, userName);

    User user = userExist(userName);
    if(user.userName.at(0) == undefinedUser)
    {
        char s;
        cout << "User: " << userName << " don't exist! Do you want to create new user? (Y/N): ";
        cin >> s;
        s = tolower(s);
        if( s == 'y')
        {
            currentUser = createUser(userName);
            cout << "User " << userName << " created and auto login successfully!\n Press any key to continue...";
            getch();
        }
    }
    else
    {
        userName.at(0) = toupper(userName.at(0));
        cout << userName <<" user logged successfully!";
        currentUser = user;
        cout << "\n Press any key to continue...";
        getch();
    }
}

void  createUserStage()
{
    system("cls");
    string userName;
    cout << "To create user and start using program, type your 'username' for which you want to take the exam.\nEnter your username: ";
    cin.sync();
    getline(cin, userName);

    User user = userExist(userName);
    if(user.userName.at(0) == undefinedUser)
    {
        char s;
        cout << "User: " << userName << " don't exist! Do you want to create new user? (Y/N): ";
        cin >> s;
        s = tolower(s);
        if( s == 'y')
        {
            currentUser = createUser(userName);
            cout << "User " << userName << " created and auto login successfully!\n Press any key to continue...";
            getch();
        }
    }else{
        cout << "User: " << userName << " exist! You can't create user witch same 'username'!\n Press any key to continue...";
        getch();
    }
}
