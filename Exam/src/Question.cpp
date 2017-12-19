#include "Question.h"

Question readQuestionFromFile(const char* fileDir, int questionIndex)
{
    Question q;
    int offsetInFile, stringSize = 0;;

    ifstream myfile(fileDir, ios::in | ios::binary);
    if(myfile.is_open())
    {
        //oblicz index offsetu w tabeli metadata na podstawie indexu
        myfile.seekg((questionIndex * (sizeof(int))),ios::beg);

        myfile.read((char*)(&offsetInFile), sizeof(offsetInFile)); //wczytaj offset pytania

        //wykonak skok do odpowiedniego pytania
        myfile.seekg(offsetInFile,ios::beg);
        //wczytaj ilosc znakow
        myfile.read((char*)(&stringSize), sizeof(stringSize));

        //stworz tablice char i wczytaj do niej dane
        char buff[stringSize];
        myfile.read((char*)(buff), sizeof(buff));

        //ustal znak  NULL(Konca linii)
        buff[stringSize] = '\0';
        string s(buff);
        q.questionText = s;

        //wszytywanie odpowiedzi
        for(int i = 0 ; i < 3; i++)
        {
            stringSize = 0;
             //wczytaj ilosc znakow
            myfile.read((char*)(&stringSize), sizeof(stringSize));

             //stworz tablice char i wczytaj do niej dane
            char b[stringSize];
            myfile.read((char*)(&b), sizeof(b));

            //ustal znak  NULL(Konca linii)
            b[stringSize] = '\0';
            string s(b);
            q.questionAnswers[i] = s;
        }

        //wczytywanie poprawnej odpowiedzi
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
