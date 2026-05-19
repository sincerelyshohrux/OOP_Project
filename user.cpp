#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool isUsernameTaken(string username) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string saved;
        getline(ss, saved, ',');
        if (saved == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "\n=== REGISTER ===\n";
    cout << "Enter username: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Username already taken!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << "," << password << ",customer\n";
    file.close();
    cout << "Registration successful!\n";
}

User loginUser() {
    string username, password;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string u, p, r;
        getline(ss, u, ',');
        getline(ss, p, ',');
        getline(ss, r, ',');
        if (u == username && p == password) {
            cout << "Welcome, " << username << "!\n";
            return {username, password, r};
        }
    }
    cout << "Invalid username or password!\n";
    return {"", "", ""};
}
