#include "utilities.h"

std::string castToPL( string * text ){
    std::string result;
    char z;
    unsigned int i;
    for(i = 0;i < text->size(); i++){
        z = text->at(i);
      switch( z )
        {
        case 'π': result += static_cast < char >( 0xa5 ); break;
        case 'Ê': result += static_cast < char >( 0x86 ); break;
        case 'Í': result += static_cast < char >( 0xa9 ); break;
        case '≥': result += static_cast < char >( 0x88 ); break;
        case 'Ò': result += static_cast < char >( 0xe4 ); break;
        case 'Û': result += static_cast < char >( 0xa2 ); break;
        case 'ú': result += static_cast < char >( 0x98 ); break;
        case 'ø': result += static_cast < char >( 0xbe ); break;
        case 'ü': result += static_cast < char >( 0xab ); break;
        case '•': result += static_cast < char >( 0xa4 ); break;
        case '∆': result += static_cast < char >( 0x8f ); break;
        case ' ': result += static_cast < char >( 0xa8 ); break;
        case '£': result += static_cast < char >( 0x9d ); break;
        case '—': result += static_cast < char >( 0xe3 ); break;
        case '”': result += static_cast < char >( 0xe0 ); break;
        case 'å': result += static_cast < char >( 0x97 ); break;
        case 'Ø': result += static_cast < char >( 0xbd ); break;
        case 'è': result += static_cast < char >( 0x8d ); break;
            default: result += z; break;
        }
    }

    return result;
}


void generateQuestionbinaryFile(const char* fileDir){

    Question q;
    int i = 0;
    string line;
    ifstream myfile(fileDir);
    ofstream of;
    of.open (QuestionFileName, ios::out | ios::app | ios::binary);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {  i++;
           switch(i){
                case 1:
                    strncpy(q.questionText, line.c_str(), sizeof(q.questionText));
                break;
                case 2:
                    strncpy( q.qA[0].answer, line.c_str(), sizeof(q.qA[0].answer));
                    break;
                case 3:
                    strncpy( q.qA[1].answer, line.c_str(), sizeof(q.qA[1].answer));
                    break;
                case 4:
                    strncpy( q.qA[2].answer, line.c_str(), sizeof(q.qA[2].answer));
                    break;
                case 5:
                    q.correctAnswer = atoi(line.c_str());
                    break;
           };
            if(i == 5){
                //cout << q.questionText << endl<<q.qA[0].answer<<endl << q.correctAnswer << endl<<endl;

                of.write(q.questionText, sizeof(q.questionText));
                for(int j = 0 ; j < 3; j++){
                    of.write(q.qA[j].answer, sizeof(q.qA[j].answer));
                }
                 of.write(reinterpret_cast<char *>(&q.correctAnswer), sizeof(q.correctAnswer));

                i = 0;
            }
        }
        myfile.close();
        of.close();
    }else cout << "Unable to open file: "<<fileDir;
}
