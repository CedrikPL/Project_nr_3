#include "utilities.h"

std::string castToPL( string * text )
{
    std::string result;
    char z;
    unsigned int i;
    for(i = 0; i < text->size(); i++)
    {
        z = text->at(i);
        switch( z )
        {
        case 'π':
            result += static_cast < char >( 0xa5 );
            break;
        case 'Ê':
            result += static_cast < char >( 0x86 );
            break;
        case 'Í':
            result += static_cast < char >( 0xa9 );
            break;
        case '≥':
            result += static_cast < char >( 0x88 );
            break;
        case 'Ò':
            result += static_cast < char >( 0xe4 );
            break;
        case 'Û':
            result += static_cast < char >( 0xa2 );
            break;
        case 'ú':
            result += static_cast < char >( 0x98 );
            break;
        case 'ø':
            result += static_cast < char >( 0xbe );
            break;
        case 'ü':
            result += static_cast < char >( 0xab );
            break;
        case '•':
            result += static_cast < char >( 0xa4 );
            break;
        case '∆':
            result += static_cast < char >( 0x8f );
            break;
        case ' ':
            result += static_cast < char >( 0xa8 );
            break;
        case '£':
            result += static_cast < char >( 0x9d );
            break;
        case '—':
            result += static_cast < char >( 0xe3 );
            break;
        case '”':
            result += static_cast < char >( 0xe0 );
            break;
        case 'å':
            result += static_cast < char >( 0x97 );
            break;
        case 'Ø':
            result += static_cast < char >( 0xbd );
            break;
        case 'è':
            result += static_cast < char >( 0x8d );
            break;
        default:
            result += z;
            break;
        }
    }

    return result;
}


void generateQuestionbinaryFile(const char* fileDir)
{

    Question q;
    int i = 0;
    string line;
    ifstream myfile(fileDir);
    ofstream of;
    of.open (QuestionFileName, ios::out | ios::app | ios::binary);
    if (myfile.is_open())
    {
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
                q.correctAnswer = line.at(0);
                break;
            };
            if(i == 5)
            {

                of << q.questionText << "\n";
                for(int j = 0; j < 3; j++)
                {
                    of << q.questionAnswers[j] << "\n";
                }
                of << q.correctAnswer<<"\n";

                i = 0;
            }
        }
        myfile.close();
        of.close();
    }
    else cout << "Unable to open file: "<<fileDir;
}

string toLowerCase(string text)
{
    int i = 0;
    char c;
    while ( i < text.length())
    {
        c=text.at(i);
        text.at(i) = (tolower(c));
        i++;
    }
    return text;
}
