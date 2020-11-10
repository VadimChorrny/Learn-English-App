#include "addQuest.h"
#include "Source.cpp"





void newQuest()
{
    quise + 1;
    cout << "Enter word wich remember ->" << endl;
    getline(cin, victorine[quise][0][0]);
    getline(cin, victorine[quise][0][0]);
    for (int i = 0; i < 10; i++) {
        victorine[quise][i][0] = victorine[quise][0][0];;
    }
    for (int i = 0; i < 10; i++) {
        cout << "Enter word";
        cin >> victorine[quise][i][1];
        for (int j = 2; j < 5; j++) {
            cout << "Enter variants word";
            cin >> victorine[quise][i][j];
            int  trueVar = 0;
            cout << "Enter varians true";
            cin >> trueVar;
            system("cls");
            if (trueVar == 1) {
                victorine[quise][i][5] = victorine[quise][i][j];
            }
        }
    }
}
