#include "iostream"
#include "windows.h"
#include "string"
#include "fstream"
#include <time.h>
#include <ctime>
#include <conio.h>
#include <sstream> 
#include <cstdlib>

using namespace std;

// Initialization of define ( macros )
#define Clear system("cls");

// Initialization of variables
string login;
string pass;
string rememberWord;

// struct with admin docs
struct User
{
    string adminName = "admin";
    string adminPass = "1234567";

} user;

// struct for system levels
struct Levels
{
    int diamonds = 0;
    int level = 0;
};

// connect color themes
void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

//function for mistake
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

// function remember words | NEED DEVELOPMENT
void rememberWords()
{
    cout << " -------------------------------" << endl;
    cout << "|         Enter your words      |" << endl;
    cout << "|-------------------------------" << endl;
    cout << "|" << endl;
    cout << "---->" << endl;
    cin >> rememberWord;

    int action = 0;
    do {
        
        cout << "Show all remember word" << endl;
        cout << "Enter new world" << endl;
        cin >> action;
        switch (action) {
        case 1: {
            cout << rememberWord << endl;
        }break;
        case 2: {
            rememberWords();
        }break;
        case 3: {
            Clear;
        }
        }

    } while (action != 3);

}

// function output all words | NEED DEVELOPMENT 
void outputAllWords()
{

    ifstream fin;
    fin.open("myFile.txt");

    string arr_char;

    for (int i = 0; fin.eof() == false; i++)
    {
        fin >> arr_char;
        cout << "===============================" << endl;
        cout << "New word: " << arr_char << endl;
        cout << "===============================" << endl;
        system("pause");
    }
}

// word selection function
void rightWord()
{
    cout << " ----------------------------------------- " << endl;
    cout << "|                   Rules                 |" << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|              One word is given          |" << endl;
    cout << "|              You have a choice          |" << endl;
    cout << "|               True or False             |" << endl;
    cout << " ----------------------------------------- " << endl;
    Sleep;
    

    
    
    
}


// function ALL english game
void englishGames()
{
    int action = 0;
    cout << "\t\t\t==============================" << endl;
    cout << "\t\t\t| 1. SHOW ALL ENGLISH WORD   |" << endl;
    cout << "\t\t\t| 2. True and False word     |" << endl;
    cout << "\t\t\t| 3. Remember word           |" << endl;
    cout << "\t\t\t==============================" << endl;
    cin >> action;
    switch (action)
    {
    case 1: {
        outputAllWords();
    }break;
    case 2: {
        rightWord();
    }break;
    case 3: {
    }break;
    }
}


// function for admin panel | NEED DEVELOPMENT
void adminPanel()
{
    string saveload;

    cout << " ----------------------------------------- " << endl;
    cout << "|  enter 'text' to write your document    |" << endl;
    cout << "|  enter 'open file' to open the document |" << endl;
    cout << "|  enter 'exit' for exit programm         |" << endl;
    cout << " -----------------------------------------" << endl;
    while (true) {
        getline(cin, saveload);

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

// function for output menu
void showMenu()
{
    int action = 0;
    do
    {
        cout << "\t\t\t ============================" << endl;
        cout << "\t\t\t| 1.    START ENGLISH GAMES  |" << endl;
        cout << "\t\t\t| 2.       Admin Panel       |" << endl;
        cout << "\t\t\t| 3.        Right word       |" << endl;
        cout << "\t\t\t| 4.      Remember word      |" << endl;
        cout << "\t\t\t ============================" << endl;
        cout << endl;
        cout << "Enter action->";
        cin >> action;
        cout << endl;

        switch (action)
        {
        case 1: {
            englishGames();
        }break;
        case 2: {
            adminPanel();
        }break;
        case 3: {
            rightWord();
        }break;
        case 4: {
            rememberWords();
        }
        }
    } while (true);


}



// function for authorizatet system | NEED DEVELOPMENT
void Login() {
    string loginW, passwordW, loginF, passwordF;
    cout << " -----------------" << endl;
    cout << "|      LOGIN      |" << endl;
    cout << " -----------------" << endl;
    cout << "\t ";
    getline(cin, loginW);
    cout << " -----------------" << endl;
    cout << "|   PASSWORD      |" << endl;
    cout << " -----------------" << endl;
    cout << "\t ";
    getline(cin, passwordW);
    ifstream in("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\login.txt");
    bool Isregister = true;
    cout << "______________________________\n";
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
                    cout << "ok";
                    showMenu();
                }
                else
                {
                    cout << "Error\n";
                }
            }
        }
    }
    in.close();
    if (Isregister)
    {
        ofstream file("C:\\Users\\vadim_oyanwuw\\source\\repos\\LearnEnglish\\LearnEnglish\\login.txt", ios_base::app);
        file << loginW << endl;
        file << passwordW << endl;
        cout << "register\n";
        file.close();
    }
    
}

int main() {
    
    Login();

    return 0;
}
