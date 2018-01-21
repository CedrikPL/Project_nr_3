#include "utilities.h"

void generateQuestionbinaryFile(const char* fileDir)
{
    Question q;
    /*
        i - index linii
        stringSize - dlugos lancucha znakow do zapisu
        currentQ - obecnie przetwzrazne pytanie
        soSQT, sQT, soQA,sQA, sCA - zmienne pomocnicze zawierajace wielkosc danych w baitach.Nazwa pochodzi od skrotu wartosci ktora reperezentuje. Wymagane przy obliczaniu offsetu w pliku.
        currentSize - obecny rozmiar pytania w baitach
        finalMetadataSize - finalny offset pytania zapisywany w tablicy metadata.
        matadataPos - pozycja elemntu w tablicy metadata
        writedDataSize - ilosc zapisanych baitow do pliku
    */
    int i = 0, stringSize, currentQ = 0, soSQT, sQT, soQA,sQA, sCA, currentSize=0, finalMetadataSize, matadataPos = 0, writedDataSize = 0;
    string line;
    ifstream myfile(fileDir);
    ofstream of;
    of.open (QuestionFileName, ios::out| ios::binary);
    if (myfile.is_open())
    {
        //prepare question file;
        int buff = 0;
        for(int g = 0 ; g < QUESTION_IN_FILE; g++)
        {
            writedDataSize = writedDataSize+sizeof(buff);
            of.write((char*)(&buff), sizeof(buff));
        }

        while ( getline (myfile,line) )
        {
            i++;
            switch(i)
            {
            case 1:
                q.questionText = line;
                break;
            case 2:
                q.questionAnswers[0] = line;
                break;
            case 3:
                q.questionAnswers[1] = line;
                break;
            case 4:
                q.questionAnswers[2] = line;
                break;
            case 5:
                switch(line.at(0))
                {
                case '1':
                    q.correctAnswer = 'a';
                    break;
                case '2':
                    q.correctAnswer = 'b';
                    break;
                case '3':
                    q.correctAnswer = 'c';
                    break;
                }
                break;
            };
            if(i == 5)
            {
                 //wykonak skok do ostatnio zapisanego pytania
                of.seekp(writedDataSize, ios::beg);

                //zapisywanie wielkosci tesktu pytania  oraz pobieranie jego wielkosci w baitach
                stringSize = q.questionText.length();
                soSQT = sizeof(stringSize);
                writedDataSize = writedDataSize + soSQT;
                currentSize = currentSize + soSQT;
                of.write((char*)(&stringSize), soSQT);

                //zapisywanie tresci pytania oraz pobieranie jego wielkosci w baitach
                sQT = (stringSize*sizeof(char));
                writedDataSize = writedDataSize + sQT;
                currentSize = currentSize + sQT;
                of.write(q.questionText.c_str(), sQT);

                //zapisywanie tresci odpowedzi
                for(int j = 0; j < 3; j++)
                {
                    stringSize = q.questionAnswers[j].length();

                    //zapisywanie wielkosci odpowiedzi oraz pobieranie jego wielkosci w baitach
                    soQA = sizeof(stringSize);
                    writedDataSize = writedDataSize + soQA;
                    currentSize = currentSize + soQA;
                    of.write((char*)(&stringSize),soQA);

                    //zapisywanie odpowiedzi oraz pobieranie jego wielkosci w baitach
                    sQA = (stringSize*sizeof(char));
                    writedDataSize = writedDataSize + sQA;
                    currentSize = currentSize + sQA;
                    of.write(q.questionAnswers[j].c_str(), sQA);
                }

                //zapisywanie poprawnej odpowedzi oraz pobieranie jej wielkosci w baitach
                sCA = sizeof(q.correctAnswer);
                writedDataSize = writedDataSize + sCA;
                currentSize = currentSize + sCA;
                of.write(&q.correctAnswer, sCA);

                //obliczanie obecnej pozycji w tabeli metadata opardej o obecne pytanie
                matadataPos = currentQ * sizeof(currentQ);   //pozycja w meta tabeli;

                //obliczanie finalenej pozycji pytania w pliku
                finalMetadataSize = writedDataSize-currentSize;

                //zapis  finalenej pozycji pytania w taablicy metadata
                of.seekp(matadataPos, ios_base::beg);
                of.write((char *)(&finalMetadataSize), sizeof(writedDataSize));

                cout <<currentSize << " , " << matadataPos <<" , " << currentQ<< " , "<<writedDataSize << "\n"; //debug out

                i = 0;
                currentSize = 0;
                currentQ++;
            }
        }
        myfile.close();
        of.close();
    }
    else cout << "Unable to open file: "<<fileDir;
}

string toLowerCase(string text)
{
    unsigned int i = 0;
    char c;
    while ( i < text.length())
    {
        c=text.at(i);
        text.at(i) = (tolower(c));
        i++;
    }
    return text;
}

bool isUserNULL(User u)
{
    return u.userName.at(0) == undefinedUser ? true : false;
}

bool isQuestionFileExist(const char* file)
{
    ifstream myfile(file, ios::in | ios::binary);
    return myfile.is_open() ? true : false;
}

void examConfirm()
{
    char s;
    cin >> s;
    s = tolower(s);
    if( s == 'y')
    {
        cout << "Press 'Enter' to begin exam or 'Escape' to discard decision and go back to main menu!";
        do
        {
            s = getch();
            if(s == 13)
            {
                exam();
                break;
            }
        }
        while(s != 27);
    }


}

void waitKey()
{
    cout << "\nPress any key to continue...";
    getch();
}

string formatExamData(Exam exam)
{
    stringstream ss;
    ss << "At: " << exam.examDate.dd <<"/" << exam.examDate.mm << "/" << exam.examDate.rrrr << "-" << exam.examDate.h<<":"<<exam.examDate.m<<":"<<exam.examDate.h;
    string line;
    line = ss.str();
    return line;
}
