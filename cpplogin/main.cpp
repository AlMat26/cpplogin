#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string register_check = "0";

string login[1];
string password[1];
string user_name;
string name;

string encryptDecrypt(string toEncrypt) {
    char key[3] = {'K', 'C', 'Q'}; //Any chars will work, in an array of any size
    string output = toEncrypt;

    for (unsigned int i = 0; i < toEncrypt.size(); i++){
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    }

    return output;
}

int main()
{
    ofstream file;
    ifstream fin;
    string dataArray[3];

    system("color 70");
    cout << "Welcome to the simple login programm!" << endl;

    fin.open("userlogininfo.neet");

    getline(fin, dataArray[0]); //login
    getline(fin, dataArray[1]); //password
    getline(fin, dataArray[2]); //username
    getline(fin, register_check); //register check (not encrypted)

    login[0] = encryptDecrypt(dataArray[0]);
    password[0] = encryptDecrypt(dataArray[1]);
    user_name = encryptDecrypt(dataArray[2]);

    fin.close();

    if (register_check == "0")
    {
        file.open("userlogininfo.neet");
        cout << "Make a login:" << endl;
        cin >> login[0];
        cout << "Make a password:" << endl;
        cin >> password[0];
        cout << "Write your name:" << endl;
        cin >> user_name;
        cout << "Success! Save your login info." << endl;
        register_check = "1";

        file << encryptDecrypt(login[0]) << endl;
        file << encryptDecrypt(password[0]) << endl;
        file << encryptDecrypt(user_name) << endl;
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

        cout << "Succes login. \nWelcome, " << name << " " << "(" << login[0] << ")" << "!" << endl;

    }

    system("pause");
    return 0;
}
