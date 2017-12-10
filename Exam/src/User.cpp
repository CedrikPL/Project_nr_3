#include "User.h"

void updateUser(User user)
{
    string line;
    fstream of;
    of.open (UserFileName, ios::out | ios::in | ios::binary);
    if (of.is_open())
    {
        while( !of.eof() )
        {
            getline( of, line );
            if(!line.compare(user.userName))
            {
                of << user.examCnt << "\n";
                of << user.topScore << "\n";
                of << user.lastExamID << "\n";
            }
        }
    }
    of.close();
}

User createUser(string userName)
{
    User u;

    u.userName = userName;
    u.examCnt = 0;
    u.topScore = 0;
    u.lastExamID = userName;

    ofstream of;
    of.open (UserFileName, ios::out | ios::app | ios::binary);

    if(of.is_open())
    {
        of << u.userName << "\n";
        of << u.examCnt << "\n";
        of << u.topScore << "\n";
        of << u.lastExamID << "\n";
    }
    else cout << "Unable to open file: "<<UserFileName;

    of.close();

    return u;
}

User userExist(string userName)
{
    User u;
    u.userName = undefinedUser;

    string line;
    ifstream myfile(UserFileName);

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(!line.compare(userName))  // user exist
            {
                u.userName = line;
                getline (myfile,line);
                u.examCnt = atoi(line.c_str());
                getline (myfile,line);
                u.topScore = atoi(line.c_str());
                getline (myfile,line);
                u.lastExamID = line;
                break;
            }
        }

    }
    else cout << "Unable to open file: "<<UserFileName;

    myfile.close();

    return u;
}
