#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>

using namespace std;

bool CheckNumber(string temp) {
    for (int k = 0; k < temp.length(); k++) {
        if (isdigit(temp[k]) == false)
            return false;
        else
            return true;
    }
}

void GenereatePass(char password[], int length) {
    // list of possible characters for a password (i have to improve it ~_^ )
    string possible_chars = "]BbCnOIWG,A6cDda14StUuyZz!27YiJjxoP>?@\^pQqFKk8}~[fR90lMmN-./:gHh3#$%&'()*+;5EesTLwX<=_{|r";

    // generating a random number which will be used in order to take a random element from /|\ string
    //                                                                                       |
    random_device rd;
    cout << "Your password is -> ' ";
    for (int j = 0; j < length; j++) {
        mt19937 mersenne(rd());
        password[j] = possible_chars[mersenne() % 89];
        cout << "\033[0;32m";
        cout << password[j];
    }
    cout << "\033[0;37m";
    cout << " '\n\nFeel free to copy!\n\n";
}

int main()
{
    cout << "\033[0;37m";
    bool Continue = true;
    while (Continue) {
        // we gotta check if the password is at least 1 character long
        string temp = "";
        int length;
        while (true) {
            cout << "The length of password: "; cin >> temp;
            // checking if the input is a number
            if (CheckNumber(temp)) {
                length = stoi(temp);
            }
            else {
                cout << "\033[0;31m";
                cout << "The number is not recognised, try again.\n\n";
                cout << "\033[0;37m";
                continue;
            }

            if (length < 1) {
                cout << "The length of password must be at least 1 character long!\n\n";
                continue;
            }
            else
                break;
        }

        char* password = (char*)malloc(sizeof(char) * length);
        GenereatePass(password, length);

        free(password);

        // checking if we need a new password
        char answer = ' ';
        cout << "Do you want to create a new password?(Y/N)\n\n-> "; cin >> answer;
        if (answer == 'Y' or answer == 'y') {
            system("cls");
            Continue = true;
        }
        else {
            Continue = false;
        }

    }

    return 0;
}
