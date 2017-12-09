#include "Exam.h"

void saveExam(Exam exam)
{
    ofstream of;
    of.open (ExamFileName, ios::out | ios::app | ios::binary);
    if(of.is_open()){

        of << exam.examID << "\n";
        of << exam.totalScore << "\n";
        of << exam.nextExamID << "\n";

    }else cout << "Unable to open file: "<<ExamFileName;
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
                e.totalScore = atoi(line.c_str());
                getline (myfile,line);
                e.nextExamID = line;
                break;
            }
        }

    }
    else cout << "Unable to open file: "<<ExamFileName;
    myfile.close();


    return e;
}