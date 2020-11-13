#include "Function.h"
#include <iostream>
#include <string>
#include <fstream>
#include "iostream"
#include "windows.h"
#include "string"
#include "fstream"
#include <time.h>
#include <ctime>
#include <conio.h>
#include <sstream> 
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <Windows.h>

// music connect
#include "Windows.h"
#include <MMSystem.h>
#include <Windows.h>

#pragma comment(lib, "winmm.lib")

// connect file
#include "Sorting.h"

using namespace std;


// connect macros
#define Clear system("cls");

/// <summary>
/// init global variable
/// </summary>

string victorine[100][10][6] = { { {
    "Ancient Greece. Myths","How did Hera thank Cancer",
    "She gave him a river","Made him a constellation",
    "Made him immortal","Made him a constellation"},
    {"Ancient Greece. Myths",
    "This king ordered the daughters to kill their brides",
    "Oedipus","Danai","Egypt","Danai"},
    {"Ancient Greece. Myths",
    "Who sympathized with ",
    "Moiri","Oceanids",
    "Eat",
    "Oceanids"},
    {"Ancient Greece. Myths",
    "Daughter of King Colchis Eeta, who helped Jason steal the golden fleece.",
    "Hestia","Iris","Medea","Medea"},
    {"Ancient Greece. Myths",
    "What did Odysseus call himself Cyclops Polyphemus?",
    "No one","Nothing","Someone","No one"},{"Ancient Greece. Myths",
    "6. What ordered Hercules to get the Amazon insignificant Eurystheus?",
    "3 pieces of Melanippus","Horse of Antioch","Hippolyta's belt","Hippolyta's belt"},
    {"Ancient Greece. Myths","thirst and fear.","Antey","Sisyphus","Tantalum","Tantalum"},
    {"Ancient Greece. Myths"," her children Apollo and Artemis - they killed all her children.",
    "Given","Pasiphae","Niobe","Niobe"},{"Ancient Greece. Myths",
    "The unsurpassed master weaver, who challenged Athena Pallas hersurned her into a spider.",
    "Arachna","Ariadne","Medea","Arachna"},{"Ancient Greece. Myths",
    "The son of Danai, who defeated Medg Cepheus and Cassiopeia, from imminent death.",
    "Odysseus","Perseus","Phineas","Perseus"} } };
string loginW, passwordW, cristalls;
int win = 0;
int cristal = 0;
int choiseQuise = 0;
int choiseVariants = 0;
int quise = 0;

/// <summary>
/// setcolor setting function
/// </summary>
void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

/// <summary>
/// function size console
/// </summary>
void Size_Console(int x, int y)
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { x, y };
    SMALL_RECT src = { 0, 0, crd.X , crd.Y };
    SetConsoleWindowInfo(out_handle, true, &src);
    SetConsoleScreenBufferSize(out_handle, crd);
}

/// <summary>
/// show mistake
/// </summary>
void mistake()
{
    cout << " ----------------------------------------- " << endl;
    cout << "|                   ERROR                 |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|              YOU IDIOTS B....           |" << endl;
    cout << "|              YOU IDIOTS BL...           |" << endl;
    cout << "|              YOU IDIOTS BLY..           |" << endl;
    cout << "|              YOU IDIOTS BLYA.           |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|              by Chorrny edition         |" << endl;
    cout << " ----------------------------------------- " << endl;
    Clear;
}

/// <summary>
/// remember word | input & output
/// </summary>
void rememberWord()
{
    string path = "remember.txt";
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
        cout << "Enter '3' for positions words" << endl;
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
            system("pause");
        }
        else if (value == 3) {
            sortingWord();
        }
        else {
            mistake();
            cout << "error" << endl;
            PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

        }
    }
    fs.close();
}

