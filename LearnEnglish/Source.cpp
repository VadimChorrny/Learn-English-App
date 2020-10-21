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

// Initialization of define

#define Clear system("cls");
#define Sleep Sleep(10000);

// Initialization of variables

string login;
string password;
bool SingIn = false;
int level = 0;
string knows;
string noThing;



void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}


// function output all words 

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


void showMenu()
{
    system("mode con cols=100 lines=30");
    int action = 0;
    do
    {
        cout << "============================" << endl;
        cout << "1. SHOW ALL ENGLISH WORDS" << endl;
        cout << "2. \tAdmin Panel" << endl;
        cout << "3. \tRight word" << endl;
        cout << "============================" << endl;
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

void Login() {
    system("mode con cols=30 lines=15");
    string password;
    cout << "\t    LOGIN" << endl;
    cout << "\t ";
    cin >> login;
    cout << "\t    PASSWORD" << endl;
    cout << "\t ";
    cin >> password;
    ifstream singIn;
    singIn.open("login.txt");
    Clear;
    bool isTrueLogin = false;
    bool isTruePassword = false;
    while (!singIn.eof()) {
        isTrueLogin = false;
        isTruePassword = false;
        string l;
        string p;
        getline(singIn, l);
        getline(singIn, p);
        if (l == login) {
            isTrueLogin = true;
            if (p == password) {
                isTruePassword = true;
            }
            break;
        }
        if (isTruePassword == true && isTrueLogin == true) {
            SingIn = true;
        }
        showMenu();
    }
    singIn.close();
    if (SingIn == false) {
        ofstream SingAdd;
        SingAdd.open("login.txt", ofstream::app);
        SingAdd << endl;
        SingAdd << login << endl;
        SingAdd << password;
        SingAdd.close();
        string str2 = "login.txt";
        SingAdd.open(str2, ofstream::app);
        SingAdd.close();

    }if (isTrueLogin == true && isTruePassword == false) {
        system("mode con cols=30 lines=10");
        system("cls");
        SetColor(4, 0);
        cout << "You enter incorect password " << endl;
        Sleep(2000);
        SetColor(15, 0);
        Login();
    }
    else {
        showMenu();
    }

    Clear;
}



int main() {
    Login();

    return 0;
}
