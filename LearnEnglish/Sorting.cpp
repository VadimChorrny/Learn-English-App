#include "Sorting.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


/// <summary>
/// sorting words | show position
/// </summary>
void sortingWord()
{
    ifstream file("myFile.txt"); 
    string s, find;
    char c;

    while (!file.eof()) {  
        file.get(c);
        s.push_back(c);
    }

    file.close(); 

    cout << "enter a word for find: ";
    cin >> find;

    int pos = s.find(find); 

    if (pos == -1)
        cout << "not finded" << endl;
    else
        cout << "finded in " << pos << " simvol position" << endl;
}


/// <summary>
/// delete word in file 
/// </summary>
void removeWord()
{
    int pos;
    string filename = "myFile.txt"; 
    cout << "Enter position for delete: ";
    cin >> pos;

    if (filename, pos)
    {
        cout << "OK!!!";
    }
    else
    {
        cout << "Error";
    }
}

