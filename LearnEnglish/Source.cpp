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

using namespace std;

#define Clear system("cls");

/// <summary>
/// init global variables
/// </summary>
string login;
string pass;
string rememberWord;
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
/// function for set color
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
/// function for mistake
/// </summary>
void mistake()
{
    cout << " ----------------------------------------- " << endl;
    cout << "|                   ERROR                 |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|              YOU IDIOTS BLYAT           |" << endl;
    cout << "|              YOU IDIOTS BLYAT           |" << endl;
    cout << "|              YOU IDIOTS BLYAT           |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|              by Chorrny edition         |" << endl;
    cout << " ----------------------------------------- " << endl;
    Clear;
}

/// <summary>
/// function remembers word
/// </summary>
void remembersWord() {

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

/// <summary>
/// function output true or false words 
/// </summary>
void output() {
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

/// <summary>
/// function add quest
/// </summary>
void addQuest()
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
/// function 
/// </summary>
void outputAllWords()
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
/// function for true word
/// </summary>
void help()
{
    cout << " ----------------------------------------- " << endl;
    cout << "|                   Rules                 |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|              One word is given          |" << endl;
    cout << "|              You have a choice          |" << endl;
    cout << "|               True or False             |" << endl;
    cout << " ----------------------------------------- " << endl;
}

/// <summary>
/// function for all games
/// </summary>
void englishGames()
{
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
        outputAllWords();
    }break;
    case 2: {
        output();
    }break;
    case 3: {
        remembersWord();
    }break;
    case 4: {
        help();
    }break;
    case 5: {
        help();
    }
    }
}

/// <summary>
/// function for settings apps
/// </summary>
void adminPanel()
{
    string saveload;

    cout << " ----------------------------------------- " << endl;
    cout << "|  enter 'text' to write your document    |" << endl;
    cout << "|  enter 'open file' to open the document |" << endl;
    cout << "|  enter 'exit' for exit programm         |" << endl;
    cout << "|  enter 'add' for add new quiz           |" << endl;
    cout << " -----------------------------------------" << endl;
    while (true) {
        getline(cin, saveload);

        if(saveload == "add"){
            addQuest();
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
        if (saveload == "exit" && saveload == "Exit" && saveload == "Ext") {
            system("cls");
        }
    }
}

/// <summary>
/// function for user profile
/// </summary>
void myProfile()
{
    
    cout << "Your name: " << loginW << endl;
    cout << "Your cristal: " << cristal << endl;
    
}

/// <summary>
/// function show menu
/// </summary>
void showMenu()
{

    ifstream("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\cristal.txt");

    //string menu = { "1. START ENGLISH GAMES" };

    system("mode con cols=60 lines=20");
    int action = 0;
    do
    {
        system("color 0"); cout << "\t\t==============================" << endl;
        Sleep(100);
        system("color 1"); cout << "\t\t| 1.    START ENGLISH GAMES  |" << endl;
        Sleep(100);
        system("color 2"); cout << "\t\t| 2.    Settings app       |" << endl;
        Sleep(100);
        system("color 3"); cout << "\t\t| 3.    Show my profile    |" << endl;
        Sleep(100);
        system("color 3"); cout << "\t\t| 4.    Exit               |" << endl;
        Sleep(100);
        system("color 4"); cout << "\t\t==============================" << endl;
        Sleep(100);
        cout << endl;
        system("color 5"); cout << "Enter action->";
        cin >> action;
        cout << endl;
        Clear;
        switch (action)
        {
        case 1: {
            englishGames();
        }break;
        case 2: {
            adminPanel();
        }break;
        case 3: {
            myProfile();
        }break;
        case 4: {
            ofstream user("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\" + loginW + ".txt");
            user << cristal;
            user.close();
            break;
        }
        default: {
            mistake();
        }
        }
    } while (action != 4);
}

/// <summary>
/// function authorization users
/// </summary>
void Login() {
    system("mode con cols=20 lines=10");
    string loginF, passwordF;
    
    system("color 3");cout << " -----------------" << endl;
    system("color 3");cout << "|      LOGIN      |" << endl;
    system("color 3");cout << " -----------------" << endl;
    system("color 3");cout << "\t ";
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


                    showMenu();
                }
                else
                {
                    system("color 4"); cout << "Error\n";
                }
            }
        }
    }
    in.close();
    if (Isregister)
    {
        ofstream file("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\login.txt", ios_base::app);
        ofstream user("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\Users\\" + loginW + ".txt");
        user << "0";
        user.close();
        file << loginW << endl;
        file << passwordW << endl;
        cout << "register\n";
        showMenu();
        file.close();
    }
}
    
int main() {

    /// <summary>
    /// function create new users
    /// </summary>
    /// <returns></returns>
    Login();

    return 0;
}
