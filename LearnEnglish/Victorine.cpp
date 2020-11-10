#include "Victorine.h"
#include "Source.cpp"


void victorina()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 5; j++) {
            cout << victorine[choiseQuise][i][j] << endl;
        }
        cout << "Enter number variants -> \t";
        cin >> choiseVariants;
        system("cls");
        for (int j = 1; j < 5; j++) {
            if (victorine[choiseQuise][i][j] == victorine[choiseQuise][i][5]) {
                cout << victorine[choiseQuise][i][j] << endl;
            }
            else if (victorine[choiseQuise][i][j] == victorine[choiseQuise][i][1]) {
                cout << victorine[choiseQuise][i][j] << endl;
            }
            else {
                cout << victorine[choiseQuise][i][j] << endl;
            }
        }
        if (victorine[choiseQuise][i][choiseVariants++] == victorine[choiseQuise][i][5]) {
            win++;
            cristal++;
        }

    }
    cout << "Correct answers:" << win << " out of 10" << endl;
    if (cristal <= 3) {
        cout << "Your cristals: " << cristal << "out for 10" << endl;
        cout << "Your level: beginner" << endl;
    }
    else if (cristal <= 5) {
        cout << "Your cristals: " << cristal << "out for 10" << endl;
        cout << "Your level: intermedia" << endl;
    }
    else if (cristal <= 9) {
        cout << "Your cristals: " << cristal << "out for 10" << endl;
        cout << "Your level: advanced " << endl;
    }
    else {
        cout << "error" << endl;
    }
}
