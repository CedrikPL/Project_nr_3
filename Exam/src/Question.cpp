#include "Question.h"

Question readQuestionFromFile(const char* fileDir, int questionIndex)
{
    Question q;

    ifstream myfile(fileDir, ios::in | ios::binary);
    string line;
    int questionCurrIdx;
    char z;
    char temp[3] = {0};
    int tempIdx = 0, currline = 0;
    while(getline (myfile,line))
    {
        currline++;
        if(currline == 1)
        {
            while((z = line.at(tempIdx)))
            {
                if(z >= 48 && z <= 57)
                {
                    temp[tempIdx] = z;
                    tempIdx++;
                }
                else
                    break;
            }

            questionCurrIdx = atoi(temp);

            if(questionCurrIdx == questionIndex)
            {
                //load question
                q.questionText = line;
                for(int j = 0 ; j < 3; j++)
                {
                    getline (myfile,line);
                    q.questionAnswers[j] = line;
                }
                getline (myfile,line);
                q.correctAnswer = line.at(0);
                break;
            }

            tempIdx = 0;
        }

        if(currline == 5)
        {
            currline = 0;
        }
    }

    myfile.close();

    return q;
}

void displayQuestion(Question q)
{
    cout << q.questionText<<"\n";
    for(int i = 0 ; i < 3; i++)
    {
        cout << q.questionAnswers[i] << "\n";
    }
    cout << q.correctAnswer << "\n";
}
