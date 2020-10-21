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
#define Sleep Sleep(5000);

// Initialization of variables



string login;
string password;
bool SingIn = false;





void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void outputAllWords()
{

    string path = "myFile.txt";

    ifstream fin;
    fin.open(path);
    if (fin.is_open()) {
        cout << "File was open :)" << endl;
        char ch;
        while (fin.get(ch))
        {
            cout << ch;

        }
    }
    else {
        cout << "!!!Error!!!  File not open!" << endl;
    }
    fin.close();
    cout << endl;
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
        }
        }
    } while (true);
    

}

void Login() {
    system("mode con cols=25 lines=10");
    string password;
    cout << "\t  LOGIN" << endl;
    cout << "\t ";
    cin >> login;
    cout << "\t PASSWORD" << endl;
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