/// <summary>
/// true or false questions
/// </summary>
void OutPut()
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
    PlaySound(TEXT("buster.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    if (win <= 3 && win >= 1) {
        PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        cout << "Your cristals: " << cristal << "out for 10" << endl;
        cout << "Your level: beginner" << endl;
    }
    else if (win <= 5) {
        PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        cout << "Your cristals: " << cristal << "out for 10" << endl;
        cout << "Your level: intermedia" << endl;
    }
    else if (win <= 9) {
        cout << "Your cristals: " << cristal << "out for 10" << endl;
        cout << "Your level: advanced " << endl;
    }
    system("pause");

}

void ShowMenu();

/// <summary>
/// adding new quest
/// </summary>
void addNewQuest()
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

/// <summary>
/// output all words with file
/// </summary>
void OutPutAllWord()
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

/// <summary>
/// show help
/// </summary>
void Help()
{
    Clear;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t ----------------------------------------- " << endl;
    cout << "\t|                   Rules                 |" << endl;
    cout << "\t|-----------------------------------------|" << endl;
    cout << "\t|              One word is given          |" << endl;
    cout << "\t|              You have a choice          |" << endl;
    cout << "\t|               True or False             |" << endl;
    cout << "\t ----------------------------------------- " << endl;
    system("pause");
}

/// <summary>
/// menu for english name
/// </summary>
void EnglishGame()
{
    Clear;
    int action = 1;
    int a = 0;
    setlocale(LC_ALL, "");
    string  ach[] = { "1-SHOW ALL ENGLISH WORDS","2-TRUE OR FALSE","3-REMEMBER WORDS","4-HELP", "5-EXIT" };
    while (a != 13) {
        system("cls");
        for (int i = 0; i < 5; i++) {
            if (i == action - 1) {
                SetColor(0, 14);
            }
            if (i != action - 1) {
                SetColor(0, 15);
            }
            cout << ach[i] << endl; // bag
            SetColor(0, 15);
        }
        a = _getch();
        if (a == 119) {
            action--;
            if (action < 1) {
                action = 1;
            }
        }
        else if (a == 115) {
            action++;
            if (action > 8) {
                action = 1;
            }
        }
    }
    switch (action)
    {
    case 1: {
        OutPutAllWord();
    }break;
    case 2: {
        OutPut();
    }break;
    case 3: {
        rememberWord();
    }break;
    case 4: {
        Help();
    }break;
    case 5: {
        ShowMenu();
    }
    }
}

void AboutAuthor();

/// <summary>
/// settings app
/// </summary>
void Settings()
{
    string saveload;

    cout << " ----------------------------------------- " << endl;
    cout << "|  enter 'text' to write your document    |" << endl;
    cout << "|  enter 'open file' to open the document |" << endl;
    cout << "|  enter 'exit' for exit programm         |" << endl;
    cout << "|  enter 'add' for add new quiz           |" << endl;
    cout << "|  enter 'delete' for delete word         |" << endl;
    cout << "|  enter 'sort' for sorting your file     |" << endl;
    cout << "|  enter 'info' for information Author    |" << endl;
    cout << " -----------------------------------------" << endl;
    while (true) {
        getline(cin, saveload);

        if (saveload == "info" || saveload == "Info") {
            AboutAuthor();
        }

        if (saveload == "sort" || saveload == "Sort")
        {
            sortingLong();
        }

        if (saveload == "delete" || saveload == "del" || saveload == "Delete" || saveload == "Del") {
            removeWord();
        }

        if (saveload == "add" ) {
            addNewQuest();
        }

        if (saveload == "open file") {
            string filenamet;
            cout << "file name? " << endl;
            getline(cin, filenamet, '*');
            ifstream loadFile;


            loadFile.open(filenamet, ifstream::in);

            cout << "the text you entered was: ";

            while (loadFile.good()) {
                cout << (char)loadFile.get();
                Sleep(100);
            }
            cout << "" << endl;
            loadFile.close();

        }

        if (saveload == "text") {
            string filename;
            cout << "file name: " << endl;
            getline(cin, filename, '*');
            string textToSave;
            cout << "Enter your text: " << endl;
            getline(cin, textToSave, '*');

            ofstream saveFile(filename);

            saveFile << textToSave;
            saveFile.close();
        }
        if (saveload == "exit" || saveload == "Exit" || saveload == "Ext") {
            ShowMenu();
        }
    }
}

