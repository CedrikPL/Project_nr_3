#include "Question.h"

Question readQuestionFromFile(const char* fileDir, int questionIndex)
{
    Question q;

    ifstream myfile(fileDir, ios::in | ios::binary);
    if(myfile.is_open())
    {
        //oblicz index offsetu w tabeli metadata na podstawie indexu
        myfile.seekg((questionIndex * (sizeof(int))),ios::beg);
        int offset;
        myfile.read((char*)(&offset), sizeof(offset)); //wczytaj offset pytania


        myfile.seekg(offset,ios::beg);

        int stringSize = 0;
        myfile.read((char*)(&stringSize), sizeof(stringSize));



        char buff[stringSize] = {0};
        myfile.read((char*)(buff), sizeof(buff));
        buff[stringSize] = '\0';
        string s(buff);
        q.questionText = s;
        for(int i = 0 ; i < 3; i++)
        {
            stringSize = 0;
            myfile.read((char*)(&stringSize), sizeof(stringSize));



            char b[stringSize]  = {0};;
            myfile.read((char*)(&b), sizeof(b));
            b[stringSize] = '\0';
            string s(b);
            q.questionAnswers[i] = s;

        }

        myfile.read((char*)(&q.correctAnswer), sizeof(q.correctAnswer));

    }
    else cout << "\nWarning!: Data corruption occurred in "<<QuestionFileName<<" file. All question data lost!\n";
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
    cout << "\n";
}
