#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
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


	return 0;
}