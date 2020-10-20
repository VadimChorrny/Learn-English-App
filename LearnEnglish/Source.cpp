#include "iostream"
#include "windows.h"
#include "string"
#include "fstream"
#include <time.h>
#include<ctime>
#include<conio.h>

using namespace std;

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

int main() {
    showMenu();
    
    return 0;
}