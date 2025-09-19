#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temp {
    string username, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signup();
    void forget();
} obj;

int main() {
    char choices;

    cout << "\n1- Login";
    cout << "\n2- Signup";
    cout << "\n3- Forget Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice : ";
    cin >> choices;
    cin.ignore(); // clear newline from buffer (important for getline)

    switch (choices) {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signup();
            break;
        case '3':
            obj.forget();
            break;
        case '4':
            return 0;
        default:
            cout << "Invalid Selection..........!" << endl;
    }
}

// ================== SIGNUP ==================
void Temp::signup() {
    cout << "\nEnter your name: ";
    getline(cin, username);
    cout << "Enter your Email address: ";
    getline(cin, Email);
    cout << "Enter your password: ";
    getline(cin, password);

    file.open("logindata.txt", ios::out | ios::app);
    file << username << "*" << Email << "*" << password << endl;
    file.close();

    cout << "\nAccount created successfully!\n";
}

// ================== LOGIN ==================
void Temp::login() {
    cout << "------------ LOGIN --------------" << endl;
    cout << "Enter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);

    bool found = false;

    file.open("logindata.txt", ios::in);
    while (getline(file, username, '*')) {
        getline(file, Email, '*');
        getline(file, password);

        if (username == searchName) {
            if (password == searchPass) {
                cout << "\nAccount Login Is Successful!" << endl;
                cout << "User Name : " << username << endl;
                cout << "Email     : " << Email << endl;
                found = true;
                break;
            } else {
                cout << "\nPassword Is Incorrect!\n";
                found = true;
                break;
            }
        }
    }
    file.close();

    if (!found) {
        cout << "\nAccount Not Found!\n";
    }
}

// ================== FORGET PASSWORD ==================
void Temp::forget() {
    cout << "\nEnter your User Name : ";
    getline(cin, searchName);
    cout << "Enter your Email : ";
    getline(cin, searchEmail);

    bool found = false;

    file.open("logindata.txt", ios::in);
    while (getline(file, username, '*')) {
        getline(file, Email, '*');
        getline(file, password);

        if (username == searchName && Email == searchEmail) {
            cout << "\nAccount Found!" << endl;
            cout << "Your Password is : " << password << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "\nAccount Not Found!\n";
    }
}

