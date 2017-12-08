#include "main.h"

int main()
{
    srand( time(0));

    displayQuestion(readQuestionFromFile(0));

    return 0;
}

Question readQuestionFromFile(int questionOffset)
{
    Question q;

    if(questionOffset >=1)
    {
        questionOffset *= sizeof(q.questionText) + (3 * sizeof(q.qA[0].answer)) + sizeof(q.correctAnswer);
    }

    ifstream myfile(QuestionFileName,  ios::binary);
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

NumberStack* generateUniqueNumber(int n)
{

    NumberStack *root = NULL, *tempW=NULL;

    int i = 0;
    bool isUnique = true;
    while(i < n)
    {
        int r = ( rand() % 100 ) + 1;
        tempW = root; // save current stack pointer;
        while(root) // until root = NULL
        {
            int tmp = popStack(&root);
            if(r == tmp){
                isUnique = false;
                break;
            }
        }
        root = tempW; // return to top stack pointer

        if(isUnique){
            pushStack(&root, r);
            i++;
        }else{
            isUnique = true;
        }
    }

   // clearStack(&root);
    return root;
}
