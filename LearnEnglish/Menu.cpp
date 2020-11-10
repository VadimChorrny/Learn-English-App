#include "Menu.h"
#include "Games.h"
#include "Profile.h"
#include "Settings.h"
#include "Source.cpp"


void menu()
{
    system("mode con cols=60 lines=20");

    ifstream("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\cristal.txt");
    int action = 0;
    do
    {
        system("color 4"); cout << "\t\t==============================" << endl;
        Sleep(100);
        system("color 1"); cout << "\t\t| 1.    START ENGLISH GAMES  |" << endl;
        Sleep(100);
        system("color 2"); cout << "\t\t| 2.    Settings app         |" << endl;
        Sleep(100);
        system("color 3"); cout << "\t\t| 3.    Show my profile      |" << endl;
        Sleep(100);
        system("color 3"); cout << "\t\t| 4.    Exit                 |" << endl;
        Sleep(100);
        system("color 4"); cout << "\t\t==============================" << endl;
        Sleep(100);
        Sleep(100);
        cout << endl;
        system("color 5"); cout << "Enter action->";
        cin >> action;
        switch (action)
        {
        case 1: {
            games();
        }break;
        case 2: {
            Setting();
        }break;
        case 3: {
            profile();
        }break;
        case 4: {
            ofstream user("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\" + loginW + ".txt");
            user << cristal;
            user.close();
            break;
        }
        }
    } while (action != 4);
}
