#include "Games.h"
#include "AllWord.h"
#include "Victorine.h"
#include "Remember.h"
#include "Help.h"
#include "Source.cpp"

void games()
{
    Clear;
    int action = 0;
    cout << "\t\t==============================" << endl;
    cout << "\t\t| 1. SHOW ALL ENGLISH WORD   |" << endl;
    cout << "\t\t| 2. True and False word     |" << endl;
    cout << "\t\t| 3. Remember words          |" << endl;
    cout << "\t\t| 4. Help                    |" << endl;
    cout << "\t\t| 5. Back to menu            |" << endl;
    cout << "\t\t==============================" << endl;
    cin >> action;
    switch (action)
    {
    case 1: {
        allWord();
    }break;
    case 2: {
        victorina();
    }break;
    case 3: {
        remember();
    }break;
    case 4: {
        Help();
    }break;
    case 5: {
        Help();
    }
    }
}
