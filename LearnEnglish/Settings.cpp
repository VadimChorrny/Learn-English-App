#include "Settings.h"
#include "Source.cpp"
#include <Windows.h>
#include "addQuest.h"
#include "addQuest.h"

void Setting()
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

        if (saveload == "add") {
            newQuest();
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
