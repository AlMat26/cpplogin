#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string register_check = "0";

string login[1];
string password[1];
string user_name;
string name;

int main()
{
    ofstream file;
    ifstream fin;

    system("color 70");
    cout << "Welcome to the simple login programm!" << endl;

    fin.open("userlogininfo.txt");

    getline(fin, login[0]);
    getline(fin, password[0]);
    getline(fin, user_name);
    getline(fin, register_check);

    fin.close();

    if (register_check == "0")
    {
        file.open("userlogininfo.txt");
        cout << "Make a login:" << endl;
        cin >> login[0];
        file << login[0] << endl;
        cout << "Make a password:" << endl;
        cin >> password[0];
        file << password[0] << endl;
        cout << "Write your name:" << endl;
        cin >> user_name;
        file << user_name << endl;
        cout << "Success! Save your login info." << endl;
        register_check = "1";
        file << register_check << endl;
        system("pause");
        system("cls");
        file.close();
        return 1;
    }
    else if (register_check == "1")
    {
        name = user_name;

        do
        {
            cout << "Enter your login:" << endl;
            cin >> login[1];

            cout << "Enter your password:" << endl;
            cin >> password[1];
        } while (login[1] != login[0] && password[1] != password[0]);

        if (login[1] == login[0] && password[1] == password[0])
        {
            cout << "Succes login. \nWelcome, " << name << " " << "(" << login[0] << ")" << "!" << endl;
        }
    }

    system("pause");
    return 0;
}
