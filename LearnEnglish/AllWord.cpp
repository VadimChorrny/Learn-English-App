#include "AllWord.h"
#include "Source.cpp"



void allWord()
{
    ifstream fin;
    fin.open("myFile.txt");

    string arr_char;

    cout << "=====================================" << endl;
    cout << "|  Write down words you don't know  |" << endl;
    cout << "=====================================" << endl;

    for (int i = 0; fin.eof() == false; i++)
    {

        fin >> arr_char;
        cout << "===============================" << endl;
        cout << "New word ---> " << arr_char << endl;
        cout << "===============================" << endl;
        system("pause");
    }
}