/// <summary>
/// prototype function
/// </summary>
void AuthUser();

/// <summary>
/// about author informations
/// </summary>
void AboutAuthor()
{
    system("cls");
    cout << "Created apps ---> ";
    system("color 4"); cout << "VADIM CHORRNY" << endl;
    
}

/// <summary>
/// show user profile
/// </summary>
void UserProfile()
{
    Clear;
    system("color 4"); cout << "================" << endl;
    system("color 3"); cout << "Your name: " << loginW << endl;
    system("color 3"); cout << "Your cristal: " << cristal << endl;
    system("color 4"); cout << "================" << endl;
    system("pause");
    Clear;
}

/// <summary>
/// show menu 
/// </summary>
void ShowMenu()
{
    system("mode con cols=60 lines=20");
    ifstream("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\cristal.txt");
    
        // new
        int a = 0;
        int action = 1;
        do {
            setlocale(LC_ALL, "");
            string  ach[] = { "1-START ENGLISH GAMES","2-Setting app","3-Show my profile","4-Exit","5-UnLogin" };
            while (a != 13) {
                system("cls");
                for (int i = 0; i < 4; i++) {
                    if (i == action - 1) {
                        SetColor(0, 14);
                    }
                    if (i != action - 1) {
                        SetColor(0, 15);
                    }
                    cout << ach[i] << endl; // bag
                    SetColor(0, 15);
                }
                a = _getch();
                if (a == 119) {
                    action--;
                    if (action < 1) {
                        action = 1;
                    }
                }
                else if (a == 115) {
                    action++;
                    if (action > 8) {
                        action = 1;
                    }
                }
            }
            switch (action)
            {
            case 1: {
                EnglishGame();
            }break;
            case 2: {
                Settings();
            }break;
            case 3: {
                UserProfile();
            }break;
            case 4: {
                ofstream user("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\" + loginW + ".txt");
                user << cristal;
                user.close();
                break;
            }break;
            case 5: {
                AuthUser();
            }
            }
        } while (action != 5);


}

/// <summary>
/// login user
/// </summary>
void AuthUser()
{
    system("mode con cols=20 lines=10");
    string loginF, passwordF;
    system("color 3"); cout << " -----------------" << endl;
    system("color 3"); cout << "|      LOGIN      |" << endl;
    system("color 3"); cout << " -----------------" << endl;
    system("color 3"); cout << "\t ";
    getline(cin, loginW);
    system("color 3"); cout << " -----------------" << endl;
    system("color 3"); cout << "|   PASSWORD      |" << endl;
    system("color 3"); cout << " -----------------" << endl;
    system("color 3"); cout << "\t ";
    getline(cin, passwordW);
    ifstream in("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\login.txt");
    bool Isregister = true;
    if (in.is_open())
    {
        while (!in.eof())
        {
            getline(in, loginF);
            getline(in, passwordF);

            if (loginF == loginW)
            {
                Isregister = false;
                if (passwordF == passwordW)
                {
                    system("cls");
                    system("mode con cols=45 lines=5");
                    system("color A"); cout << "\t\t  ---------" << endl;
                    system("color B"); cout << "\t\t | Welcome |" << endl;
                    system("color C"); cout << "\t\t  ---------" << endl;
                    Sleep(1000);

                    ifstream user("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\" + loginW + ".txt");
                    getline(user, cristalls);
                    cristal = stoi(cristalls); // change string in int


                    ShowMenu();
                }
                else
                {
                    system("color 4"); cout << "Error\n";
                    mistake();
                    PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                }
            }
        }
    }
    in.close();
    if (Isregister)
    {
        ofstream file("login.txt", ios_base::app);
        ofstream user(loginW + ".txt");
        user << "0";
        user.close();
        file << loginW << endl;
        file << passwordW << endl;
        cout << "register\n";
        ShowMenu();
        file.close();
    }
}
