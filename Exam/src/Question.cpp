#include "Question.h"


Question readQuestionFromFile(const char* fileDir, int questionOffset)
{
    Question q;

    if(questionOffset >=1)
    {
        questionOffset *= sizeof(q.questionText) + (3 * sizeof(q.qA[0].answer)) + sizeof(q.correctAnswer);
    }

    ifstream myfile(fileDir,  ios::binary);
    myfile.seekg(questionOffset);

    myfile.read(q.questionText, sizeof(q.questionText));
    for(int j = 0 ; j < 3; j++)
    {
        myfile.read(q.qA[j].answer, sizeof(q.qA[j].answer));
    }
    myfile.read(reinterpret_cast<char *>(&q.correctAnswer), sizeof(q.correctAnswer));

    myfile.close();

    return q;
}

void displayQuestion(Question q)
{

    cout << q.questionText << endl;
    for(int j = 0 ; j < 3; j++)
    {
        cout << q.qA[j].answer<<endl;
    }
    cout << q.correctAnswer << endl;


}
