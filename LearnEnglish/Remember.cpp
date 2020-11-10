#include "Remember.h"
#include "Mistake.h"
#include "Source.cpp"

void remember()
{
    string path = "C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\remember.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {

        mistake();

    }
    else {
        string msg;
        int value;
        cout << "Enter '1' for write words" << endl;
        cout << "Enter '2' for output your words" << endl;
        cout << "Enter 'close' for exit app" << endl;
        cin >> value;
        if (value == 1) {
            while (cin >> msg)
            {
                fs << msg << "\n";
                if (msg == "close") { // when in cycle.. user enter 'close', cycle stoped
                    system("cls");
                    break;
                }
            }
        }
        else if (value == 2) {
            while (!fs.eof()) {
                msg = "";
                fs >> msg;
                cout << msg << endl;
            }
        }
        else {
            cout << "error" << endl;
        }
    }
    fs.close();
}


