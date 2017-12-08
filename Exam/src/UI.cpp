#include "UI.h"
#include "main.h"

void mainScreen()
{

    system("cls");

    char s;
    do
    {
        cout << "1 - exam; 2 - exit\nSelect option: ";
        cin.sync();
        s = getchar();

        switch(s)
        {
        case '1':

            break;
        default:
            cout << "Incorrect value!\n";
        }

        }while(s != '2');
    }
