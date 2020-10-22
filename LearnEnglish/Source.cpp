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

// struct with admin docs
struct User
{
    string adminName = "admin";
    string adminPass = "123qwe1q2w3e";
    string userName = "user";
    string userPass = "1234";
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

// function output all words | NEED DEVELOPMENT 
void outputAllWords()
{
    ifstream fin;
    fin.open("myFile.txt");

    string arr_char;

    for (int i = 0; fin.eof() == false ; i++)
    {
        fin >> arr_char;
        cout << arr_char << endl;
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
    outputAllWords();
    
    
    
}

// function for admin panel | NEED DEVELOPMENT
void adminPanel()
{
    string saveload;

    cout << " ----------------------------------------- " << endl;
    cout << "|  enter 'text' to write your document    |" << endl;
    cout << "|  enter 'open file' to open the document |" << endl;
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
    }
}

// function for output menu
void showMenu()
{
    system("mode con cols=80 lines=30");
    int action = 0;
    do
    {
        cout << "\t\t\t ============================" << endl;
        cout << "\t\t\t| 1. SHOW ALL ENGLISH WORDS  |" << endl;
        cout << "\t\t\t| 2.    Admin Panel          |" << endl;
        cout << "\t\t\t| 3.     Right word          |" << endl;
        cout << "\t\t\t ============================" << endl;
        cout << endl;
        cout << "Enter action->";
        cin >> action;
        cout << endl;

        switch (action)
        {
        case 1: {
            outputAllWords();
        }break;
        case 2: {
            adminPanel();
        }break;
        case 3: {
            rightWord();
        }break;
        }
    } while (true);


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

// function for authorizatet system | NEED DEVELOPMENT
void Login() {
    system("mode con cols=20 lines=10");
    cout << " -----------------" << endl;
    cout << "|      LOGIN      |" << endl;
    cout << " -----------------" << endl;
    cout << "\t ";
    cin >> login;
    cout << " -----------------" << endl;
    cout << "|   PASSWORD      |" << endl;
    cout << " -----------------" << endl;
    cout << "\t ";
    cin >> pass;
    if (login == user.adminName && login == user.userName) {
        cout << "success" << endl;
        showMenu();
    }
    else
    {
        mistake();
    }
    if (pass == user.adminPass && pass == user.userPass) {
        cout << "success" << endl;
        showMenu();
    }
    else
    {
        mistake();
    }
    
}

int main() {
    showMenu();

    return 0;
}
