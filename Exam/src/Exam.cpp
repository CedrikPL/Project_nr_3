#include "Exam.h"

void saveExam(Exam exam)
{
    ofstream of;
    of.open (ExamFileName, ios::out | ios::app | ios::binary);
    if(of.is_open()){

        of << exam.examID << "\n";
        of << exam.examDate.rrrr << "\n";
        of << exam.examDate.mm << "\n";
        of << exam.examDate.dd << "\n";
        of << exam.examDate.h << "\n";
        of << exam.examDate.m << "\n";
        of << exam.examDate.s << "\n";
        of << exam.totalScore << "\n";
        of << exam.nextExamID << "\n";

    }else cout << "\nWarning!: Data corruption occurred in "<<ExamFileName<<" file. All exam data lost!\n";
    of.close();
}

Exam loadExam(string examID)
{
    Exam e;
    string line;
    ifstream myfile(ExamFileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(!line.compare(examID))  // user exist
            {
                e.examID = line;

                getline (myfile,line);
                e.examDate.rrrr = atoi(line.c_str());
                getline (myfile,line);
                e.examDate.mm = atoi(line.c_str());
                getline (myfile,line);
                e.examDate.dd = atoi(line.c_str());
                 getline (myfile,line);
                e.examDate.h = atoi(line.c_str());
                 getline (myfile,line);
                e.examDate.m = atoi(line.c_str());
                 getline (myfile,line);
                e.examDate.s = atoi(line.c_str());

                getline (myfile,line);
                e.totalScore = atoi(line.c_str());
                getline (myfile,line);
                e.nextExamID = line;
                break;
            }
        }

    }
    else {cout << "\nWarning!: Data corruption occurred in "<<ExamFileName<<" file. All exam data lost!\n";e.examID = '~';}
    myfile.close();
    return e;
}
