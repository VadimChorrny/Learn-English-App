#include "Login.h"
#include "Menu.h"
#include "Source.cpp"



void login()
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


                    menu();
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
        menu();
        file.close();
    }
}
