#include "main.h"

int main()
{
    srand( time(0));

    // mainScreen();

    // generateQuestionbinaryFile("test.txt");
    /*  ifstream myfile(QuestionFileName,  ios::binary);

     for(int i = 0; i < 3; i++){
     Question q;

     myfile.read(q.questionText, sizeof(q.questionText));
     for(int j = 0 ; j < 3; j++){
       myfile.read(q.qA[j].answer, sizeof(q.qA[j].answer));
     }
     myfile.read(reinterpret_cast<char *>(&q.correctAnswer), sizeof(q.correctAnswer));

     cout << q.questionText << endl;
      for(int j = 0 ; j < 3; j++){
       cout << q.qA[j].answer<<endl;
     }
     cout << q.correctAnswer << endl;
     }
        myfile.close();*/

    /*Question q;
    q = readQuestionFromFile(0);

    displayQuestion(q);

    q = readQuestionFromFile(2);

    displayQuestion(q);

    */

    /*NumberStack *root = NULL, *w=NULL;

    pushStack(&root, 40);
    pushStack(&root, 12);

    w=root;

    // clearStack(&root);

    if (root)  //sprawdz czy stos nie jest juz pusty
    {
        cout << popStack(&root);
    }

    root = w;

    if (root)  //sprawdz czy stos nie jest juz pusty
    {
        cout << popStack(&root);
    }

    clearStack(&root);
*/

/*
    NumberStack *root = generateUniqueNumber(80);
    NumberStack *w = root;

    while(root){
        cout << popStack(&root) <<endl;
    }

    root =w;

    clearStack(&root);
*/
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


/*Remove temp file after generation*/
/*
int generateUniqueNumber()
{

    fstream tempFile;
    tempFile.open(TempFileName, ios::in | ios::out | ios::binary | ios::app );

    bool isUnique = true;
    int n = ( rand() % 50 ) + 1;
    int buff = -1;

    int fsize = tempFile.tellg();
    int currpos = 0;
    tempFile.seekg( 0, std::ios::end );
    fsize = tempFile.tellg() - fsize;
    //fsize/=sizeof(int);


    if(fsize == 0)
    {
        tempFile.write(reinterpret_cast<char *>(&n), sizeof(n));
        return n;
    }
    else
    {

    while(true){

        n = ( rand() % 50 ) + 1;
        isUnique = true;
        for(int i = 0; i < (fsize/sizeof(fsize)); i++)
        {
            tempFile.seekg(currpos);
            tempFile.read(reinterpret_cast<char *>(&buff), sizeof(buff));

            if(buff == n)
            {
                isUnique = false;
            }

            currpos += sizeof(buff);
        }

        if(isUnique){
            tempFile.write(reinterpret_cast<char *>(&n), sizeof(n));
            break;
        }
    }

    }
    tempFile.close();
    return n;

}

int removeTempFile(){

  if( remove( TempFileName ) != 0 )
    return 1;
  else
    return 0;

}
*/
